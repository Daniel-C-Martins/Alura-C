#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "Forca.h"

// compilador C lê as funções em ordem, isso faz com quem ele entenda que aqueles métodos existem
// int enforcou();
// void iniciaPrograma();
// void chuta();
// int jachutou(char letra);
// int acertou();
// void desenhaforca();
// void escolhepalavra();

char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;

// Método que printa o menu
void iniciaPrograma()
{
  printf("========================== \n");
  printf("      Jogo de forca        \n");
  printf("========================== \n");
}

// Método pega o chute do usuário
void chuta()
{
  char chute;
  printf("Qual letra? ");
  scanf(" %c", &chute);

  chutes[chutesDados] = chute;
  chutesDados++;
}

// Método que ve se o usuario ja chutou um numero
int jachutou(char letra)
{
  int achou = 0;
  for (int j = 0; j < chutesDados; j++)
  {
    if (chutes[j] == letra)
    {
      achou = 1;
      break;
    }
  }
  return achou;
}

// Método que desenha a forca
void desenhaForca()
{
  int erros = chuteserrados();
  printf("  _______       \n");
  printf(" |/      |      \n");
  printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '),
         (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
  printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '),
         (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
  printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
  printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '),
         (erros >= 4 ? '\\' : ' '));
  printf(" |              \n");
  printf("_|___           \n");
  printf("\n\n");
  for (int i = 0; i < strlen(palavraSecreta); i++)
  {
    if (jachutou(palavraSecreta[i]))
    {
      printf("%c ", palavraSecreta[i]);
    }
    else
    {
      printf("_ ");
    }
  }
  printf("\n");
}

// Método que seleciona a palavra da forca
void escolhepalavra()
{
  FILE *f;

  f = fopen("BancoDeDados.txt", "r");
  if (f == NULL)
  {
    printf("Banco de dados de palavras nao disponivel\n\n");
    exit(1);
  }

  int qtddepalavras;
  fscanf(f, "%d", &qtddepalavras);

  srand(time(0));
  int randomico = rand() % qtddepalavras;

  for (int i = 0; i <= randomico; i++)
  {
    fscanf(f, "%s", palavraSecreta);
  }

  fclose(f);
}

void adicionapalavra()
{
  char quer;

  printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
  scanf(" %c", &quer);

  if (quer == 'S')
  {
    char novapalavra[TAMANHO_PALAVRA];

    printf("Digite a nova palavra, em letras maiúsculas: ");
    scanf("%s", novapalavra);

    FILE *f;

    f = fopen("BancoDeDados.txt", "r+");
    if (f == 0)
    {
      printf("Banco de dados de palavras não disponível\n\n");
      exit(1);
    }

    int qtd;
    fscanf(f, "%d", &qtd);
    qtd++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", qtd);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s", novapalavra);

    fclose(f);
  }
}

int chuteserrados()
{
  int erros = 0;

  for (int i = 0; i < chutesDados; i++)
  {

    int existe = 0;

    for (int j = 0; j < strlen(palavraSecreta); j++)
    {
      if (chutes[i] == palavraSecreta[j])
      {
        existe = 1;
        break;
      }
    }

    if (!existe)
      erros++;
  }

  return erros;
}

int enforcou()
{

  return chuteserrados() >= 5;
}

int acertou()
{
  for (int i = 0; i < strlen(palavraSecreta); i++)
  {
    if (!jachutou(palavraSecreta[i]))
    {
      return 0;
    }
  }

  return 1;
}

int main()
{
  iniciaPrograma();
  escolhepalavra();
  do
  {
    desenhaForca();
    chuta();
  } while (!acertou() && !enforcou());
  adicionapalavra();
}

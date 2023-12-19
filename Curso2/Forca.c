#include <stdio.h>
#include <string.h>

void iniciaPrograma()
{
  printf("========================== \n");
  printf("      Jogo de forca        \n");
  printf("========================== \n");
}

void imprimePalavraSecreta()
{
}

void chuta(int *tentativas, char chutes[26])
{
  char chute;
  printf("Qual letra? ");
  scanf(" %c", &chute);

  chutes[*tentativas] = chute;
  (*tentativas)++;
}

int main()
{
  char palavraSecreta[20];
  sprintf(palavraSecreta, "Melancia");

  int acertou = 0;
  int enforcou = 0;

  char chutes[26];
  int tentativas = 0;

  iniciaPrograma();

  do
  {
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {

      int achou = 0;

      for (int j = 0; j < tentativas; j++)
      {
        if (chutes[j] == palavraSecreta[i])
        {
          achou = 1;
          break;
        }
      }

      if (achou)
      {
        printf("%c ", palavraSecreta[i]);
      }
      else
      {
        printf("_ ");
      }
    }
    printf("\n");
    chuta(&tentativas, chutes);

  } while (!acertou && !enforcou);
}
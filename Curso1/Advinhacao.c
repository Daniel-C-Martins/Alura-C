#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  printf("          P  /_\\  P                               \n ");
  printf("         /_\\_|_|_/_\\                             \n ");
  printf("     n_n | ||. .|| | n_n         Bem vindo ao      \n ");
  printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!  \n ");
  printf("    |"
         "  |  |_|  |"
         " |                          \n ");
  printf("    |_____| ' _ ' |_____|                          \n ");
  printf("          \\__|_|__/                               \n ");
  printf("\n \n");

  // Variaveis numero Secreto
  int segundos = time(0);
  srand(segundos); // Cria uma função matematica nova para Rand() usando o tempo em segundos do mundo
  int random = rand();
  int numSecreto = random % 100;

  // Variaveis do jogo
  int chute = 0;
  int quantTentativas = 0;
  int numeroTentativas = 0;
  int acertou = 0;

  // Varivel de pontuacao
  double pontos = 1000;

  // variavel de dificuldade
  int nivel = 0;
  printf("Qual o nivel de dificuldade voce deseja jogar? \n ");
  printf("(1) Facil, (2) Medio, (3) Dificil \n");
  printf("Escolha: ");
  scanf("%d", &nivel);

  switch (nivel)
  {
  case 1:
    numeroTentativas = 20;
    break;
  case 2:
    numeroTentativas = 20;
    break;
  case 3:
    numeroTentativas = 5;
    break;
  default:
    printf("Alternativa de nivel nao foi escolhida da forma correta \n");
    printf("Nivel medio selecionado automaticamente \n");
    printf("-----------------------------------------------------");
    numeroTentativas = 10;
    break;
  }

  for (int i = 0; i < numeroTentativas; i++)
  {
    quantTentativas++;
    printf("Tentativa %d \n", quantTentativas);
    printf("Digite o numero do seu chute ");
    scanf("%d", &chute);

    if (chute < 0)
    {
      printf("Voce nao pode chutar um numero negativo \n");
      printf("-----------------------------------------------------");
      quantTentativas--;
      continue;
    }
    printf("Seu chute foi: %d \n", chute);

    acertou = (numSecreto == chute);
    int maior = chute > numSecreto;

    if (acertou)
    {
      break;
    }
    else if (maior)
    {
      printf("O numero digitado e maior que o numero secreto \n");
      printf("-----------------------------------------------------");
    }
    else
    {
      printf("O numero digitado e menor que o numero secreto\n");
      printf("-----------------------------------------------------");
    }
    double pontosPerdidos = (double)abs(chute - numSecreto) / (double)2;
    pontos -= pontosPerdidos;
  }

  if (acertou)
  {
    printf("             OOOOOOOOOOO               \n");
    printf("         OOOOOOOOOOOOOOOOOOO           \n");
    printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
    printf("    OOOOOO      OOOOO      OOOOOO      \n");
    printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
    printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
    printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
    printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
    printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
    printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
    printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
    printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
    printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
    printf("         OOOOOO         OOOOOO         \n");
    printf("             OOOOOOOOOOOO              \n");
    printf("\n\n");
    printf("Voce acerto o numero secreto: %d em %d tentativas \n", numSecreto, quantTentativas);
    printf("Sua pontuacao foi: %.2f \n", pontos);
  }
  else
  {
    printf("Voce perdeu tente novamente \n");
    printf("o numero secreto era: %d \n", numSecreto);
    printf("       \\|/ ____ \\|/    \n");
    printf("        @~/ ,. \\~@      \n");
    printf("       /_( \\__/ )_\\    \n");
    printf("          \\__U_/        \n");
  }
  printf("Fim do jogo");
}

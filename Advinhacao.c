#include <stdio.h>

#define NUMERO_TENTATIVAS 5

int main()
{
  printf("-------------------------------------- \n");
  printf("Bem vindo ao nosso jogo de adivinhacoo \n");
  printf("-------------------------------------- \n");

  int numSecreto = 10;

  int chute = 0;
  int quantTentativas = 0;

  // for (int i = 0; i < NUMERO_TENTATIVAS; i++)
  while (1)
  {
    quantTentativas++;
    printf("Tentativa %d \n", quantTentativas);
    printf("Digite o numero do seu chute ");
    scanf("%d", &chute);

    if (chute < 0)
    {
      printf("Voce nao pode chutar um numero negativo \n");
      quantTentativas--;
      continue;
    }

    printf("Seu chute foi: %d \n", chute);

    int acertou = numSecreto == chute;
    int maior = chute > numSecreto;

    if (acertou)
    {
      printf("Voce acerto o numero secreto: %d em %d tentativas \n", numSecreto, quantTentativas);
      break;
    }
    else if (maior)
    {
      printf("O numero digitado e maior que o numero secreto \n");
    }
    else
    {
      printf("O numero digitado e menor que o numero secreto\n");
    }
  }
  printf("Fim do jogo");
}
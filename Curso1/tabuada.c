#include <stdio.h>

int main()
{
  int numero = 0;
  printf("Digite o numero que voce deseja saber a tabuada ");
  scanf("%d", &numero);

  for (int i = 1; i <= 10; i++)
  {
    printf("%d vezes %d = %d \n", i, numero, i * numero);
  }
}
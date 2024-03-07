#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int x = 0;
  int y = 0;
  int multi = 0;
  //int random = rand();
  int segundos = time(0);
  srand(segundos);
  printf("Digite um valor para a variavel y \n");
  scanf("%d", &y);
  printf("Agora digite um valor para a variavel x \n");
  scanf("%d", &x);
  multi = x * y;
  printf("O resultado da multiplicacao entre x E y é : %i", multi);
}
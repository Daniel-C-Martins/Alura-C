#include <stdio.h>

void ponteiro(int *num) // int* estou passando o endereço para a função
{
  (*num)++; // estou pegando o valor desse endereço e somando
  printf("Ponteiro: %d %d \n", (*num), num);
}

int main()
{
  int numero = 10;

  printf("Main: %d %d \n", numero, &numero); // &numero acessa o endereço de memoria da variavel
  numero++;
  printf("Main: %d %d \n", numero, &numero);
  ponteiro(&numero);
  printf("Main: %d %d \n", numero, &numero);
}
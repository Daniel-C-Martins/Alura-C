#include <stdio.h>

int soma(int* lista, int tamanhoLista)
{
  int soma = 0;
  for (int i = 0; i < tamanhoLista; i++){
    soma += lista[i];
  }
  return soma;
}

int main()
{
  int numeros[10] = {10, 8, 6, 23, 4, 5, 6, 1, 3, 9};
  int somaLista = soma(numeros, 10);
  printf("A soma da lista é: %d", somaLista);
}

// int soma(int *nums, int tam)
// {
//   int total = 0;

//   for (int i = 0; i < tam; i++)
//   {
//     total += nums[i];
//   }

//   return total;
// }
// int main()
// {
//   int nums[3];
//   nums[0] = 10;
//   nums[1] = 20;
//   nums[2] = 30;

//   int total = soma(nums, 3);
//   printf("%d", total);
// }
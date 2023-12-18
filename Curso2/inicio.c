#include <stdio.h>

int main()
{
  // Declaração de char
  /*char letra1 = 'a';
   char letra2 = 'l';
   char letra3 = 'o';
   printf("%c %c %c \n", letra1, letra2, letra3);
  */

  // Array inteiros
  /* int notas[10];
  notas[0] = 10;
  notas[1] = 9;
  printf(" notas %d %d \n", notas[0], notas[1]);*/

  // Strings(char[])
  char palavra[20];
  /*
    palavra[0] = 'a';
    palavra[1] = 'l';
    palavra[2] = 'o';
    palavra[3] = 'm';
    palavra[4] = 'u';
    palavra[5] = 'n';
    palavra[6] = 'd';
    palavra[7] = 'o';
    palavra[8] = '\0';
    printf("%c %c %c %c %c %c %c %c", palavra[0], palavra[1], palavra[2], palavra[3], palavra[4], palavra[5], palavra[6], palavra[7]);
  */
  sprintf(palavra, "alo mundo"); // guarda no array palavra o "alo mundo"
  printf("%s", palavra);
}
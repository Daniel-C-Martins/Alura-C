#include <stdio.h>
#include <string.h>

int main()
{
  char palavraSecreta[20];
  sprintf(palavraSecreta, "Melancia");

  int acertou = 0;
  int enforcou = 0;

  do
  {
    char chute ="";
    printf("Digite seu chute: ");
    scanf("%c", &chute);
    for(int i = 0; i < strlen(palavraSecreta); i++){
      if(palavraSecreta[i] == chute){
        printf("A posicao %d tem essa letra! \n", i);
      }
    }
  } while (!acertou && !enforcou);
}
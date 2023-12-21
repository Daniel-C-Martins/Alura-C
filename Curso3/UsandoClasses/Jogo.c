#include <stdio.h>
#include <stdlib.h>
#include "Mapa.h"
#include "Jogo.h"

MAPA m;

int acabou()
{
  return 0;
}

void move(char direcao)
{
  int x;
  int y;

  // Posição do pacman
  for (int i = 0; i < m.linhas; i++)
  {
    for (int j = 0; j < m.colunas; j++)
    {
      if (m.matriz[i][j] == '@')
      {
        x = i;
        y = j;
      }
    }
  }

  switch (direcao)
  {
  case 'a':
    m.matriz[x][y - 1] = '@';
    break;
  case 'w':
    m.matriz[x - 1][y] = '@';
    break;
  case 's':
    m.matriz[x + 1][y] = '@';
    break;
  case 'd':
    m.matriz[x][y + 1] = '@';
    break;
  }
  m.matriz[x][y] = '.';
}

int main()
{
  leMapa(&m);

  do
  {
    imprimeMapa(&m);
    char comando;
    scanf(" %c", &comando);
    move(comando);
  } while (!acabou());

  liberaMapa(&m);
}
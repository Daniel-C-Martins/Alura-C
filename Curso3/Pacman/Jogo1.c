#include <stdio.h>
#include <stdlib.h>
#include "Jogo1.h"

MAPA m;

void liberaMapa()
{
  for (int i = 0; i < m.linhas; i++)
  {
    free(m.matriz[i]);
  }
  free(m.matriz);
}

void alocaMapa()
{
  /////// Alocação de memória dinâmica
  m.matriz = malloc(sizeof(char *) * m.linhas);
  for (int i = 0; i < m.linhas; i++)
  {
    m.matriz[i] = malloc(sizeof(char) *  m.colunas + 1);
  }
}

void leMapa()
{
  FILE *f;
  f = fopen("Mapa.txt", "r");
  fscanf(f, "%d %d", &m.linhas, &m.colunas);
  if (f == NULL)
  {
    printf("Mapa está vazio");
    exit(1);
  }

  alocaMapa();

  for (int i = 0; i < m.colunas; i++)
  {
    fscanf(f, "%s", m.matriz[i]);
  }

  fclose(f);
}

void imprimeMapa()
{
  for (int i = 0; i < m.linhas; i++)
  {
    printf("%s \n", m.matriz[i]);
  }
}


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
  leMapa();

  do
  {
    imprimeMapa();
    char comando;
    scanf(" %c", &comando);
    move(comando);
  } while (!acabou());

  liberaMapa();
}

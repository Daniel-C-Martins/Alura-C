#include <stdio.h>
#include <stdlib.h>
#include "Jogo1.h"
#include <string.h>

MAPA m;
POSICAO heroi;

//
//  Métodos para a criação do mapa
//
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
    m.matriz[i] = malloc(sizeof(char) * m.colunas + 1);
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

void encontraMapa()
{
  // Posição do pacman
  for (int i = 0; i < m.linhas; i++)
  {
    for (int j = 0; j < m.colunas; j++)
    {
      if (m.matriz[i][j] == '@')
      {
        heroi.x = i;
        heroi.y = j;
      }
    }
  }
}

void copiamapa(MAPA *destino, MAPA *origem)
{
  destino->linhas = origem->linhas;
  destino->colunas = origem->colunas;
  alocaMapa(destino);
  for (int i = 0; i < origem->linhas; i++)
  {
    strcpy(destino->matriz[i], origem->matriz[i]);
  }
}

int acabou()
{
  return 0;
}

//
//  Métodos da movimentação do personagem
//
void fantasma()
{
  MAPA copia;

  copiamapa(&copia, &m);

  for (int i = 0; i < copia.linhas; i++)
  {
    for (int j = 0; j < copia.colunas; j++)
    {
      if (copia.matriz[i][j] == FANTASMA)
      {
        if (ehValida(i, j + 1) && ehVazia(i, j + 1))
        {
          andaNoMapa(i, j + 1);
        }
      }
    }
  }

  liberaMapa(&copia);
}

int ehDirecao(char direcao)
{
  if (direcao == ESQUERDA || direcao == BAIXO || direcao == DIREITA || direcao == CIMA)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int ehValida(int proximox, int proximoy)
{
  if (proximox >= m.linhas)
    return 0;
  if (proximoy >= m.colunas)
    return 0;

  return 1;
}

int ehVazia(int proximox, int proximoy)
{
  if (m.matriz[proximox][proximoy] == VAZIO)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void andaNoMapa(int proximox, int proximoy)
{
  char personagem = m.matriz[heroi.x][heroi.y];
  m.matriz[proximox][proximoy] = personagem;
  m.matriz[heroi.x][heroi.y] = VAZIO;
  heroi.x = proximox;
  heroi.y = proximoy;
}

void move(char direcao)
{

  if (!ehDirecao(direcao))
  {
    return;
  }

  int proximox = heroi.x;
  int proximoy = heroi.y;

  switch (direcao)
  {
  case ESQUERDA:
    proximoy--;
    break;
  case CIMA:
    proximox--;
    break;
  case BAIXO:
    proximox++;
    break;
  case DIREITA:
    proximoy++;
    break;
  }

  if (!ehValida(proximox, proximoy))
  {
    return;
  }

  if (!ehVazia(proximox, proximoy))
  {
    return;
  }
  andaNoMapa(proximox, proximoy);
}

int main()
{
  leMapa();
  encontraMapa();
  do
  {
    imprimeMapa();
    char comando;
    scanf(" %c", &comando);
    move(comando);
    fantasma();
  } while (!acabou());

  liberaMapa();
}

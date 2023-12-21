#include "Mapa.h"
#include <stdlib.h>
#include <stdio.h>

void liberaMapa(MAPA *m)
{
  for (int i = 0; i < m->linhas; i++)
  {
    free(m->matriz[i]);
  }
  free(m->matriz);
}

void alocaMapa(MAPA *m)
{
  /////// Alocação de memória dinâmica
  m->matriz = malloc(sizeof(char *) * m->linhas);
  for (int i = 0; i < m->linhas; i++)
  {
    m->matriz[i] = malloc(sizeof(char) *  m->colunas + 1);
  }
}

void leMapa(MAPA *m)
{
  FILE *f;
  f = fopen("Mapa.txt", "r");
  fscanf(f, "%d %d", &m->linhas, &m->colunas);
  if (f == NULL)
  {
    printf("Mapa está vazio");
    exit(1);
  }

  alocamatriz(m);

  for (int i = 0; i < m->colunas; i++)
  {
    fscanf(f, "%s", m->matriz[i]);
  }

  fclose(f);
}

void imprimeMapa(MAPA *m)
{
  for (int i = 0; i < m->linhas; i++)
  {
    printf("%s \n", m->matriz[i]);
  }
}

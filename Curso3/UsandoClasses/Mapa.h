struct mapa
{
  char **matriz; // 5 Linhas, 10 colunas
  int linhas;
  int colunas;
};

typedef struct mapa MAPA;

void liberaMapa(MAPA *m);
void leMapa(MAPA *m);
void alocaMapa(MAPA *m);
void imprimeMapa(MAPA *m);

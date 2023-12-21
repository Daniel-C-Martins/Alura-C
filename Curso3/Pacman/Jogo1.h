struct mapa
{
  char **matriz; // 5 Linhas, 10 colunas
  int linhas;
  int colunas;
};

typedef struct mapa MAPA;

void liberaMapa();
void leMapa();
void alocaMapa();
void imprimeMapa();
int acabou();
void move(char direcao);


#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

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
void encontraMapa();
int ehDirecao(char direcao);
int ehValida(int proximox, int proximoy);
int ehVazia(int proximox, int proximoy);
void andaNoMapa(int proximox, int proximoy  );
struct posicao
{
  int x;
  int y;
};

typedef struct posicao POSICAO;




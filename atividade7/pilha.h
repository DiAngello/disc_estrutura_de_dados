#define TAMANHO_MAX 100

typedef struct {
    char url[100];
} PaginaWeb;

typedef struct {
    PaginaWeb paginas[TAMANHO_MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *pilha);
int pilhaEstaVazia(Pilha *pilha);
int pilhaEstaCheia(Pilha *pilha);
void empilharPagina(Pilha *pilha, PaginaWeb pagina);
PaginaWeb desempilharPagina(Pilha *pilha);


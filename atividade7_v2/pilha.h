typedef struct PilhaNode {
    int carta;
    struct PilhaNode* proximo;
} PilhaNode;

typedef struct {
    PilhaNode* topo;
} Pilha;

void inicializarPilha(Pilha* pilha);
int tamanhoPilha(Pilha* pilha);
void empilhar(Pilha* pilha, int carta);
int desempilhar(Pilha* pilha);


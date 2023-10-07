typedef struct Node {
    int jogador;
    struct Node* proximo;
} Node;

typedef struct {
    Node* frente;
    Node* tras;
} Fila;

void inicializarFila(Fila* fila);
int tamanhoFila(Fila* fila);
void enfileirar(Fila* fila, int jogador);
int desenfileirar(Fila* fila);


#define TAMANHO_MAX 100

typedef struct {
    char nomeDocumento[100];
} Documento;

typedef struct {
    Documento documentos[TAMANHO_MAX];
    int frente;
    int fundo;
} Fila;

void inicializarFila(Fila *fila);
int filaEstaVazia(Fila *fila);
int filaEstaCheia(Fila *fila);
void enfileirarDocumento(Fila *fila, Documento documento);
Documento desenfileirarDocumento(Fila *fila);

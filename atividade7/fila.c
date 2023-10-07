#include "fila.h"
#include <string.h>

void inicializarFila(Fila *fila) {
    fila->frente = -1;
    fila->fundo = -1;
}

int filaEstaVazia(Fila *fila) {
    return fila->frente == -1;
}

int filaEstaCheia(Fila *fila) {
    return (fila->fundo + 1) % TAMANHO_MAX == fila->frente;
}

void enfileirarDocumento(Fila *fila, Documento documento) {
    if (!filaEstaCheia(fila)) {
        if (filaEstaVazia(fila)) {
            fila->frente = 0;
        }
        fila->fundo = (fila->fundo + 1) % TAMANHO_MAX;
        fila->documentos[fila->fundo] = documento;
    }
}

Documento desenfileirarDocumento(Fila *fila) {
    Documento documentoVazio;
    strcpy(documentoVazio.nomeDocumento, "");

    if (!filaEstaVazia(fila)) {
        Documento documento = fila->documentos[fila->frente];
        if (fila->frente == fila->fundo) {
            fila->frente = fila->fundo = -1;
        } else {
            fila->frente = (fila->frente + 1) % TAMANHO_MAX;
        }
        return documento;
    }

    return documentoVazio; // Fila vazia
}

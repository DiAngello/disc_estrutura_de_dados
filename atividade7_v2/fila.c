#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializarFila(Fila* fila) {
    fila->frente = NULL;
    fila->tras = NULL;
}

int tamanhoFila(Fila* fila) {
    int tamanho = 0;
    Node* atual = fila->frente;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

void enfileirar(Fila* fila, int jogador) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        fprintf(stderr, "Erro: Não foi possível alocar memória para novoNode\n");
        exit(1);
    }
    novoNode->jogador = jogador;
    novoNode->proximo = NULL;

    if (fila->tras == NULL) {
        fila->frente = novoNode;
        fila->tras = novoNode;
    } else {
        fila->tras->proximo = novoNode;
        fila->tras = novoNode;
    }
}

int desenfileirar(Fila* fila) {
    if (fila->frente == NULL) {
        fprintf(stderr, "Erro: Tentativa de desenfileirar de uma fila vazia\n");
        exit(1);
    }

    int jogador = fila->frente->jogador;
    Node* temp = fila->frente;
    fila->frente = fila->frente->proximo;
    free(temp);

    if (fila->frente == NULL) {
        fila->tras = NULL;
    }

    return jogador;
}

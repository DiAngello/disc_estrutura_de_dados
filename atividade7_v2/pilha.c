#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

int tamanhoPilha(Pilha* pilha) {
    int tamanho = 0;
    PilhaNode* atual = pilha->topo;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

void empilhar(Pilha* pilha, int carta) {
    PilhaNode* novoNode = (PilhaNode*)malloc(sizeof(PilhaNode));
    if (novoNode == NULL) {
        fprintf(stderr, "Erro: Não foi possível alocar memória para novoNode\n");
        exit(1);
    }
    novoNode->carta = carta;
    novoNode->proximo = pilha->topo;
    pilha->topo = novoNode;
}

int desempilhar(Pilha* pilha) {
    if (pilha->topo == NULL) {
        fprintf(stderr, "Erro: Tentativa de desempilhar de uma pilha vazia\n");
        exit(1);
    }

    int carta = pilha->topo->carta;
    PilhaNode* temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(temp);

    return carta;
}

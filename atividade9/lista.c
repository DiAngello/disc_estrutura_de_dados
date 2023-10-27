//
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(float valor, No* proximo_no) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no != NULL) {
        novo_no->valor = valor;
        novo_no->proximo_no = proximo_no;
    }
    return novo_no;
}

void lista_inserir_no(No* L, float valor) {
    while (L->proximo_no != NULL) {
        L = L->proximo_no;
    }
    L->proximo_no = no(valor, NULL);
}

void lista_inserir_no_ordenado(No** L, float valor) {
    No* novo_no = no(valor, NULL);
    if (novo_no == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    
    if (*L == NULL || (*L)->valor >= valor) {
        novo_no->proximo_no = *L;
        *L = novo_no;
    } else {
        No* atual = *L;
        while (atual->proximo_no != NULL && atual->proximo_no->valor < valor) {
            atual = atual->proximo_no;
        }
        novo_no->proximo_no = atual->proximo_no;
        atual->proximo_no = novo_no;
    }
}

void lista_imprimir(No* L) {
    while (L != NULL) {
        printf("%.2f -> ", L->valor);
        L = L->proximo_no;
    }
    printf("NULL\n");
}

void lista_liberar(No* L) {
    while (L != NULL) {
        No* proximo = L->proximo_no;
        free(L);
        L = proximo;
    }
}

#include "pilha.h"
#include <string.h>

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilhaEstaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int pilhaEstaCheia(Pilha *pilha) {
    return pilha->topo == TAMANHO_MAX - 1;
}

void empilharPagina(Pilha *pilha, PaginaWeb pagina) {
    if (!pilhaEstaCheia(pilha)) {
        pilha->paginas[++pilha->topo] = pagina;
    }
}

PaginaWeb desempilharPagina(Pilha *pilha) {
    PaginaWeb paginaVazia;
    strcpy(paginaVazia.url, "");

    if (!pilhaEstaVazia(pilha)) {
        return pilha->paginas[pilha->topo--];
    }

    return paginaVazia; 
}

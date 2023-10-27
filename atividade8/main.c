#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]) {
    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));  
    No* n3 = no('U', NULL);

    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);

    lista_imprimir(n0);
    printf("\nQuantidade de nos: %d\n", lista_quantidade_nos(n0));

    char valor_busca = 'B';
    int existe = lista_verificar_existencia(n0, valor_busca);
    printf("Valor '%c' existe na lista? %s\n", valor_busca, (existe == 1) ? "1" : "0");

    int ocorrencias = lista_verificar_ocorrencias(n0, valor_busca);
    printf("Ocorrencias de '%c' na lista: %d\n", valor_busca, ocorrencias);

    printf("Lista inversa: ");
    lista_imprimir_inversa(n0);
    printf("\n");

    lista_inserir_no_i(n0, 2);
    printf("Lista apos a insercao na posicao 2: ");
    lista_imprimir(n0);
    printf("\n");

    lista_remover_no_i(n0, 1);
    printf("Lista apos a remocao da posicao 1: ");
    lista_imprimir(n0);
    printf("\n");

    char valor_remover = 'X';
    lista_remover_no(n0, valor_remover);
    printf("Lista apos a remocao de '%c': ");
    lista_imprimir(n0);
    printf("\n");

    lista_liberar(n0);
    n0 = NULL;

    lista_imprimir(n0);

    return 0;
}


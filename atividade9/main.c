//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "lista.h"

LARGE_INTEGER frequency;

void iniciar_tempo() {
    QueryPerformanceFrequency(&frequency);
}

double medir_tempo() {
    LARGE_INTEGER start;
    QueryPerformanceCounter(&start);
    return (double)start.QuadPart / (double)frequency.QuadPart;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo.csv\n", argv[0]);
        return 1;
    }

    FILE* arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    No* lista_nao_ordenada = no(0.0, NULL);
    No* lista_ordenada = NULL;  

    char linha[20]; 

    double tempo_insercao_nao_ordenada = 0.0;
    double tempo_insercao_ordenada = 0.0;
    int num_elementos = 0;

    iniciar_tempo();

    while (fgets(linha, sizeof(linha), arquivo)) {
        float numero = strtof(linha, NULL);

        double inicio = medir_tempo();
        lista_inserir_no(lista_nao_ordenada, numero);
        double fim = medir_tempo();
        tempo_insercao_nao_ordenada += (fim - inicio);

        inicio = medir_tempo();
        lista_inserir_no_ordenado(&lista_ordenada, numero);
        fim = medir_tempo();
        tempo_insercao_ordenada += (fim - inicio);

        num_elementos++;
    }

    fclose(arquivo);

    if (num_elementos > 0) {
        printf("Tempo medio de insercao na lista nao ordenada: %f segundos\n", tempo_insercao_nao_ordenada / num_elementos);
        printf("Tempo medio de insercao na lista ordenada: %f segundos\n", tempo_insercao_ordenada / num_elementos);
    } else {
        printf("Nenhum elemento inserido.\n");
    }

    //printf("Lista Nao Ordenada: ");
    //lista_imprimir(lista_nao_ordenada->proximo_no);  

    //printf("Lista Ordenada: ");
    //lista_imprimir(lista_ordenada);

    lista_liberar(lista_nao_ordenada->proximo_no);
    lista_liberar(lista_ordenada);

    return 0;
}

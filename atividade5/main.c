#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = "arq_palavras_ordenado.txt"; 

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    int num = 0;
    char palavra[100]; 

    while (fscanf(inputFile, "%s", palavra) != EOF) {
        num++;
    }

    rewind(inputFile);

    char **palavras = (char **)malloc(num * sizeof(char *));
    for (int i = 0; i < num; i++) {
        palavras[i] = (char *)malloc(100 * sizeof(char));
        fscanf(inputFile, "%s", palavras[i]);
    }

    bubbleSort(palavras, num);

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < num; i++) {
        fprintf(outputFile, "%s\n", palavras[i]);
    }

    fclose(inputFile);
    fclose(outputFile);

    for (int i = 0; i < num; i++) {
        free(palavras[i]);
    }
    free(palavras);

    printf("As palavras foram ordenadas com sucesso e salvas em \"%s\".\n", outputFileName);

    return 0;
}
//Exercício 3 - Verificar se um elemento existe no array. Escreva uma função que recebe um array de strings e uma string de busca, e retorna "1" se a string de busca existe no array, ou "0" caso não exista.//
#include <stdio.h>
#include <string.h>

int searchInArray(const char *array[], int arraySize, const char *searchString) {
    for (int i = 0; i < arraySize; i++) {
        if (strcmp(array[i], searchString) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    const char *words[] = {"texto", "J", "EDA"};
    int arraySize = sizeof(words) / sizeof(words[0]);
    
    const char *searchWord = "EDO";
    if (searchInArray(words, arraySize, searchWord)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    
    searchWord = "texto";
    if (searchInArray(words, arraySize, searchWord)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    
    return 0;
}
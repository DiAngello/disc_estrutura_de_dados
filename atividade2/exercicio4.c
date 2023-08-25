//Exercício 4 - Contar a quantidade de ocorrências de um elemento no array. Escreva uma função que recebe um array de números inteiros e um número inteiro de busca, e retorna a quantidade de vezes que o número de busca aparece no array.//
#include <stdio.h>

int count(const int array[], int arraySize, int busca) {
    int count = 0;
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == busca) {
            count++;
        }
    }
    return count;
}

int main() {
    int array[] = {5, 7, 9, 6, 7, 11, 6, 5};
    int arraySize = sizeof(array) / sizeof(array[0]);
    int length = sizeof(array)/sizeof(array[0]);    
    
    printf("Vetor: ");
    for (int i = 0; i < length; i++) {     
        printf("%d ", array[i]);     
    }      
    printf("\n"); 
    int busca;
    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &busca);
    int occurrences = count(array, arraySize, busca);
    
    printf("O numero %d aparece %d vezes no array.\n", busca, occurrences);
    
    return 0;
}

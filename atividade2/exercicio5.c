//Exercício 5 - Multiplicar elementos de dois arrays. Escreva uma função que recebe dois arrays de números inteiros com o mesmo tamanho e retorna um novo array com os elementos resultantes da multiplicação dos elementos dos dois arrays.//
#include <stdio.h>
#include <stdlib.h>

int* multiplyArrays(const int array1[], const int array2[], int arraySize) {
    int *resultArray = (int*)malloc(arraySize * sizeof(int));
    for (int i = 0; i < arraySize; i++) {
        resultArray[i] = array1[i] * array2[i];
    }
    
    return resultArray;
}

int main() {
    int array1[] = {5, 7, 9, 6};
    int array2[] = {6, 3, 9,8};
    int arraySize = sizeof(array1) / sizeof(array1[0]);
    
    int *resultArray = multiplyArrays(array1, array2, arraySize);

    int length1 = sizeof(array1)/sizeof(array1[0]);    
    int length2 = sizeof(array2)/sizeof(array2[0]);   
    printf("Vetor1: ");
    for (int i = 0; i < length1; i++) {     
        printf("%d ", array1[i]);    
    }          
    printf("\n"); 
    printf("Vetor2: ");
    for (int i = 0; i < length2; i++) {     
        printf("%d ", array2[i]);    
    }      
    printf("\n"); 
    
    printf("Resultado da multiplicacao dos arrays:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", resultArray[i]);
    }
    printf("\n");
    
    return 0;
}

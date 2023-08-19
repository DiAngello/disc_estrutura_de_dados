//Exercício 2 - Maior e menor elemento do array. Escreva uma função que recebe um array de números inteiros e retorna o menor e o maior elemento do array.//
#include <stdio.h>
#include <stdlib.h>

void maiorMenor(int *array, int tam, int *menor, int *maior){
    int i;

    *menor = *array;
    *maior = *array;
    
    for (i = 1; i < tam; i++){ 
        if(*menor > *(array + i)){
            *menor = *(array + i);
        }
        if(*maior < *(array + i)){
            *maior = *(array + i);
        }
    } 
}

int main (){
    int menor, maior, array[4] = {4, 2, 9, 5};
    int length = sizeof(array)/sizeof(array[0]);    
    
    printf("Vetor: ");
    for (int i = 0; i < length; i++) {     
        printf("%d ", array[i]);     
    }      
    maiorMenor(array, 4, &menor, &maior); 
    printf("Menor valor: %d Maior valor: %d\n", menor, maior); 
}

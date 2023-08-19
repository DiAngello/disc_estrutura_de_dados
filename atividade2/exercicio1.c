//Exercício 1 - Soma dos elementos de um array. Escreva uma função que recebe um array de números inteiros e retorna a soma de todos os elementos;//

#include <stdio.h>
#include <stdlib.h>

void soma( int array[4]){
    int total = 0; 
    
    for (int i = 0; i < 4; i++){ 
        total += array[i];
    } 
    printf("Soma dos valores: %d\n", total); 
}

int main (){
    int array[4] = {4, 2, 9, 5};
    int length = sizeof(array)/sizeof(array[0]);    
    
    printf("Vetor: ");
    for (int i = 0; i < length; i++) {     
        printf("%d ", array[i]);     
    }      
    soma(array); 
}

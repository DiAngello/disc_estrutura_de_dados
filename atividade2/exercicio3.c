//Exercício 3 - Verificar se um elemento existe no array. Escreva uma função que recebe um array de strings e uma string de busca, e retorna "1" se a string de busca existe no array, ou "0" caso não exista.//
#include <stdio.h>
#include <stdlib.h>

void busca_string[char *array[3], char busca]{
    for (int i = 0; i < array.length; i++) {
        if (busca.equals(array[i])) {
            printf("1");
        }else
            printf("0");
        break; 
    }
}

int main (){
    char *array[3] = {"texto", "J", "EDA"};
    char busca;
    int length = sizeof(array)/sizeof(array[0]);    

    printf("Digite o numero inteiro que deseja buscar: ");
    scanf("%c", &busca);
    
    printf("Vetor: ");
    for (int i = 0; i < length; i++) {     
        printf("%d ", array[i]);     
    }

    busca_string(array, &busca);
    return 0;
}      
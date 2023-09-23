#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void imprimir_arr(int *arr, int n){
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("\t%d", arr[i]);
    }
    printf("\n");
};

int main (int argc, char *argv[]){
    if (argc < 2) {
        printf("Uso: %s <numeros separados por espaços>\n", argv[0]);
        return 1;
    }
    int n = argc - 1;
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    bubble_sort(arr, n);
    imprimir_arr(arr, n);

    exit(0);

}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int n, i, resultado = 0;

    n = atoi(argv[1]);

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            resultado++;
            break;
    }
    }
    if (resultado == 0)
        printf("1\n", n);
    else
        printf("0", n);
 
 return 0;
}

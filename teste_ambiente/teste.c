#include <stdio.h>

double calcular_dobro(double n){
    return n*2;
}

int main(int argc, char * argv()){
    int n = -11;
    float n2 = 0;
    double d1 = 1.99999;
    char letra = 'j';

    if(n2){
        printf("0 eh verdadeiro");
    }

    if(n){
        printf("-11 eh verdadeiro");
    }
    
    for(n = 0; n < 10; n++){
        printf("%d", n);
    }

    n = 0;
    
    do{
        printf("%d", n);
        n++;
    } while (n < 10);

    printf("% O dobro de %f eh %f", d1, calcular_dobro(d1));

    return 0;
}

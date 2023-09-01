#include <stdio.h>
#include <stdlib.h>

typedef struct P{
    int x;
    int y;
} P;

int main (int argc, char* argv[]){
    P ponto;
    ponto.x=1;
    ponto.y=2;

    printf("%d, %d\n", ponto.x, ponto.y);

    int qtd_pontos = atoi(argv[1]);
    P* pontos = malloc(sizeof(ponto)*qtd_pontos);
    for(int i = 0; i < qtd_pontos; i++){
        fflush(stdin);
        scanf("%d", &pontos[i].x);
        fflush(stdin);
        scanf("%d", &pontos[i].y);
    }
    for(int i = 0; i < qtd_pontos; i++){
        printf("(%d,%d)\n", pontos[i].x, pontos[i].y);}
    return 0;
}
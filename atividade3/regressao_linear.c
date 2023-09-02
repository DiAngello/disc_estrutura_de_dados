#include <stdio.h>
#include <stdlib.h>

struct Ponto {
    double x;
    double y;
};

void regressaoLinear(struct Ponto *pontos, int n) {
    double somaX = 0.0, somaY = 0.0, somaXY = 0.0, somaXQuadrado = 0.0;

    for (int i = 0; i < n; i++) {
        somaX += pontos[i].x;
        somaY += pontos[i].y;
        somaXY += pontos[i].x * pontos[i].y;
        somaXQuadrado += pontos[i].x * pontos[i].x;
    }

    double a = (n * somaXY - somaX * somaY) / (n * somaXQuadrado - somaX * somaX);
    double b = (somaY - a * somaX) / n;

    printf("y = %.2fx + %.2f\n", a, b);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo.csv\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (!arquivo) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    int capacidade = 10;  
    int n = 0;           
    struct Ponto *pontos = malloc(capacidade * sizeof(struct Ponto));

    if (!pontos) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    double x, y;
    int contador_de_linhas = 0; 

    while (!feof(arquivo)) {
        if (fscanf(arquivo, "%lf,%lf", &x, &y) == 2) {
            pontos[n].x = x;
            pontos[n].y = y;
            n++;}
        if (n == capacidade) {
            capacidade *= 2;
            pontos = realloc(pontos, capacidade * sizeof(struct Ponto));
            if (!pontos) {
                printf("Erro de realocação de memória.\n");
                return 1;
            }
        }

        contador_de_linhas++;
    }

    fclose(arquivo);

    if (n < 2) {
        printf("Não há pontos suficientes para calcular a regressão linear.\n");
        free(pontos);
        return 1;
    }

    for(int i=0; i<=contador_de_linhas; i++){
    regressaoLinear(pontos, n++);}

    free(pontos);

    return 0;
}

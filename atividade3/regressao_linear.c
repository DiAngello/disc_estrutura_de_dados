#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    printf("A linha de regressao linear e: y = %.1fx + %.1f\n", a, b);
}

int main(int argc, char *argv[]) {
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

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (n == capacidade) {
            capacidade *= 2;
            pontos = realloc(pontos, capacidade * sizeof(struct Ponto));
            if (!pontos) {
                printf("Erro de realocação de memória.\n");
                return 1;
            }
        }

        char *token = strtok(linha, ",");
        if (token) {
            pontos[n].x = atof(token);
            token = strtok(NULL, ",");
            if (token) {
                pontos[n].y = atof(token);
                n++;
            }
        }
    }

    fclose(arquivo);

    if (n < 2) {
        printf("Não há pontos suficientes para calcular a regressão linear.\n");
        return 1;
    }

    regressaoLinear(pontos, n);

    free(pontos);

    return 0;
}

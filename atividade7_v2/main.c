#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"
#include "pilha.h"

typedef struct {
    int valor;
    char naipe;
} Carta;

void inicializarBaralho(Carta baralho[]) {
    char naipes[] = {'C', 'O', 'P', 'E'};
    int valores[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}; 

    int index = 0;
    for (int n = 0; n < 4; n++) {
        for (int v = 0; v < 13; v++) {
            baralho[index].valor = valores[v];
            baralho[index].naipe = naipes[n];
            index++;
        }
    }
}

void embaralharBaralho(Carta baralho[], int tamanho) {
    srand(time(NULL));
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

int main() {
    Fila filaJogadores;
    Pilha pilhaCartas;
    Carta baralho[52]; 

    inicializarFila(&filaJogadores);
    inicializarPilha(&pilhaCartas);
    inicializarBaralho(baralho); 
    embaralharBaralho(baralho, 52); 

    for (int i = 1; i <= 5; i++) {
        enfileirar(&filaJogadores, i);
    }

    while (tamanhoFila(&filaJogadores) > 0) {
        int jogador = desenfileirar(&filaJogadores);
        
        Carta cartaJogada = baralho[jogador - 1];
        printf("Jogador %d jogou a carta: %d do naipe %c\n", jogador, cartaJogada.valor, cartaJogada.naipe);

        empilhar(&pilhaCartas, cartaJogada.valor);
    }

    printf("\nCartas jogadas na pilha:\n");
    while (tamanhoPilha(&pilhaCartas) > 0) {
        int carta = desempilhar(&pilhaCartas);
        printf("%d\n", carta);
    }
    printf("\n");

    return 0;
}

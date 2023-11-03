#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

#define M 11

Registro tabelaHash[M];

void initialize_hash_table() {
    for (int i = 0; i < M; i++) {
        tabelaHash[i].chave = NULL;
        tabelaHash[i].dado = NULL;
    }
}

int hash(char* chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % M;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    while (tabelaHash[index].chave != NULL) {
        if (strcmp(tabelaHash[index].chave, chave) == 0) {
            free(tabelaHash[index].dado);
            tabelaHash[index].dado = strdup(dado);
            return;
        }
        index = (index + 1) % M;
    }
    tabelaHash[index].chave = strdup(chave);
    tabelaHash[index].dado = strdup(dado);
}

Registro* hash_table_get(char* chave) {
    int index = hash(chave);
    while (tabelaHash[index].chave != NULL) {
        if (strcmp(tabelaHash[index].chave, chave) == 0) {
            return &tabelaHash[index];
        }
        index = (index + 1) % M;
    }
    return NULL;
}

void print_hash_table() {
    printf("\n------------------------TABELA---------------------------\n");
    for (int i = 0; i < M; i++) {
        if (tabelaHash[i].chave != NULL) {
            printf("\n%2d = %s \t %s", i, tabelaHash[i].chave, tabelaHash[i].dado);
        } else {
            printf("\n%2d =", i);
        }
    }
    printf("\n----------------------------------------------------------\n");
}

void destroy_hash_table() {
    for (int i = 0; i < M; i++) {
        if (tabelaHash[i].chave != NULL) {
            free(tabelaHash[i].chave);
            free(tabelaHash[i].dado);
        }
    }
}
int hash_table_contains(char* chave) {
    int index = hash(chave);
    while (tabelaHash[index].chave != NULL) {
        if (strcmp(tabelaHash[index].chave, chave) == 0) {
            return 1;  
        }
        index = (index + 1) % M;
    }
    return 0;  
}
void hash_table_remove(char* chave) {
    int index = hash(chave);
    while (tabelaHash[index].chave != NULL) {
        if (strcmp(tabelaHash[index].chave, chave) == 0) {
            free(tabelaHash[index].chave);
            free(tabelaHash[index].dado);
            tabelaHash[index].chave = NULL;
            tabelaHash[index].dado = NULL;
            return; 
        }
        index = (index + 1) % M;
    }
}
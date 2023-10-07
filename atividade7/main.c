#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

int main() {
    Pilha historicoNavegacao;
    inicializarPilha(&historicoNavegacao);

    printf("Sistema de Gerenciamento de Historico de Navegacao em um Navegador Web\n");

    while (1) {
        char url[100];
        printf("Digite o site que deseja acessar (ou digite 'sair' para encerrar): ");
        scanf("%s", url);

        if (strcmp(url, "sair") == 0) {
            break;
        }
        
        PaginaWeb pagina;
        strcpy(pagina.url, url);
        empilharPagina(&historicoNavegacao, pagina);
    }
    
    printf("\nHistorico de Navegacao:\n");

    while (!pilhaEstaVazia(&historicoNavegacao)) {
        PaginaWeb pagina = desempilharPagina(&historicoNavegacao);
        printf("Pagina visitada: %s\n", pagina.url);
    }

    Fila filaImpressao;
    inicializarFila(&filaImpressao);

    printf("\n======================================\n");
    printf("\nSistema de Impressao de Documentos\n");

    while (1) {
        char nomeDocumento[100];
        printf("Digite o nome do documento para impressao (ou digite 'sair' para encerrar): ");
        scanf("%s", nomeDocumento);

        if (strcmp(nomeDocumento, "sair") == 0) {
            break;
        }

        Documento documento;
        strcpy(documento.nomeDocumento, nomeDocumento);
        enfileirarDocumento(&filaImpressao, documento);
    }

    printf("\nFila de Impressao:\n");

    while (!filaEstaVazia(&filaImpressao)) {
        Documento documento = desenfileirarDocumento(&filaImpressao);
        printf("Imprimindo documento: %s\n", documento.nomeDocumento);
    }

    return 0;
}

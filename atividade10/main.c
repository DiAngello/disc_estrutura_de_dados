#include <stdio.h>
#include "tabela_hash.h" 

int main() {
    int opcao;
    char estudante[50];
    char matricula[50];

    initialize_hash_table();

    do {
        printf("1 - Inserir\n2 - Buscar\n3 - Imprimir\n4 - Verificar \n5 - Remover\n0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                printf("Digite o nome do estudante: ");
                scanf("%s", estudante);
                printf("Digite a matricula: ");
                scanf("%s", matricula);
                hash_table_put(matricula, estudante);
                break;
            case 2:
                printf("Digite a matricula a ser buscada: ");
                scanf("%s", matricula);
                Registro* registro = hash_table_get(matricula);

                if (registro) {
                    printf("\n\tMatricula: %s \tEstudante: %s\n", registro->chave, registro->dado);
                } else {
                    printf("\tMatricula nao encontrada!\n");
                }
                break;
            case 3:
                print_hash_table();
                break;
            case 4:
               printf("Digite a matricula: ");
                scanf("%s", matricula);
                if (hash_table_contains(matricula)) {
                    printf("A matricula existe na tabela.\n");
                } else {
                    printf("A matricula não existe na tabela.\n");
                }
                break;
            case 5:
                printf("Digite a matricula a ser removida: ");
                scanf("%s", matricula);
                hash_table_remove(matricula);
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    destroy_hash_table();

    return 0;
}

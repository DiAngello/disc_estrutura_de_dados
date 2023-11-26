//Ana Luiza da Penha 
//Andressa Gabrielly A. de Souza

#include <stdio.h>
#include "binary_search_tree.h"

int main() {
    struct TreeNode* root = NULL;

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir um numero\n");
        printf("2. Remover um numero\n");
        printf("3. Buscar um numero\n");
        printf("4. Imprimir em ordem\n");
        printf("5. Imprimir pre-ordem\n");
        printf("6. Imprimir pos-ordem\n");
        printf("7. Encontrar valor minimo\n");
        printf("8. Encontrar valor maximo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nDigite o numero a ser inserido: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("\nDigite o numero a ser removido: ");
                scanf("%d", &value);
                root = removeNode(root, value);
                break;
            case 3:
                printf("\nDigite o numero a ser buscado: ");
                scanf("%d", &value);
                printf(search(root, value) ? "Encontrado\n" : "Nao Encontrado\n");
                break;
            case 4:
                printf("\nInorder: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("\nPreorder: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("\nPostorder: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("\nValor minimo: %d\n", findMinValue(root));
                break;
            case 8:
                printf("\nValor maximo: %d\n", findMaxValue(root));
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (choice != 0);
    root = destroyTree(root);
    return 0;
}

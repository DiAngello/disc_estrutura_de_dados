#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct TreeNode* removeNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = removeNode(root->left, key);
    } else if (key > root->key) {
        root->right = removeNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMin(root->right);
        root->key = temp->key;
        root->right = removeNode(root->right, temp->key);
    }

    return root;
}

int search(struct TreeNode* root, int key) {
    if (root == NULL || root->key == key) {
        return root != NULL;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int findMinValue(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->key;
}

int findMaxValue(struct TreeNode* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->key;
}
struct TreeNode* destroyTree(struct TreeNode* root) {
    if (root != NULL) {
        root->left = destroyTree(root->left);
        root->right = destroyTree(root->right);
        free(root);
    }
    return NULL;
}

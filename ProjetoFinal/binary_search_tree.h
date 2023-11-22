#define BINARY_SEARCH_TREE_H

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int key);
struct TreeNode* insert(struct TreeNode* root, int key);
struct TreeNode* removeNode(struct TreeNode* root, int key);
int search(struct TreeNode* root, int key);
void inorder(struct TreeNode* root);
void preorder(struct TreeNode* root);
void postorder(struct TreeNode* root);
int findMinValue(struct TreeNode* root);
int findMaxValue(struct TreeNode* root);
struct TreeNode* destroyTree(struct TreeNode* root) ;

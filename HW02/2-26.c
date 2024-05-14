#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left, *right;
} TreeNode;

// 创建新节点
TreeNode* newNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// 通过前序和中序遍历重建二叉树
TreeNode* buildTree(char *preorder, char *inorder, int n) {
    if (n <= 0) return NULL;

    TreeNode *node = newNode(preorder[0]);

    int pos = strchr(inorder, preorder[0]) - inorder; // 在中序遍历中找到根节点的位置

    // 递归构建左子树和右子树
    node->left = buildTree(preorder + 1, inorder, pos);
    node->right = buildTree(preorder + pos + 1, inorder + pos + 1, n - pos - 1);

    return node;
}

// 层次遍历并输出二叉树的内容
void printLevelOrder(TreeNode *root) {
    if (!root) return;
    
    TreeNode *queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        TreeNode *node = queue[front++];
        
        printf("%c", node->data);
        
        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
}

int main() {
    char preorder[100], inorder[100];
    char preOrderCode, inOrderCode;
    
    scanf(" %c", &preOrderCode);
    scanf("%s", preorder);
    scanf(" %c", &inOrderCode);
    scanf("%s", inorder);
    
    TreeNode *root = buildTree(preorder, inorder, strlen(preorder));
    
    printLevelOrder(root);
    
    return 0;
}

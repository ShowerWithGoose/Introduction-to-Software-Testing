#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node*insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    // 递归插入新节点
    if (data < root->data) { // 如果新节点数据小于当前节点数据，则插入到左子树中
        root->left = insert(root->left, data);
    } else if (data > root->data) { // 如果新节点数据大于当前节点数据，则插入到右子树中
        root->right = insert(root->right, data);
    }

    return root; // 返回更新后的根节点指针
}

void printLeafNodes(Node* root, int height) {
    if(root!=NULL)
    {
        if (root->left == NULL && root->right == NULL) {
            printf("%d %d\n", root->data, height);
        }
        printLeafNodes(root->left, height + 1);
        printLeafNodes(root->right, height + 1);
    }
}

int main() {
    Node* root = NULL;
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    printLeafNodes(root, 1);
    return 0;
}


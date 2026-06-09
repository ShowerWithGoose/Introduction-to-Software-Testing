#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct NodeSpace {
    int data;
    struct NodeSpace *left, *right;
    int depth;
} NodeSpace, *Node;

Node CreateNode(int data) {
    Node node = malloc(sizeof(NodeSpace));
    node->data = data;
    node->left = node->right = NULL;
    node->depth = -1;
    return node;
}

Node CreateTree(int elem_list[], int elem_quantity) {
    if(!elem_quantity) {
        return NULL;
    }
    Node tree = CreateNode(elem_list[0]);
    tree->depth = 1;
    for(int i = 1; i < elem_quantity; i++) {
        Node current = tree;
        while(1) {
            if(elem_list[i] >= current->data) {
                if(current->right) {
                    current = current->right;
                } else {
                    current->right = CreateNode(elem_list[i]);
                    current->right->depth = current->depth + 1;
                    break;
                }
            } else {
                if(current->left) {
                    current = current->left;
                } else {
                    current->left = CreateNode(elem_list[i]);
                    current->left->depth = current->depth + 1;
                    break;
                }
            }
        }
    }
    return tree;
}

void Visit(Node node){
    if(!(node->left || node->right)){
        printf("%d %d\n", node->data, node->depth);
    }
}

void InorderTraverse(Node tree) {
    if(tree) {
        InorderTraverse(tree->left);
        Visit(tree);
        InorderTraverse(tree->right);
    }
}

int main() {
    int elem_list[MAX_N], quantity;

    scanf("%d", &quantity);
    for(int i = 0; i < quantity; i++){
        scanf("%d", &elem_list[i]);
    }

    Node tree = CreateTree(elem_list, quantity);
    InorderTraverse(tree);

    return 0;
}

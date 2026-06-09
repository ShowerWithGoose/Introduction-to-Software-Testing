#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long Coordinate;
typedef struct NodeSpace{
    Coordinate coordinate;
    struct NodeSpace *left, *right, *left_neighbor, *right_neighbor;
    char visit;
} NodeSpace, *Node;

int max_length = 0;
Coordinate ans_coordinate;

Node CreateNode(Coordinate coordinate){
    Node node = malloc(sizeof(NodeSpace));
    node->coordinate = coordinate;
    node->left = node->right = node->left_neighbor = node->right_neighbor =  NULL;
    node->visit = 0;
    return node;
}

void DeleteNode(Node *node_ptr){
    free(*node_ptr);
    *node_ptr = NULL;
}

void Insert(Node search_tree, Coordinate coordinate_of_left ,Coordinate coordinate_of_right){
    Node current = search_tree;
    Node node_left = CreateNode(coordinate_of_left);
    Node node_right = CreateNode(coordinate_of_right);
    node_left->right_neighbor = node_right;
    node_right->left_neighbor = node_left;
    while(1){
        if(coordinate_of_left > current->coordinate){
            if(current->right){
                current = current->right;
            } else{
                current->right = node_left;
                break;
            }
        } else if(coordinate_of_left < current->coordinate){
            if(current->left){
                current = current->left;
            } else{
                current->left = node_left;
                break;
            }
        } else{
            current->right_neighbor = node_right;
            node_right->left_neighbor = current;
            DeleteNode(&node_left);
            break;
        }
    }

    current = search_tree;
    while(1){
        if(coordinate_of_right > current->coordinate){
            if(current->right){
                current = current->right;
            } else{
                current->right = node_right;
                break;
            }
        } else if(coordinate_of_right < current->coordinate){
            if(current->left){
                current = current->left;
            } else{
                current->left = node_right;
                break;
            }
        } else{
            node_right->left_neighbor->right_neighbor = current;
            current->left_neighbor = node_right->left_neighbor;
            DeleteNode(&node_right);
            break;
        }
    }
}

void VisitAndMakeLength(Node head){
    int temp_length = 0;
    Node current = head;
    while(current->right_neighbor){
        current->visit = 1;
        current = current->right_neighbor;
        temp_length++;
    }
    current->visit = 1;
    if(temp_length > max_length){
        max_length = temp_length;
        ans_coordinate = head->coordinate;
    }
}

void VisitTree(Node tree){
    if(!tree){
        return;
    }
    VisitTree(tree->left);
    if(tree->visit == 0){
        VisitAndMakeLength(tree);
    }
    VisitTree(tree->right);
}

int main(){
    int n;
    Coordinate coordinate_of_left, coordinate_of_right;
    unsigned long long x, y;

    scanf("%d", &n);

    scanf("%llu%llu", &x, &y);
    coordinate_of_left = (x << 32) + y;
    scanf("%llu%llu", &x, &y);
    coordinate_of_right = (x << 32) + y;
    Node tree = CreateNode(coordinate_of_left);
    tree->right = CreateNode(coordinate_of_right);
    tree->right_neighbor = tree->right;
    tree->right->left_neighbor = tree;

    for(int i = 1; i < n; i++){
        scanf("%llu%llu", &x, &y);
        coordinate_of_left = (x << 32) + y;
        scanf("%llu%llu", &x, &y);
        coordinate_of_right = (x << 32) + y;
        Insert(tree, coordinate_of_left, coordinate_of_right);
    }

    VisitTree(tree);

    y = ans_coordinate & 0xffff;
    x = ans_coordinate >> 32;

    printf("%d %d %d", max_length, (int)x, (int)y);



    return 0;
}

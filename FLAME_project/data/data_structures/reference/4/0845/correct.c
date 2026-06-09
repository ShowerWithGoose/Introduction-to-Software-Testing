#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeSpace{
    char word[500];
    int quantity;
    struct NodeSpace *left;
    struct NodeSpace *right;
} NodeSpace, *Node;

Node CreateNode(char *word){
    Node node = malloc(sizeof(NodeSpace));
    strcpy(node->word, word);
    node->quantity = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void Insert(char *word, Node tree){
    Node current = tree;
    while(1){
        if(strcmp(word, current->word) == 0){
            current->quantity++;
            break;
        } else if(strcmp(word, current->word) < 0){
            if(current->left){
                current = current->left;
            } else{
                current->left = CreateNode(word);
                break;
            }
        } else{
            if(current->right){
                current = current->right;
            } else{
                current->right = CreateNode(word);
                break;
            }
        }
    }
}

void Print(Node tree){
    if(!tree){
        return;
    }
    Print(tree->left);
    printf("%s %d\n", tree->word, tree->quantity);
    Print(tree->right);
}

int main(){
    FILE *input = fopen("article.txt", "r");
    char current_word[500];
    int current_char, rear = 0;
    int word_exist_flag = 0;
    Node tree = NULL;

    while((current_char = fgetc(input)) != EOF){
        if(current_char >= 'a' && current_char <= 'z'){
            word_exist_flag = 1;
            current_word[rear++] = (char)current_char;
        } else if(current_char >= 'A' && current_char <= 'Z'){
            word_exist_flag = 1;
            current_word[rear++] = (char)(current_char - 'A' + 'a');
        } else{
            if(word_exist_flag){
                current_word[rear] = 0;
                rear = 0;
                word_exist_flag = 0;
                if(tree){
                    Insert(current_word, tree);
                } else{
                    tree = CreateNode(current_word);
                }
            }
        }
    }

    Print(tree);

    fclose(input);

    return 0;
}


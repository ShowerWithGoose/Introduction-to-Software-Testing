#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeSpace{
    long long coefficient;
    long long exponent;
    struct NodeSpace *next;
} NodeSpace, *Node;

Node CreateNode(long long coefficient, long long exponent){
    Node node = malloc(sizeof(NodeSpace));
    node->coefficient = coefficient;
    node->exponent = exponent;
    node->next = NULL;
    return node;
}

int main(){
    long long multinomial_one[1000][2], multinomial_two[1000][2];
    int poly1 = 0, poly2 = 0, rear = 0, condition = 0;
    char current_char, temp_num[100];

    while(1){
        scanf("%c", &current_char);
        if(current_char == '\n'){
            temp_num[rear] = 0;
            rear = 0;
            condition = 0;
            multinomial_one[poly1][1] = atoll(temp_num);
            poly1++;
            break;
        } else{
            if(current_char == ' '){
                temp_num[rear] = 0;
                rear = 0;
                if(condition){
                    multinomial_one[poly1][1] = atoll(temp_num);
                    poly1++;
                    condition = 0;
                } else{
                    multinomial_one[poly1][0] = atoll(temp_num);
                    condition = 1;
                }
            } else{
                temp_num[rear++] = current_char;
            }
        }
    }

    while(1){
        scanf("%c", &current_char);
        if(current_char == '\n'){
            temp_num[rear] = 0;
            multinomial_two[poly2][1] = atoll(temp_num);
            poly2++;
            break;
        } else{
            if(current_char == ' '){
                temp_num[rear] = 0;
                rear = 0;
                if(condition){
                    multinomial_two[poly2][1] = atoll(temp_num);
                    poly2++;
                    condition = 0;
                } else{
                    multinomial_two[poly2][0] = atoll(temp_num);
                    condition = 1;
                }
            } else{
                temp_num[rear++] = current_char;
            }
        }
    }

    Node result = CreateNode(multinomial_one[0][0] * multinomial_two[0][0], multinomial_one[0][1] + multinomial_two[0][1]);
    long long coefficient, exponent;
    for(int i = 0; i < poly1; i++){
        for(int j = 0; j < poly2; j++){
            if(!i && !j){
                continue;
            }
            coefficient = multinomial_one[i][0] * multinomial_two[j][0];
            exponent = multinomial_one[i][1] + multinomial_two[j][1];
            Node current = result;
            while(current){
                if(current->exponent == exponent){
                    current->coefficient += coefficient;
                    break;
                } else if(!current->next){
                    Node node_to_be_insert = CreateNode(coefficient, exponent);
                    current->next = node_to_be_insert;
                    break;
                } else if(current->next->exponent < exponent){
                    Node node_to_be_insert = CreateNode(coefficient, exponent);
                    node_to_be_insert->next = current->next;
                    current->next = node_to_be_insert;
                    break;
                } else{
                    current = current->next;
                }
            }
        }
    }

    while(result){
        if(result->coefficient){
            printf("%lld %lld ", result->coefficient, result->exponent);
        }
        result = result->next;
    }

    return 0;
}

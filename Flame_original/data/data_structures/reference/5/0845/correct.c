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
    int quantity_one = 0, quantity_two = 0, rear = 0, condition = 0;
    char current_char, temp_num[100];

    while(1){
        scanf("%c", &current_char);
        if(current_char == '\n'){
            temp_num[rear] = 0;
            rear = 0;
            condition = 0;
            multinomial_one[quantity_one][1] = atoll(temp_num);
            quantity_one++;
            break;
        } else{
            if(current_char == ' '){
                temp_num[rear] = 0;
                rear = 0;
                if(condition){
                    multinomial_one[quantity_one][1] = atoll(temp_num);
                    quantity_one++;
                    condition = 0;
                } else{
                    multinomial_one[quantity_one][0] = atoll(temp_num);
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
            multinomial_two[quantity_two][1] = atoll(temp_num);
            quantity_two++;
            break;
        } else{
            if(current_char == ' '){
                temp_num[rear] = 0;
                rear = 0;
                if(condition){
                    multinomial_two[quantity_two][1] = atoll(temp_num);
                    quantity_two++;
                    condition = 0;
                } else{
                    multinomial_two[quantity_two][0] = atoll(temp_num);
                    condition = 1;
                }
            } else{
                temp_num[rear++] = current_char;
            }
        }
    }

    Node ans = CreateNode(multinomial_one[0][0] * multinomial_two[0][0], multinomial_one[0][1] + multinomial_two[0][1]);
    long long temp_coefficient, temp_exponent;
    for(int i = 0; i < quantity_one; i++){
        for(int j = 0; j < quantity_two; j++){
            if(!i && !j){
                continue;
            }
            temp_coefficient = multinomial_one[i][0] * multinomial_two[j][0];
            temp_exponent = multinomial_one[i][1] + multinomial_two[j][1];
            Node current = ans;
            while(current){
                if(current->exponent == temp_exponent){
                    current->coefficient += temp_coefficient;
                    break;
                } else if(!current->next){
                    Node node_to_be_insert = CreateNode(temp_coefficient, temp_exponent);
                    current->next = node_to_be_insert;
                    break;
                } else if(current->next->exponent < temp_exponent){
                    Node node_to_be_insert = CreateNode(temp_coefficient, temp_exponent);
                    node_to_be_insert->next = current->next;
                    current->next = node_to_be_insert;
                    break;
                } else{
                    current = current->next;
                }
            }
        }
    }

    while(ans){
        if(ans->coefficient){
            printf("%lld %lld ", ans->coefficient, ans->exponent);
        }
        ans = ans->next;
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000

int main(){
    char operator[MAX];
    long long operand[MAX];
    char expression[MAX * 20];
    char *current, *next;
    int operand_number = 0, operator_number = 0;

    gets(expression);

    next = expression;
    for(int i = 0; expression[i] != '='; i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] =='*' || expression[i] == '/'){
            operator[operator_number++] = expression[i];
            expression[i] = '\0';
            current = next;
            operand[operand_number++] = atoll(current);
            next = expression + i + 1;
        }
    }

    operand[operand_number++] = atoll(next);

    for(int i = 0; i < operator_number; i++){
        if(operator[i] == '*'){
            operand[i] *= operand[i + 1];
            if(operator_number - i >= 2){
                memmove(operator + i, operator + i + 1, operator_number - i);
                memmove(operand + i + 1, operand + i + 2, (operand_number - i - 1) * sizeof(long long));
            }
            operator_number--;
            operand_number--;
            i--;
        } else if(operator[i] == '/'){
            operand[i] /= operand[i + 1];
            if(operator_number - i >= 2){
                memmove(operator + i, operator + i + 1, operator_number - i);
                memmove(operand + i + 1, operand + i + 2, (operand_number - i - 1) * sizeof(long long));
            }
            operator_number--;
            operand_number--;
            i--;
        }
    }

    for(int i = 0; i < operator_number; i++){
        if(operator[i] == '+'){
            operand[i + 1] = operand[i] + operand[i + 1];
        } else{
            operand[i + 1] = operand[i] - operand[i + 1];
        }
    }

    printf("%lld", operand[operator_number]);

    return 0;
}



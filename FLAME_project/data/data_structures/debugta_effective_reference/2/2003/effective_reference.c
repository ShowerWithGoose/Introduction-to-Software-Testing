#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000

int main(){
    char operator[MAX];
    long long operand[MAX];
    char expression[MAX * 20];
    char *current, *i;
    int j = 0, k = 0;

    gets(expression);

    i = expression;
    for(int i = 0; expression[i] != '='; i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] =='*' || expression[i] == '/'){
            operator[k++] = expression[i];
            expression[i] = '\0';
            current = i;
            operand[j++] = atoll(current);
            i = expression + i + 1;
        }
    }

    operand[j++] = atoll(i);

    for(int i = 0; i < k; i++){
        if(operator[i] == '*'){
            operand[i] *= operand[i + 1];
            if(k - i >= 2){
                memmove(operator + i, operator + i + 1, k - i);
                memmove(operand + i + 1, operand + i + 2, (j - i - 1) * sizeof(long long));
            }
            k--;
            j--;
            i--;
        } else if(operator[i] == '/'){
            operand[i] /= operand[i + 1];
            if(k - i >= 2){
                memmove(operator + i, operator + i + 1, k - i);
                memmove(operand + i + 1, operand + i + 2, (j - i - 1) * sizeof(long long));
            }
            k--;
            j--;
            i--;
        }
    }

    for(int i = 0; i < k; i++){
        if(operator[i] == '+'){
            operand[i + 1] = operand[i] + operand[i + 1];
        } else{
            operand[i + 1] = operand[i] - operand[i + 1];
        }
    }

    printf("%lld", operand[k]);

    return 0;
}



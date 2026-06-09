#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))
#define pai acos(-1)

int Max(int a, int b){
    return a > b ? a : b;
}

int Min(int a, int b){
    return a < b ? a : b;
}

typedef long long int ll;

int main(int argc, const char * argv[]) {
    int number[3] = {0}, count = 0, ans = 0;
    scanf("%d", &number[count]);
    count++;
    char c;
    c = getchar();
    c = getchar(); // @@ Assumes there is a space after the first number; if the next character is an operator, this skips it and may consume part of the next number.
    while(1){
        scanf("%d", &number[count]);
        switch (c) {
            case '+':
                //count++;
                break;
            case '-':
                number[count] = number[count] * (-1);
                //count++;
                break;
            case '*':
                count--;
                number[count] *= number[count + 1];
                number[count + 1] = 0;
                break;
            case '/':
                count--;
                number[count] /= number[count + 1];
                number[count + 1] = 0;
                break;
            default:
                break;
        }
        if (2 == count) {
            ans = number[0] + number[1];
            number[1] = number[2];
            number[0] = ans;
            number[2] = 0;
            count--;
        }
        
        c = getchar(); // @@ Assumes a space exists after the current number; if the operator is directly followed by the next digit, this consumes the operator instead of the space.
        c = getchar(); // @@ Assumes the second character is the operator; this may instead consume the first digit of the next number, corrupting further input.
        if('=' == c){
            ans = number[0] + number[1];
            break;
        }
        count++;
    }
    printf("%d", ans);
    return 0;
}
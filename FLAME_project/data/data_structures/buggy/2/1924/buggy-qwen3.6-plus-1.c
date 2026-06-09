//
//  main.c
//  表达式计算
//
//  Created by Miracle Zeta on 2024/3/1.
//

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
    c = getchar();
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
        if (2 == count) { // @@ The logic for handling addition and subtraction accumulation is flawed. It only triggers when count is exactly 2, but after multiplication/division, count might be 1 or other values, causing pending additions/subtractions to be ignored or handled incorrectly relative to the current buffer state. Specifically, it fails to accumulate results properly when multiple +/- operations occur without intervening *// that reset the buffer structure as expected by this specific logic.
            ans = number[0] + number[1];
            number[1] = number[2];
            number[0] = ans;
            number[2] = 0;
            count--;
        }
        
        c = getchar();
        c = getchar();
        if('=' == c){
            ans = number[0] + number[1]; // @@ Final calculation assumes only two numbers remain in the buffer (number[0] and number[1]), but due to the flawed accumulation logic above, intermediate results from previous additions/subtractions might be lost or stored incorrectly, leading to wrong final sum. For example, if the buffer contains more than just the last two operands effectively contributing to the sum, this line ignores them.
            break;
        }
        count++;
    }
    printf("%d", ans);
    return 0;
}
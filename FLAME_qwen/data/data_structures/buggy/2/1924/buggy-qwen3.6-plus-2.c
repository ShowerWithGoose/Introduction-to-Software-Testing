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
    c = getchar(); // @@ Assumes exactly one space after the number; fails if input has no spaces or multiple spaces.
    c = getchar(); // @@ Reads the operator but is fragile due to whitespace handling; should use scanf(" %c", &c) or skip whitespace properly.
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
                count--; // @@ Incorrectly decrements count when it is 1, causing number[0] (the accumulated sum) to be multiplied instead of the current term.
                number[count] *= number[count + 1];
                number[count + 1] = 0;
                break;
            case '/':
                count--; // @@ Incorrectly decrements count when it is 1, causing number[0] (the accumulated sum) to be divided instead of the current term.
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
        
        c = getchar(); // @@ Same whitespace assumption issue as before; will misread operators if spacing varies.
        c = getchar(); // @@ Same whitespace assumption issue as before; will misread operators if spacing varies.
        if('=' == c){
            ans = number[0] + number[1];
            break;
        }
        count++;
    }
    printf("%d", ans);
    return 0;
}
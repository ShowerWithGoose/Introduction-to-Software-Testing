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
    c = getchar(); // @@ [This skips one character after the first number, but if there are multiple spaces or no space, it may skip part of the next token or operator incorrectly.]
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
        
        c = getchar();
        c = getchar(); // @@ [Same issue: blindly reading two characters assumes fixed spacing and fails when operators or numbers are adjacent without consistent spacing. Also, after reading '=', this may read past input.]
        if('=' == c){
            ans = number[0] + number[1]; // @@ [This ignores the possibility that only one number remains (e.g., expression ends right after '='), and always adds number[0] and number[1], which may include stale or zero values.]
            break;
        }
        count++;
    }
    printf("%d", ans); // @@ [The logic does not correctly handle operator precedence beyond immediate left-to-right with a 3-element buffer; complex expressions like the test case overflow the tiny buffer and lose intermediate results.]
    return 0;
}
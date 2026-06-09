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
    c = getchar(); // @@ This assumes a space or newline after the number; if there is no space, the operator is skipped, causing incorrect parsing.
    c = getchar(); // @@ Same issue; the operator may be misread if there is no space.
    while(1){
        scanf("%d", &number[count]);
        switch (c) {
            case '+':
                //count++;
                break;
            case '-':
                //number[count] = number[count] * (-1); // @@ This line is commented out, so subtraction is not applied; the number remains positive, leading to incorrect addition instead of subtraction.
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
        c = getchar();
        if('=' == c){
            ans = number[0] + number[1];
            break;
        }
        count++;
    }
    printf("%d", ans);
    return 0;
}
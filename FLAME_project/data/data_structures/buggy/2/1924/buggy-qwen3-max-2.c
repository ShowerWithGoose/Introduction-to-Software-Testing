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
    c = getchar(); // @@ [This assumes every token is separated by exactly one space, which may not be true. Also, it skips the first operator incorrectly if there's no leading space.]
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
            count--; // @@ [This logic only accumulates two numbers at a time and doesn't correctly handle operator precedence across the whole expression, especially for long chains of + and -. It also overwrites values prematurely.]
        }
        
        c = getchar();
        c = getchar(); // @@ [Same issue as above: assumes fixed spacing and reads two characters blindly, which can consume part of a number or miss operators if spacing varies.]
        if('=' == c){
            ans = number[0] + number[1]; // @@ [At this point, number[1] might not represent the correct accumulated value due to flawed accumulation logic; also ignores possible leftover in number[2] or incorrect state.]
            break;
        }
        count++; // @@ [Incrementing count after possibly decrementing it in * or / cases leads to inconsistent indexing and buffer overflow risk since number array is only size 3.]
    }
    printf("%d", ans);
    return 0;
}
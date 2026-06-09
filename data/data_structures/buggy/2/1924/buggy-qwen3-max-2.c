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
    c = getchar(); // @@ [This assumes there's always a space after the number; if input has no space before operator or '=', it reads wrong character]
    while(1){
        scanf("%d", &number[count]); // @@ [If previous operator was '=' or input ends unexpectedly, this scanf may fail or read invalid data]
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
                number[count] /= number[count + 1]; // @@ [Integer division is required, but if number[count+1] is 0, this causes undefined behavior (division by zero)]
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
        c = getchar(); // @@ [Same issue: assumes two characters (e.g., space and operator), but input may not have consistent spacing; may consume '=' incorrectly or miss it]
        if('=' == c){
            ans = number[0] + number[1];
            break;
        }
        count++; // @@ [May cause buffer overflow if count exceeds 2, since number array only has size 3 and logic assumes limited history]
    }
    printf("%d", ans);
    return 0;
}
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
    c = getchar(); // @@ [This assumes there's always a space after the first number; if input starts with no space or has multiple spaces, it may read wrong character or skip needed operator]
    while(1){
        scanf("%d", &number[count]); // @@ [If the next token is not a number (e.g., due to malformed input or end), this will fail; also doesn't handle cases where operator comes before number correctly]
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
                number[count] /= number[count + 1]; // @@ [Potential division by zero if number[count+1] is 0; also integer division truncates toward zero which may be okay per spec but logic flow is fragile]
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
        c = getchar(); // @@ [Same issue as earlier: assumes exactly one space between tokens; fails if multiple spaces, tabs, or no space]
        if('=' == c){
            ans = number[0] + number[1];
            break;
        }
        count++; // @@ [May cause buffer overflow if expression is longer than expected since number array only has size 3]
    }
    printf("%d", ans);
    return 0;
}
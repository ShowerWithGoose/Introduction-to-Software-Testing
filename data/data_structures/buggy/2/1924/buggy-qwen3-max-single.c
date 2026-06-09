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
    c = getchar(); // @@ [This assumes there's always a space after the number, but input may not have consistent spacing; also skips one character blindly without checking if it's whitespace or operator]
    while(1){
        scanf("%d", &number[count]); // @@ [If the next token is '=', this scanf will fail to read an integer, leading to undefined behavior]
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
                number[count] /= number[count + 1]; // @@ [Integer division is required, but if number[count+1] is zero, this causes division by zero; also, order of operations may be violated due to left-to-right processing without proper precedence handling]
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
        c = getchar(); // @@ [Same issue as above: blindly reads two characters without validating input format or handling variable spacing]
        if('=' == c){
            ans = number[0] + number[1];
            break;
        }
        count++; // @@ [May cause buffer overflow if expression is longer than expected since 'number' array only has size 3]
    }
    printf("%d", ans);
    return 0;
}
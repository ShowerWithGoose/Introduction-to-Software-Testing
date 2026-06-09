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
    scanf("%d", &number[count]); // @@ [Error: This reads the first number but does not handle the case where the expression starts with a negative number or spaces before the first number. Also, the input format may include spaces, and this approach assumes the first token is always an integer.]
    count++;
    char c;
    c = getchar(); // @@ [Error: This reads the space or newline after the first number, but the input may have multiple spaces or no space. The logic of reading characters is fragile and may skip or misread operators.]
    c = getchar(); // @@ [Error: This reads the operator, but if there are multiple spaces, it may read a space instead of the operator. The input format allows spaces, so this approach is unreliable.]
    while(1){
        scanf("%d", &number[count]); // @@ [Error: This reads the next number, but if the expression ends with '=', this will fail because there is no number after '='. The loop should check for '=' before reading a number.]
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
        if (2 == count) { // @@ [Error: This condition is incorrect for handling operator precedence. It assumes that when count is 2, the first two numbers should be combined, but this does not correctly handle sequences like '1 + 2 * 3' where multiplication should be done first.]
            ans = number[0] + number[1];
            number[1] = number[2];
            number[0] = ans;
            number[2] = 0;
            count--;
        }
        
        c = getchar(); // @@ [Error: This reads a character, which could be a space or newline, not necessarily the operator. The logic is flawed because it assumes the next non-space character is the operator, but it does not skip spaces.]
        c = getchar(); // @@ [Error: Similar to above, this reads another character, but the input may have only one space or no space between number and operator. This double getchar() will skip or misread characters.]
        if('=' == c){
            ans = number[0] + number[1]; // @@ [Error: This assumes that after processing, the result is always in number[0] and number[1], but the array size is only 3 and the logic for combining numbers is incorrect. For example, with input '1 + 2 =', after reading '2', count becomes 2, then the if condition combines them, but the final answer may be wrong.]
            break;
        }
        count++; // @@ [Error: This increments count after reading the operator, but the array size is only 3, so if there are more than 3 numbers, it will cause out-of-bounds access.]
    }
    printf("%d", ans);
    return 0;
}
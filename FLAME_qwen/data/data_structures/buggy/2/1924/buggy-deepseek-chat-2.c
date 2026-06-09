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
    scanf("%d", &number[count]); // @@ [Error: The first number is read but the initial operator is not handled. The expression starts with a number, but the program assumes the first operator is read before the second number, leading to incorrect parsing of the first operation.]
    count++;
    char c;
    c = getchar(); // @@ [Error: This reads the space or newline after the first number, but the next getchar() reads the operator. However, the logic for handling the first operator is flawed because the program does not account for the initial operator before the first number.]
    c = getchar(); // @@ [Error: This reads the operator after the first number, but the program's loop structure assumes the operator is read before each subsequent number, causing misalignment in parsing.]
    while(1){
        scanf("%d", &number[count]); // @@ [Error: The program reads the next number but does not properly handle the case where the operator is '=' (end of expression). The loop may read an extra number after '='.]
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
        if (2 == count) { // @@ [Error: This condition is too restrictive. The program only combines results when count is exactly 2, but the expression may have more than two numbers before combining, leading to incorrect order of operations.]
            ans = number[0] + number[1];
            number[1] = number[2];
            number[0] = ans;
            number[2] = 0;
            count--;
        }
        
        c = getchar(); // @@ [Error: This reads the space or newline after the number, but the next getchar() reads the operator. The logic for reading the operator is inconsistent with the initial reading, causing potential off-by-one errors.]
        c = getchar(); // @@ [Error: This reads the operator, but the program does not handle the case where the operator is '=' correctly in the loop condition. The break condition is checked after reading, but the number may have already been read incorrectly.]
        if('=' == c){
            ans = number[0] + number[1]; // @@ [Error: This assumes only two numbers remain in the array, but the expression may have more than two numbers that haven't been combined yet, leading to incorrect final result.]
            break;
        }
        count++;
    }
    printf("%d", ans);
    return 0;
}
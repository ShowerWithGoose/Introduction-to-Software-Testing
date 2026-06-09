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
    c = getchar(); // @@ This assumes exactly one space after the first number; but input may have no space or multiple spaces, causing operator to be missed.
    c = getchar(); // @@ Same assumption; this line reads the operator, but it may actually read a digit if there is no space.
    while(1){
        scanf("%d", &number[count]); // @@ This assumes the next token is a number; if there is no space, the operator would be read as part of the number, causing failure.
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
        
        c = getchar(); // @@ Same assumption as line 24.
        c = getchar(); // @@ Same assumption as line 25.
        if('=' == c){
            ans = number[0] + number[1];
            break;
        }
        count++;
    }
    printf("%d", ans);
    return 0;
}
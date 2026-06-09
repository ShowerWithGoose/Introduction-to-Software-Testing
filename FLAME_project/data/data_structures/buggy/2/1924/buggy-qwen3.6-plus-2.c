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
    c = getchar();
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
        if (2 == count) { // @@ The logic for accumulating addition/subtraction results is flawed. It only triggers when count is exactly 2, but after multiplication/division, count decreases, potentially skipping accumulation or handling indices incorrectly for longer chains of +/-. Specifically, it fails to correctly maintain the running sum in number[0] when multiple +/- operations occur without intermediate *//.
            ans = number[0] + number[1];
            number[1] = number[2];
            number[0] = ans;
            number[2] = 0;
            count--;
        }
        
        c = getchar();
        c = getchar();
        if('=' == c){
            ans = number[0] + number[1]; // @@ The final result calculation assumes the result is always number[0] + number[1]. However, due to the flawed accumulation logic above, the intermediate results might not be correctly stored in number[0], or number[1] might contain irrelevant data if the last operation was * or /. For the input ending in =, it should sum up all remaining valid terms in the buffer, but the buffer management is broken.
            break;
        }
        count++;
    }
    printf("%d", ans);
    return 0;
}
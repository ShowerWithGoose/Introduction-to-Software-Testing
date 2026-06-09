#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#define max(a, b) ( (a > b) ? (a) : (b) )
#define min(a, b) ( (a < b) ? (a) : (b) )
int main () {
    char a[100];
    scanf("%s", a);
    int x = -1, y = -1;
    int flag = 1;
    int len = strlen(a);
    for(int i = 0; i < len&&(y == -1 || x == -1); i++){
        if(a[i]=='.'){
            x = i;
        }
        if(a[i]!= '0' && a[i] != '.'){
            y = i;
            flag = 0;
        }
    }
    printf("%c", a[y]);
    
    if(y != len-1){
        printf(".");
    }
    
    for(int i = y+1; i < len; i++){
        if(a[i]=='.'){
            printf("%c", a[i]); // @@ This line incorrectly prints the decimal point instead of the digits after it. The loop should print all characters except the decimal point to output the fractional part of the base.
        }
    }
    
    if(x > y){
        y++;
    }
    
    printf("e%d\n", x-y); // @@ The exponent calculation is incorrect. For numbers like 0.00000009123456789012, x is the position of the decimal point, y is the position of the first non-zero digit. The exponent should be -(y - x - 1) or similar, not x - y. Also, the exponent should not have a '+' sign for positive exponents, but the output format expects no sign for non-negative exponents.
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> // @@ Non-standard header, may cause compilation error on some systems.
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
        if(a[i]=='.'){ // @@ Condition should be 'if(a[i] != '.')' to print the actual digits, not the decimal point.
            printf("%c", a[i]);
        }
    }
    
    if(x > y){ // @@ This adjustment of y may skip significant digits and is not a correct way to compute exponent.
        y++;
    }
    
    printf("e%d\n", x-y);
    return 0;
}
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
        if(a[i]=='.'){ // @@ This condition is incorrect; it should print all digits after the first significant digit, not just the decimal point. The loop should print all characters except the decimal point.
            printf("%c", a[i]);
        }
    }
    
    if(x > y){
        y++;
    }
    
    printf("e%d\n", x-y); // @@ The exponent calculation is incorrect. It should be (point - begin - 1) if begin < point, else (point - begin). The current formula does not handle cases where the decimal point is before the first significant digit correctly.
    return 0;
}
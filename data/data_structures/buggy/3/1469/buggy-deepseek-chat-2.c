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
            printf("%c", a[i]); // @@ This loop prints only the decimal point, but should print all digits after the first significant digit, skipping the decimal point itself.
        }
    }
    
    if(x > y){
        y++;
    }
    
    printf("e%d\n", x-y); // @@ The exponent calculation is incorrect; it should be (point - begin - 1) when begin < point, and (point - begin) when begin > point, but here it uses x-y which does not account for the decimal point position correctly.
    return 0;
}
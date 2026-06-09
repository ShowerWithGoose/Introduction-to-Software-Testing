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
            printf("%c", a[i]);
        }
    } // @@ [This loop only prints the decimal point but skips all non-zero digits after the first significant digit. It should print all digits after the first significant digit except the decimal point.]
    
    if(x > y){
        y++;
    }
    
    printf("e%d\n", x-y); // @@ [The exponent calculation is incorrect. For numbers less than 1 (like 0.000...), the exponent should be negative and equal to -(number of leading zeros after decimal + 1). The current formula x - y gives wrong sign and magnitude.]
    return 0;
}
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
    
    if(y != len-1){ // @@ [Error: This condition does not correctly determine whether a decimal point is needed; should check if there are other significant digits after the first one]
        printf("."); // @@ [Error: Prints a dot unconditionally when y != len-1, but may print a dot even if the next character is a decimal point, causing double dots]
    }
    
    for(int i = y+1; i < len; i++){
        if(a[i]=='.'){ // @@ [Error: This conditional prints only decimal points, not the actual digits after the first significant digit. Should print all characters except the decimal point.]
            printf("%c", a[i]);
        }
    }
    
    if(x > y){
        y++;
    }
    
    printf("e%d\n", x-y);
    return 0;
}
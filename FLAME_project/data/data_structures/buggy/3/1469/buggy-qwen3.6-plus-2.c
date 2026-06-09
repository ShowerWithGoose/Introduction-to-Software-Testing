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
        if(a[i]=='.'){ // @@ The condition checks if the character is '.', but we want to print all significant digits after the first non-zero digit, excluding the original decimal point. It should check if a[i] != '.' to print the digits, or simply print all characters from y+1 to end except the original dot at index x. The current logic only prints dots, which is incorrect. It should be: if (i != x) printf("%c", a[i]);
            printf("%c", a[i]);
        }
    }
    
    if(x > y){
        y++;
    }
    
    printf("e%d\n", x-y);
    return 0;
}
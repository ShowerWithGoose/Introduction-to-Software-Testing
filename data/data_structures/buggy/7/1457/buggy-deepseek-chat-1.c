#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0)
#include <ctype.h>
#include <stdlib.h>
char s[200];
int main(){
    int n=0;
    //FILE *fp = fopen("example.c","r");
    while(gets(s) != NULL){ // @@ [Error: gets() is deprecated and removed from C11 standard; it can cause buffer overflow and compilation errors in modern compilers. Use fgets() instead.]
        n++;
        puts(s);
    }
    
return 0;
}
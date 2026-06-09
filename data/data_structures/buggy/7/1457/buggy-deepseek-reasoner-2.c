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
    while(gets(s) != NULL){ // @@ [gets is removed from C11 standard and causes compilation error in modern compilers]
        n++;
        puts(s);
    }
    
return 0;
}
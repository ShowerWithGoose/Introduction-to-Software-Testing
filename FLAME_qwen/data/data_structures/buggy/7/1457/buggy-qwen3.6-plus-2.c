#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0) // @@ Redefinition of the standard macro NULL causes a compilation error.
#include <ctype.h>
#include <stdlib.h>
char s[200];
int main(){
    int n=0;
    //FILE *fp = fopen("example.c","r");
    while(gets(s) != NULL){ // @@ `gets` is removed in the C11 standard and causes a compilation error; additionally, the program logic does not implement BST construction or leaf node output as required.
        n++;
        puts(s);
    }
    
return 0;
}
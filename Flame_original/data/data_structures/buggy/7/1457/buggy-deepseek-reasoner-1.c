#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0) // @@ Redefinition of NULL after including standard headers may cause compilation error if the existing definition is not identical.
#include <ctype.h>
#include <stdlib.h>
char s[200];
int main(){
    int n=0;
    //FILE *fp = fopen("example.c","r");
    while(gets(s) != NULL){
        n++;
        puts(s);
    }
    
return 0;
}
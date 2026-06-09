#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0) // @@ Redefinition of NULL macro; <stdio.h> already defines it, may cause compilation error depending on compiler strictness.
#include <ctype.h>
#include <stdlib.h>
char s[200];
int main(){
    int n=0;
    //FILE *fp = fopen("article.txt","r");
    while(gets(s) != NULL){ // @@ gets() is removed in C11 and later; using it leads to implicit declaration error in strict C11 mode.
        n++;
        printf("%s\n",s);
    }
    
return 0;
}
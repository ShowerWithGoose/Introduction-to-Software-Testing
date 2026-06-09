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
    //FILE *fp = fopen("article.txt","r");
    while(gets(s) != NULL){ @@ [The function 'gets' is unsafe and has been removed from the C standard library in C11; many compilers no longer support it, leading to compilation errors. It should be replaced with 'fgets'.]
        n++;
        printf("%s\n",s);
    }
    
return 0;
}
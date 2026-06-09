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
    while(gets(s) != NULL){ @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11. Using it may cause compilation errors or warnings with modern compilers, leading to a compilation failure.]
        n++;
        puts(s);
    }
    
return 0;
}
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
    while(gets(s) != NULL){ @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. Additionally, the program logic does not implement the required BST construction or leaf node height calculation as per the problem description.]
        n++;
        puts(s); @@ [This simply echoes input lines, which is unrelated to the problem's requirement of building a BST and printing leaf nodes with their heights.]
    }
    
return 0;
}
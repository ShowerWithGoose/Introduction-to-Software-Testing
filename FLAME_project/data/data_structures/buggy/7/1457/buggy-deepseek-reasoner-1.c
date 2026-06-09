#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0) // @@ Unnecessary redefinition of NULL; may cause warning but not the main error.
#include <ctype.h>
#include <stdlib.h>
char s[200];
int main(){
    int n=0; // @@ Should store number of integers, not line counter; logic incorrect.
    //FILE *fp = fopen("example.c","r");
    while(gets(s) != NULL){ // @@ Uses gets(), dangerous and does not parse input correctly. Should read n first then loop n times to read integers.
        n++; // @@ Counting lines incorrectly; should not be used here.
        puts(s); // @@ Prints raw input, not the required leaf node values and heights.
    }
    
return 0;
}
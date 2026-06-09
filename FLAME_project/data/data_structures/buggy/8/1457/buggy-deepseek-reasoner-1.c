#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0) // @@ Unnecessary and could conflict with standard definition; not the main error.
#include <ctype.h>
#include <stdlib.h>
char s[200];
int main(){
    int n=0;
    //FILE *fp = fopen("article.txt","r");
    while(gets(s) != NULL){ // @@ Uses gets() which is unsafe and does not parse input as required (n, m, edges, delete vertex).
        n++; // @@ Unused variable, does not contribute to solution.
        printf("%s\n",s); // @@ Prints raw input lines instead of the required DFS/BFS traversal sequences.
    }
    
return 0;
}
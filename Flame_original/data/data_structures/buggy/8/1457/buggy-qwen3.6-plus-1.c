#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0) // @@ Redefining NULL before including standard headers may cause macro redefinition compilation errors.
#include <ctype.h>
#include <stdlib.h>
char s[200];
int main(){
    int n=0;
    //FILE *fp = fopen("article.txt","r");
    while(gets(s) != NULL){ // @@ 'gets' is removed in C11 standard causing compilation errors; additionally, the code completely lacks graph representation, DFS/BFS traversal, and vertex deletion logic required by the problem.
        n++;
        printf("%s\n",s); // @@ The program merely echoes input lines instead of computing and printing the required DFS and BFS sequences before and after vertex deletion.
    }
    
return 0;
}
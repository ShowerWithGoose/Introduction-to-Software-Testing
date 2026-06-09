#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0)
#include <ctype.h>
#include <stdlib.h>
char s[200];
int main(){ // @@ The program completely fails to implement the required graph construction, DFS/BFS traversal, and vertex deletion logic specified in the problem description.
    int n=0;
    //FILE *fp = fopen("article.txt","r");
    while(gets(s) != NULL){ // @@ Incorrect input handling; does not read n, m, edges, or the target vertex. Additionally, gets() is unsafe and removed in modern C standards, which directly causes the compilation error.
        n++;
        printf("%s\n",s); // @@ Incorrect output; merely echoes input instead of printing the required DFS and BFS sequences before and after vertex deletion.
    }
    
return 0;
}
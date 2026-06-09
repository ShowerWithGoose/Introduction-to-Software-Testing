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
    while(gets(s) != NULL){ // @@ This loop simply reads input lines and prints them; it does not implement the required DFS/BFS traversal or deletion of a vertex.
        n++;
        printf("%s\n",s); // @@ Printing the input line instead of computing and printing the traversal sequences.
    }
    
return 0;
}
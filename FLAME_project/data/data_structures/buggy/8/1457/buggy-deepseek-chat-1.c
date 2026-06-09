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
    while(gets(s) != NULL){ // @@ [gets() is unsafe and reads from stdin, but the program should read graph input and perform DFS/BFS, not just echo input. The entire logic is missing.]
        n++;
        printf("%s\n",s); // @@ [This just prints the input lines, but the problem requires outputting DFS and BFS sequences before and after deletion. The program does not implement any graph traversal.]
    }
    
return 0;
}
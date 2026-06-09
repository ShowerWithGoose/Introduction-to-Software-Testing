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
    while(gets(s) != NULL){ // @@ [gets() is unsafe and reads the entire input including the graph data, but the program should parse the graph and perform DFS/BFS, not just echo input. The logic is completely wrong for the problem.]
        n++;
        printf("%s\n",s); // @@ [This just prints each line of input, which is not the required output format. The program should output traversal sequences, not echo input.]
    }
    
return 0;
}
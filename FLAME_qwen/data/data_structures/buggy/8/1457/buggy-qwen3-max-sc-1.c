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
    while(gets(s) != NULL){
        n++;
        printf("%s\n",s);
    }
    
return 0;
} // @@ [The program uses the deprecated and unsafe function 'gets', which may cause compilation errors or warnings in modern compilers. Additionally, the code does not implement graph traversal (DFS/BFS), vertex deletion, or any logic related to the problem description. It merely reads and prints input lines, which is entirely unrelated to the required functionality. This explains the mismatch between expected behavior and actual output, and likely causes a compilation error if 'gets' is disabled or not supported.]
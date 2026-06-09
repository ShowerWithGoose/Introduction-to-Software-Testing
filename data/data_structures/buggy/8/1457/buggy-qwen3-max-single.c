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
} // @@ [The program uses the deprecated and unsafe function 'gets', which has been removed from newer C standards (C11 onwards). This causes a compilation error on systems where 'gets' is not available. Additionally, the code does not implement graph traversal (DFS/BFS), vertex deletion, or any logic related to the problem description—it merely reads and prints input lines. The entire implementation is unrelated to the required functionality, leading to both compilation issues (due to 'gets') and logical failure.]
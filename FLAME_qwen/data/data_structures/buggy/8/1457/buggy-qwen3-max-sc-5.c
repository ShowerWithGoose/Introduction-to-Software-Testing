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
    while(gets(s) != NULL){ @@ [The function 'gets' is deprecated and removed in modern C standards (C11 onwards), leading to compilation errors on systems where it's not available. Additionally, the program logic does not implement graph traversal (DFS/BFS) as required by the problem description—it merely reads and prints input lines.]
        n++;
        printf("%s\n",s);
    }
    
return 0;
}
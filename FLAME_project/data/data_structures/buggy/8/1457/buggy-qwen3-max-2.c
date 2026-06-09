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
    while(gets(s) != NULL){ @@ [The program is simply reading and printing input lines instead of parsing the graph, building adjacency structures, performing DFS/BFS traversals before and after vertex deletion as required by the problem. It completely ignores the logic needed to solve the problem.]
        n++;
        printf("%s\n",s); @@ [This outputs the raw input, not the DFS/BFS traversal sequences. Hence, for the given test case, it prints the input back instead of the expected traversal orders.]
    }
    
return 0;
}
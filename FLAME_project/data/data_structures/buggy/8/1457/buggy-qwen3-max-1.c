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
    while(gets(s) != NULL){ @@ [The program is simply reading and printing input lines instead of parsing the graph, building adjacency structures, performing DFS/BFS traversals before and after vertex deletion as required by the problem. This leads to outputting the raw input rather than the expected traversal sequences.]
        n++;
        printf("%s\n",s); @@ [This prints each input line as-is, which matches the buggy output shown (printing the test case input), but completely ignores the problem's requirement to compute and output DFS/BFS traversal sequences.]
    }
    
return 0;
}
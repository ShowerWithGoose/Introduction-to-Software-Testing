#include <stdio.h> // @@ The program completely fails to implement the graph traversal logic (DFS/BFS) and vertex deletion. It merely reads input lines and prints them back, which is incorrect for the problem description.
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
    while(gets(s) != NULL){ // @@ This loop reads all input until EOF and prints it, instead of parsing the graph structure, performing traversals, and outputting the specific sequences required.
        n++;
        printf("%s\n",s); // @@ This outputs the raw input lines instead of the calculated DFS/BFS sequences before and after vertex deletion.
    }
    
return 0;
}
#include<stdio.h>
int main(){
    char s[1005];
    int i=9900;
    while(i--){ // @@ The loop runs a fixed number of times instead of reading the graph input (n, m, edges, delete vertex) and performing traversals.
    gets(s)    ; // @@ Using gets() is unsafe and does not read integers; the input format requires reading integers for vertices and edges.
    puts(s);// @@ @@ Outputting the raw input lines does not produce the required DFS/BFS sequences.
    }return 0;
}
#include<stdio.h>
#include<string.h>
int main()
{
   char str[1000]; // @@ The program does not read graph data (n, m, edges, delete vertex) as required by the problem.
   while(gets(str)!=NULL) // @@ The program should not simply echo input; it must parse graph adjacency and traverse.
   {
        puts(str); // @@ This line only outputs the raw input, not the required DFS/BFS sequences.
   }
   return 0; // @@ The program returns without performing any graph traversal or output.
}
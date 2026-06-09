#include<stdio.h>
#include<string.h>
int main() // @@ The program completely fails to implement the required graph input parsing, DFS, BFS traversal, and vertex deletion logic.
{
   char str[1000];
   while(gets(str)!=NULL) // @@ Incorrectly reads input as strings instead of parsing integers for vertices and edges; also uses the unsafe/deprecated gets() function.
   {
        puts(str); // @@ Simply echoes the input instead of computing and printing the DFS and BFS sequences before and after vertex deletion.
   }
   return 0;
}
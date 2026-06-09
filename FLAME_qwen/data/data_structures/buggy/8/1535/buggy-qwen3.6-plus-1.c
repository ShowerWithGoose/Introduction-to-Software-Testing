#include<stdio.h>
#include<string.h>
int main()
{
   char str[1000];
   while(gets(str)!=NULL) // @@ The program merely echoes input and completely lacks the implementation for graph representation, DFS/BFS traversal, and vertex deletion as specified in the problem.
   {
        puts(str);
   }
   return 0;
}
#include<stdio.h>
#include<string.h>
int main()
{
   char str[1000];
   while(gets(str)!=NULL)   // @@ The program should parse the first line for n and m, not simply read and echo all lines. This loop causes the program to output the input itself instead of performing the required graph traversals.
   {
        puts(str);   // @@ This statement prints the input line, which is incorrect. The program should output the DFS and BFS sequences of the graph as specified.
   }
   return 0;
}
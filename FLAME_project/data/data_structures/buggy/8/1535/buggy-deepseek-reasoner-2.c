#include<stdio.h>
#include<string.h>
int main()
{
   char str[1000];
   while(gets(str)!=NULL) // @@ This loop reads input lines but does not parse them; the program should read n, m, edges, and delete vertex according to the problem specification.
   {
        puts(str); // @@ This outputs the input lines instead of the required DFS/BFS sequences.
   }
   return 0;
}
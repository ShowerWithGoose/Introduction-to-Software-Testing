#include<stdio.h>
#include<stdlib.h>
int main() // @@ The program does not implement the required graph traversal (DFS/BFS before and after deletion). Instead, it simply echoes the entire input, which is incorrect for the problem.
{
    char data[1005];
    char c;
    while(scanf("%c",&c)!=EOF) // @@ The loop echoes characters instead of reading the graph structure and performing the required traversals.
    {
        printf("%c",c);
    }
    return 0;
    
}
#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF) // @@ The program fails to implement the graph traversal logic (DFS/BFS) and vertex deletion as required by the problem description. Instead, it merely reads integers and prints them, which is completely unrelated to the expected output format and content.
    
    printf("%d\n",x); // @@ This line prints the last read integer repeatedly or incorrectly due to the missing braces in the while loop, and does not produce the required DFS/BFS sequences.
    return 0;
}
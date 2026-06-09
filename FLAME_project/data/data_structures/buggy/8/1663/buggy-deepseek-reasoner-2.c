#include<stdio.h>
int main()
{
    int a; // @@ This variable is used to read one integer at a time, but the program needs to parse the graph structure (n, m, edges, delete vertex). As a result, the program fails to perform DFS/BFS.
    while(scanf("%d",&a)!=EOF) // @@ This loop reads all integers from input but does not store them appropriately. It also does not separate the input into the required components (n, m, edges, delete vertex). 
    {
        printf("%d ",a); // @@ This prints the input numbers without performing any graph traversals. The output does not match the expected DFS/BFS sequences.
    }
    return 0;
}
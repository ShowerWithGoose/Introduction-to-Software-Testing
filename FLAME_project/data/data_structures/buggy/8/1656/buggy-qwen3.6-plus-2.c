#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); // @@ The program incorrectly prints the input values instead of performing graph traversal. It lacks the adjacency matrix, DFS/BFS implementations, and logic to handle vertex deletion as required by the problem.
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); // @@ The program incorrectly prints the edge inputs instead of storing them in a data structure (like an adjacency matrix) to build the graph for traversal.
    }
    
    return 0;
 }
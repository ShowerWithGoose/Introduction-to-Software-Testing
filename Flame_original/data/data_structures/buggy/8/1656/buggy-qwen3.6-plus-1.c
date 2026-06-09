#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); // @@ Logical error: The problem requires outputting DFS and BFS traversal sequences, not echoing the number of vertices and edges.
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); // @@ Logical error: The program completely lacks graph storage, DFS/BFS traversal algorithms, vertex deletion logic, and the required output format.
    }
    
    return 0;
 }
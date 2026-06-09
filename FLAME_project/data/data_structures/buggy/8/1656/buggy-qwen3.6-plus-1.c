#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); // @@ The program incorrectly echoes the input vertices and edges instead of performing DFS/BFS traversals as required by the problem description.
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); // @@ The program incorrectly echoes the input edges instead of storing them in an adjacency matrix/list and performing the required graph traversals.
    }
    
    return 0;
 }
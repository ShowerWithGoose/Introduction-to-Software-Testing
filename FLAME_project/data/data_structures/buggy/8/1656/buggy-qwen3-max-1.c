#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); // @@ [This line incorrectly outputs the input values instead of performing graph traversal. The program should build an adjacency matrix and perform DFS/BFS before and after vertex deletion, but it only echoes the input.]
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); // @@ [This line also just echoes the edges instead of storing them in an adjacency structure needed for traversal. No graph representation is built, so no traversal can be performed.]
    }
    
    return 0;
 }
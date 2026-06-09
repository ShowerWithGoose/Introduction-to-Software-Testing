#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); // @@ [Prints input values, not the required DFS/BFS traversal sequences. This line should not exist.]
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); // @@ [Prints edge values, not the required traversal output. Also does not store edges for graph construction.]
    } // @@ [After reading edges, the program must read the vertex to delete and then perform DFS and BFS traversals before and after deletion. This missing logic causes the program to fail.]
    
    return 0;
 }
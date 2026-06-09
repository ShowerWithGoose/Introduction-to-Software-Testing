#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); // @@ [The program incorrectly outputs the input values instead of performing graph traversals. It should not print the input at all.]
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); // @@ [The program incorrectly echoes each edge input instead of building an adjacency structure and performing DFS/BFS traversals before and after vertex deletion.]
    }
    
    return 0;
 }
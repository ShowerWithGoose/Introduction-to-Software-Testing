#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); // @@ This line incorrectly prints the input values instead of performing graph traversal. The program should not output the input; it should output DFS and BFS sequences.
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); // @@ This line also incorrectly prints the edges instead of building the graph and performing traversals.
    }
    
    return 0;
 }
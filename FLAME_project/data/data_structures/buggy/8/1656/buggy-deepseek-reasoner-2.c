#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); // @@ This line prints the input values, but the program should not output them. The required output only includes DFS and BFS sequences.
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); // @@ This line prints the edges, which is not part of the required output. The program should instead build the adjacency matrix.
    }
    
    return 0;
 }
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); @@ [This line prints the number of vertices and edges, which is not part of the expected output. The program should only output traversal sequences, not input values.]
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); @@ [This line prints each edge as it is read, which is incorrect. The problem requires only DFS and BFS traversal sequences before and after deletion, not echoing input edges.]
    }
    
    return 0;
 }
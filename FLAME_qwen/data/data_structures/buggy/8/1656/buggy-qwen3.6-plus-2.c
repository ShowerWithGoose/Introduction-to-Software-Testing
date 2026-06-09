#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side);
    int i,j,k; // @@ In C89/C90 standards, variable declarations must appear before any executable statements in a block, which causes a compilation error here. Furthermore, the code completely lacks graph storage, DFS/BFS traversal algorithms, and vertex deletion logic required by the problem description.
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j);
    }
    
    return 0;
 }
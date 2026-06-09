#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); // @@ [This debug print statement alters the expected output format and should not be present. The program must only output traversal sequences, not input values.]
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); // @@ [This debug print statement outputs each edge as it is read, which violates the required output format. The program should only output DFS/BFS sequences before and after deletion, not intermediate input data.]
    }
    
    return 0;
 }
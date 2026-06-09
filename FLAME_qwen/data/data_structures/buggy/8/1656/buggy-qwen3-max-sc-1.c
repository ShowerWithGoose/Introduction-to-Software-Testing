#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); @@ [This debug print statement should not be present in the final output; it causes extra output that does not match expected format]
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); @@ [This debug print statement should not be present; it outputs edge data which is not part of the required DFS/BFS traversal output]
    }
    
    return 0;
 }
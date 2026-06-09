#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); @@ [This debug print statement should not be present in the final program and causes incorrect output format.]
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); @@ [This debug print statement should not be present and causes incorrect output format.]
    }
    
    return 0;
 }
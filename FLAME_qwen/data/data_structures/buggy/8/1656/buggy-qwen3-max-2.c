#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); @@ [This debug print statement should not be present as it alters the output format and causes mismatch with expected output]
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); @@ [This debug print statement should not be present as it alters the output format and causes mismatch with expected output]
    }
    
    return 0;
 }
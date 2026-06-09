#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int point,side;
    scanf("%d%d",&point,&side);
    printf("%d %d\n",point,side); // @@ This line prints the input values, which is not part of the required output format. The program should not print the input values.
    int i,j,k;
    
    for(k=0;k<side;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d %d\n",i,j); // @@ This line prints each edge, which is not part of the required output format. The program should not print the edges.
    }
    
    return 0;
 }
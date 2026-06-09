#include<stdio.h>     
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h> 
#include<limits.h>

int main()
{
    int op,num;
    int zhan[101];
    int i=1;
    while(op!=-1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&num);
            if(i>=101)
                printf("error ");
            else
            {
                zhan[i]=num;
                i++;
            }
        }
        else if(op==0)
        {
            if(i-1<=0)
                printf("error ");
            else
            {
                printf("%d ",zhan[i-1]);
                i--;
            }
        }
    }
    
    return 0;
}

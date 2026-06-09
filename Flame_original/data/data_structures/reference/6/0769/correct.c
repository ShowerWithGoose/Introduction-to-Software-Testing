#include<stdio.h>
#define maxsize 100
int s[150],total=0;
int main()
{
    int index,num;
    while(1)
    {
    scanf("%d",&index);
    if(index==1)
    {
        scanf("%d",&num);
        if(total==maxsize)
        printf("error ");
        else 
        s[total++]=num;
    }
    else if(index==0)
    {
        if(total==0)
        printf("error ");
        else
        printf("%d ",s[--total]);
    }
    else
    break;
    }
    return 0;
}

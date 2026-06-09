#include<stdio.h>
int s[100],front=-1;
int isfull()
{
    return front==99;
}
int isempty()
{
    return front==-1;
}
int main()
{
    int judge,item;
    scanf("%d",&judge);
    while(judge!=-1)
    {
        if(judge==1)
        {
            scanf("%d",&item);
            if(isfull())
                printf("error ");
            else
            {
                front++;
                s[front]=item;
            }
        }
        if(judge==0)
        {
            if(isempty())
                printf("error ");
            else
            {
                printf("%d ",s[front]);
                front--;
            }
        }
        scanf("%d",&judge);
    }
    return 0;
}


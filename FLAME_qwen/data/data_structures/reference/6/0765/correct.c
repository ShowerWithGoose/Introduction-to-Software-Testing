#include<stdio.h>
#define MAX 100
void PUSH(int a[],int *top,int item);
void POP(int a[],int *top);
int main()
{
    int a[MAX]={0};
    int flag,item,top=-1;
    do
    {
        scanf("%d",&flag);
        if(flag==1)
        {
            scanf("%d",&item);
            PUSH(a,&top,item);
        }
        if(flag==0)
        {
            POP(a,&top);
        }
    }while(flag!=-1);
    return 0;
}
void PUSH(int a[],int *top,int item)
{
    if(*top==MAX-1)
    {
        printf("error ");
        return;
    }
    else
    {
        *top=*top+1;
        a[*top]=item;
        return;
    }
}
void POP(int a[],int *top)
{
    if(*top==-1)
    {
        printf("error ");
        return;
    }
    else
    {
        printf("%d ",a[*top]);
        *top=*top-1;
        return;
    }
}

#include<stdio.h>
int a[100];
int flag,hold;
int top;

void initStack()
{
    top=-1;
}

void push(int a[],int item)
{
    if(top==99)
        printf("error ");
    else
        a[++top]=item;
}

void pop(int a[])
{
    if(top==-1)
        printf("error ");
    else
        printf("%d ",a[top--]);
}

int main()
{
    initStack();
    while(scanf("%d",&flag))
    {
        switch(flag)
        {
        case 1:
            {
                scanf("%d",&hold);
                push(a,hold);
                break;
            }
        case 0:
            {
                pop(a);
                break;
            }
        }
        if(flag==-1)
            break;
    }
    /*for(int i=0;i<=top;i++)
        printf("%d\n",a[i]);*/
    return 0;
}




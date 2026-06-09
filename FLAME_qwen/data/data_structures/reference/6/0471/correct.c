#include <stdio.h>
int STACK[100];
int EmptyStack(int front)
{
    return (front==-1);
}
int FullStack(int front)
{
    return (front==100);
}
int main()
{
    int front=-1,order,num;
    scanf("%d",&order);
    while(order!=-1)
    {
        switch(order)
        {
            case 1:{
                scanf("%d",&num);
            if(FullStack(front))
                printf("error ");
            else
            {
                STACK[++front]=num;
            }
            break;
            }
            case 0:{
            if(EmptyStack(front))
                printf("error ");
            else
            {
                printf("%d ",STACK[front--]);
            }
            break;
            }
        }
        scanf("%d",&order);
    }
    return 0;
}


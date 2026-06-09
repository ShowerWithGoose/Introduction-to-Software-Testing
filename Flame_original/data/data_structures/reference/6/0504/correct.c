#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int maxsize=100;
int main()
{
    int stack[1000];
    int pop=1;
    int size=0;
    int op=0;
    int num=0;
    while(op!=-1)
    {
        scanf("%d",&op);
        int flag=1;
        if(op==1)
        {
            if(size==100)
            {
                flag=0;
                printf("error ");
            }
            if(flag==1)
            {
                scanf("%d",&num);
                stack[pop]=num;
                pop++;
                size++;          
            }
        }
        else if(op==0)
        {
            if(size==0)
            {
                flag=0;
                printf("error ");
            }
            if(flag==1)
            {
                printf("%d ",stack[pop-1]);
                pop--;
                size--;
            }
        }
        else if(op==-1)
        {
            break;
        }
    }
    return 0;

}

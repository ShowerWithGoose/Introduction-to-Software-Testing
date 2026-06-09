#include<stdio.h>
#include<string.h>

int main()
{
    int stack[100]={0};
    int top=-1;
    int opt;
    scanf("%d",&opt);
    while(opt!=-1)
    {
        if(opt==1)
        {
            int get;
            scanf("%d",&get);
            if(top==99)
            {
                printf("error ");
            }
            else
            {
                stack[++top]=get;
            }
        }
        if(opt==0)
        {
            if(top==-1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",stack[top--]);
            }
        }
        scanf("%d",&opt);
    }
}

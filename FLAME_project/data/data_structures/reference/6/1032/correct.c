#include <stdio.h>
int max=100;
int stack[105]={0};
int vol=0;
int overflow();
int empty();
int main()
{
    
    int data,op;
    int i=0;
    while(scanf("%d",&op))
    {
        if(op==-1)
        return 0;

        if(op==1)
        {
            scanf("%d",&data);
            if(!overflow())
            {
                stack[i++]=data;
                vol++;
            }
            
        }
        else
        {
            if(!empty())
            {
                i--;
                printf("%d ",stack[i]);
                vol--;
            }
        }
    }
}

int overflow()
{
    if (vol == max-1)
    {
        printf("error ");
        return 1;
    }
    return 0;
}

int empty()
{
    if(vol==0)
    {
        printf("error ");
        return 1;
    }
    return 0;
}

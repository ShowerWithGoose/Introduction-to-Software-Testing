#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define eps 1e-10
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define arraynum(x) (sizeof(x)/sizeof(x[0]))
#define Malloc(type,size) (type *)malloc(sizeof(type)*size)
#define MAX 100
int stack[MAX];
int Top=-1;
void InitStack()
{
    Top=-1;
}
int Isempty()
{
    return Top==-1;
}
int Isfull()
{
    return Top==MAX-1;
}
int PushItem(int s[],int item)
{
    if(Top==MAX-1)
    {
        printf("Full Stack!");
        return 0;
    }
    else
    {
        Top++;
        s[Top]=item;
        return 1;
    }
}
int PopItem(int s[])
{
    if(Top==-1)
    {
        printf("Empty Stack!");
        return -1;
    }
    else
    {
        Top--;
        return s[Top+1];
    }
}
int GetItem(int s[])
{
    return s[Top];
}
int PutStack(int s[])
{
    int i=0;
    if(Top==-1)
    {
        printf("Empty Stack!");
        return 0;
    }
    for(i=0;i<=Top;i++)
    {
        printf("%d\n",s[i]);
        return 1;
    }
}

int main()
{
    int operation;
    int item;
    while(1)
    {
        scanf("%d",&operation);
        if(operation==-1) break;
        else if(operation==0)
        {
            if(Isempty()!=0)
            {
                printf("error ");
                continue;
            }
            else
            {
                printf("%d ",PopItem(stack));
            }
        }
        else if(operation==1)
        {
            scanf("%d",&item);
            if(Isfull()!=0)
            {
                printf("error ");
                continue;
            }
            else
            {
                PushItem(stack,item);
            }

        }
    }
    return 0;
}


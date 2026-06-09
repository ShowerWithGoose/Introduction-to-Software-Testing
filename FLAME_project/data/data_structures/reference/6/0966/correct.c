#include<stdio.h>
#define MAXMIM 100;
int isEmpty();
void pushStack(int w, int *p);
int isFull();
void popstack(int *p);
int Top=-1;
int num[100];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==-1)
        {
            break;
        }else if (n==0)
        {
            popstack(num);
        }else{
            int q;
            scanf("%d",&q);
            pushStack(q,num);
        }
    }
    return 0;
}
int isEmpty()
{
    return Top==-1;
}
int isFull()
{
    return Top==MAXMIM-1;
}
void pushStack(int w, int *p)
{
    if (isFull())
    {
        printf("error ");
        return;
    }
    Top++;
    *(p+Top)=w;
    return;
}
void popstack(int *p)
{
    if (isEmpty())
    {
       printf("error ");
       return;
    }
    printf("%d ",p[Top]);
    Top--;
    return;
}


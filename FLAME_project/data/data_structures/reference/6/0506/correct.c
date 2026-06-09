#include <stdio.h>
#define MAX 100

int pushStack(int *a, int top, int elem);
int popStack(int *a, int top);

int main()
{
    int a[MAX]={0};
    int top=-1, operate, elem;
    scanf("%d", &operate);
    do
    {
        if(operate==1)
        {
            scanf("%d", &elem);
            top=pushStack(a, top, elem);
        }
        else if(operate==0)
        {
            top=popStack(a, top);
        }
        scanf("%d", &operate);
    }while(operate!=-1);
    return 0;
}

int pushStack(int *a, int top, int elem)
{
    if(top==MAX-1)
    {
        printf("error ");
        return top;   //曾错 这里要return，以结束操作！
    }
    a[++top]=elem;
    return top;
}
int popStack(int *a, int top)
{
    if(top==-1)
    {
        printf("error ");
        return -1;
    }
    printf("%d ", a[top--]);
    return top;
}


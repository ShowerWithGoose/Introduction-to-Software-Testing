//判断为空是top==-1，而不是1

#include<stdio.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top=-1;

int initial();
int isempty();
int isfull();
int push(int a);
int pop();

int array[300];

int main()
{
    int n=0;
    int i=0;
    while(n!=-1)
    {
        scanf("%d",&n);
        array[i]=n;
        i++;
    }
    i=0;
    while(array[i]!=-1)
    {
        if(array[i]==1)
        {
            push(array[++i]);//读入下一个，并移动到下一位
        }
        else if(array[i]==0)
            pop();
        i++;
    }
    system("pause");
    return 0;
}

int initial()
{
    top=-1;
    return 0;
}

int isempty()
{
    return top==-1;
}

int isfull()
{
    return top==MAXSIZE-1;
}

int push(int a)
{
    if(isfull())
    {
        printf("error ");
        return -1;
    }
    else
    {
        stack[++top]=a;
        return 0;
    }
}

int pop()
{
    if(isempty())
    {
        printf("error ");
        return -1;
    }
    else
    {
        printf("%d ",stack[top]);
        top--;
        return 0;
    }
}

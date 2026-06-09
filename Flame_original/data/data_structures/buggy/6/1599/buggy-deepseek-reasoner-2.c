# include<stdio.h>
# define MAXSIZE 1000 // @@ [栈最大容量应为100，否则会错误地允许超过100个元素入栈]
int top=-1;
int Stack[MAXSIZE];
int num[201]={0};
void initStack()
{
    top=-1;
}
int isEmpty()
{
    return top==-1;
}
int  isFull()
{
    return top==MAXSIZE-1;
}
void push(int Stack[MAXSIZE],int k)
{
    if(isFull())
    {
        printf("Full Stack"); // @@ [应输出"error "以符合题目要求]
    }
    else
    {
        Stack[++top]=k;
    }
}
void pop(int Stack[MAXSIZE])
{
    if(isEmpty())
    {
        printf("error ");
    }
    else
    {
        printf("%d ",Stack[top]);
        Stack[top--];
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ [多余的输出，不符合输出格式]
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0;
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++;
        }
        if(num[i]==0)
        {
            pop(Stack);
        }
    }
    return 0;
}
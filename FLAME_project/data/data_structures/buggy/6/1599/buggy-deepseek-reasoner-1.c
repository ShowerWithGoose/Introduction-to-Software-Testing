# include<stdio.h>
# define MAXSIZE 1000
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
        printf("Full Stack"); // @@ Error: should print "error " instead of "Full Stack", and must include a space after "error".
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
    printf("hfh\n"); // @@ Error: extra output not required by the problem; should not print anything before the results.
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ Error: overwrites the terminator -1 with 0, which may cause an extra pop operation and corrupts the input data.
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
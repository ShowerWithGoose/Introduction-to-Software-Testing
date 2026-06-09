# include<stdio.h>
# define MAXSIZE 1000 // @@ [The problem specifies maximum capacity 100; using 1000 may prevent detecting stack full errors.]
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
        printf("Full Stack"); // @@ [Should output "error " with a space, not "Full Stack". This will cause output format mismatch.]
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
    printf("hfh\n"); // @@ [Extra output not allowed; will cause mismatch with expected output.]
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ [Overwrites the sentinel -1 with 0, causing an extra pop operation and incorrect processing.]
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
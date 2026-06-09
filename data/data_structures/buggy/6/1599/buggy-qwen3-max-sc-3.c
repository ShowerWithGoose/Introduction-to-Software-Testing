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
        printf("Full Stack"); // @@ [The problem requires printing "error " (with a space) for both push on full and pop on empty, but this prints "Full Stack" without a space and with different message]
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
        Stack[top--]; // @@ [This line does not actually decrement top; it should be top-- as a standalone statement or use --top in the array access. As written, it evaluates Stack[top] then decrements top but doesn't assign or use the result properly, leading to incorrect stack state]
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ [The problem does not require any extra output like "hfh", which will cause mismatch with expected output]
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ [This overwrites the -1 terminator with 0, which may convert an end marker into a pop operation, causing incorrect behavior]
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ [Incrementing loop variable inside loop body can cause skipping of next element or out-of-bounds access if not handled carefully; also, no validation that i+1 < a]
        }
        if(num[i]==0) // @@ [After incrementing i in the previous block, this condition may access num[i] where i >= a, leading to undefined behavior]
        {
            pop(Stack);
        }
    }
    return 0;
}
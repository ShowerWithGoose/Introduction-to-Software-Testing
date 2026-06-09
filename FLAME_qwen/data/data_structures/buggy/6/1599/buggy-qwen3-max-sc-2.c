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
        printf("Full Stack"); // @@ [The problem requires printing "error " (with a space) for both push on full and pop on empty, but this prints "Full Stack" without a space and wrong message]
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
        Stack[top--]; // @@ [This line does not actually decrement top; it should be top-- as a standalone statement or in the previous line. The expression Stack[top--] evaluates but doesn't change top because it's not assigned. Also, the order of operations causes undefined behavior since top is used and modified without sequence point.]
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
    num[i-1]=0; // @@ [This overwrites the -1 terminator with 0, which may convert an intended end-of-input into a pop operation, causing incorrect processing]
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ [Incrementing loop variable inside loop body can cause skipping of next element or out-of-bound access if not handled carefully, but more critically, if the last operation is a push without a following value, it may read beyond input]
        }
        if(num[i]==0) // @@ [After incrementing i in the previous if-block, this condition may check an already processed or invalid index, leading to double-processing or logic errors]
        {
            pop(Stack);
        }
    }
    return 0;
}
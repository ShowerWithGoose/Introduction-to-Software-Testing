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
        printf("Full Stack"); // @@ Error: Should output "error " instead of "Full Stack" when stack is full, as per problem specification.
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
        Stack[top--]; // @@ Error: This line does not actually decrement top; it accesses Stack[top] and then decrements top, but the expression has no effect. Should be "top--;" or "Stack[top--];" without the extra semicolon.
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ Error: This prints extra output "hfh" which is not part of the expected output format.
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ Error: This sets the last element (which is -1) to 0, incorrectly treating it as a pop operation instead of terminating the loop.
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ Error: This increments i again, skipping the next operation after a push. The loop's i++ will also execute, causing double skip.
        }
        if(num[i]==0) // @@ Error: Should be "else if" to avoid processing the same element as both a push and a pop when num[i]==1.
        {
            pop(Stack);
        }
    }
    return 0;
}
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
        printf("Full Stack"); // @@ Error: Should print "error " instead of "Full Stack" to match the problem specification.
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
        Stack[top--]; // @@ Error: This line does nothing; should be `top--;` to decrement the stack pointer.
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ Error: This extra output is not required by the problem specification.
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ Error: This incorrectly modifies the last element (the -1 sentinel) to 0, which may cause unintended pop operations.
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ Error: This extra increment skips the next operation, causing incorrect processing of the sequence.
        }
        if(num[i]==0) // @@ Error: Should be `else if` to avoid processing a 1 as a 0 after the push.
        {
            pop(Stack);
        }
    }
    return 0;
}
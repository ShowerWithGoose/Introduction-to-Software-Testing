# include<stdio.h>
# define MAXSIZE 1000 // @@ MAXSIZE should be 100 according to the problem description.
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
        printf("Full Stack"); // @@ Should output "error " as specified in the problem description.
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
        Stack[top--]; // @@ This expression statement does not correctly update the stack pointer; should be 'top--;'.
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ Unnecessary output that violates the required output format.
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ Incorrectly overwrites the termination flag -1 with 0, which is logically flawed.
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++;
        }
        if(num[i]==0) // @@ Should be 'else if' to prevent checking the incremented index as a new operation, avoiding logical errors.
        {
            pop(Stack);
        }
    }
    return 0;
}
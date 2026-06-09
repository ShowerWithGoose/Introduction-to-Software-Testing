# include<stdio.h>
# define MAXSIZE 1000 // @@ The problem specifies a maximum capacity of 100, not 1000.
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
        printf("Full Stack"); // @@ The problem requires outputting "error " (with a trailing space) when the stack is full, not "Full Stack".
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
        Stack[top--]; // @@ This statement does not properly update the stack pointer; it should be `top--;` to correctly decrement the top index after popping.
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ This prints extra output not required by the problem specification, which will cause a mismatch with the expected output.
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ This incorrectly overwrites the termination flag -1 with 0, which is logically flawed and unnecessary.
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++;
        }
        if(num[i]==0) // @@ Should be `else if(num[i]==0)` to prevent checking the pushed value as an operation command after `i` is incremented in the push block.
        {
            pop(Stack);
        }
    }
    
    return 0;
}
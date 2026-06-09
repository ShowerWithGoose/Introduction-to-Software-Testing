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
        Stack[top--]; // @@ Error: This line does not actually decrement top; it should be "top--;" or "Stack[top--];" is incorrect syntax. The intended operation is to decrement top after popping.
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ Error: This prints extra output "hfh" which is not part of the required output format.
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ Error: This sets the last element (the -1) to 0, which may cause incorrect processing of operations.
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ Error: This increments i again, skipping the next operation after a push. The loop already increments i, so this causes incorrect operation sequence.
        }
        if(num[i]==0) // @@ Error: Should use "else if" to avoid processing the same element as both a push and a pop when num[i]==1 and i is incremented incorrectly.
        {
            pop(Stack);
        }
    }
    return 0;
}
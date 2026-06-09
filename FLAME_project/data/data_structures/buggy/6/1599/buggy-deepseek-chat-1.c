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
        printf("Full Stack"); // @@ Error: Should print "error " instead of "Full Stack" to match the required output format.
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
        Stack[top--]; // @@ Error: This line does not actually decrement top; it should be "top--;" or "Stack[top--];" is incorrect syntax. The intended operation is to decrement top after printing.
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ Error: This prints extra output "hfh" which is not part of the expected output.
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ Error: This sets the last element (which is -1) to 0, incorrectly treating it as a pop operation.
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ Error: This increments i again, skipping the next operation after a push. The loop already increments i, so this causes incorrect processing.
        }
        if(num[i]==0) // @@ Error: Should be "else if" to avoid processing the same index as a pop after a push (when num[i]==1, i is incremented, but the next if still checks the original i value before increment).
        {
            pop(Stack);
        }
    }
    return 0;
}
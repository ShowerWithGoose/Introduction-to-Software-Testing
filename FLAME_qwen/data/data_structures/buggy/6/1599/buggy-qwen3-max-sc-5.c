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
        printf("Full Stack"); // @@ [The problem requires printing "error " (with a space) for both stack full and stack empty cases, but this prints "Full Stack" without a space and with wrong message.]
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
        Stack[top--]; // @@ [This line decrements top after accessing it, but the expression `Stack[top--]` does nothing useful; it should just be `top--;` or better yet, combine decrement in the previous line. However, more critically, the pop logic is correct in effect but stylistically odd. The real issue is elsewhere.]
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ [The program prints extra debug output "hfh" which is not part of expected output, causing mismatch.]
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ [This overwrites the -1 terminator with 0, which corrupts input: if the last operation before -1 was something else, this may turn it into an unintended pop. Also, the loop processes until -1, then replaces -1 with 0, so an extra pop may be executed.]
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ [Incrementing loop variable inside loop body can cause skipping or out-of-bounds access. For example, if i == a-1 and num[i]==1, then i++ leads to accessing num[i+1] = num[a], which is uninitialized (since valid indices are 0 to a-1). Also, after i++, the next if(num[i]==0) checks the pushed value as an operation, which is wrong.]
        }
        if(num[i]==0) // @@ [This should be 'else if' to avoid treating the pushed value (which is now at index i due to prior i++) as an operation code. As written, after pushing, the next integer (the value just pushed) is interpreted as an operation, leading to incorrect behavior.]
        {
            pop(Stack);
        }
    }
    return 0;
}
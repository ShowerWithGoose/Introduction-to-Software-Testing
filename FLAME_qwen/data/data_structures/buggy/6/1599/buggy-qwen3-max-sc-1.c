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
        printf("Full Stack"); // @@ [The problem requires printing "error " for both push on full and pop on empty, but this prints "Full Stack" instead of "error ".]
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
        Stack[top--]; // @@ [This line decrements top after accessing Stack[top], but the assignment `Stack[top--]` does nothing useful and is incorrect syntax for popping; it should just be `top--;` or better yet, the decrement should happen in the expression that uses the value. However, the bigger issue is that the pop logic already printed the value, so this line is redundant and malformed. But more critically, the main logic error is below.]
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ [The problem does not require any extra output like "hfh", which will cause the output to be wrong.]
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ [This overwrites the -1 terminator with 0, which corrupts the input sequence. The loop condition in processing later uses `a = i-1`, but this change causes the last operation before -1 to be lost or misinterpreted. Specifically, if the input ends with -1, this replaces -1 with 0, turning the end marker into a pop operation.]
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ [Incrementing loop variable inside the loop can cause skipping or out-of-bounds access. Also, if the last element is a 1 (push), then num[i+1] may be beyond the valid data because the original -1 was replaced by 0, and the array might not have a following number.]
        }
        if(num[i]==0) // @@ [This should be 'else if' to avoid checking again after a push. As written, after handling a push (and incrementing i), it checks num[i] again which is now the pushed value (not an operation), leading to unintended behavior. For example, if input is "1 5 0 -1", after pushing 5, i becomes index of 5, then this condition checks if 5==0, which is false, so it's okay in that case. But if the pushed value were 0, it would incorrectly trigger a pop. However, the problem states pushed integers are not 1, 0, or -1, so maybe safe? Still, logically flawed structure.]
        {
            pop(Stack);
        }
    }
    return 0;
}
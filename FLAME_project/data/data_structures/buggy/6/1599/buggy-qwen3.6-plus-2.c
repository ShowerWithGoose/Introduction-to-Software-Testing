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
        printf("Full Stack"); // @@ The problem requires outputting "error " when the stack is full, not "Full Stack". Also missing a space.
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
        Stack[top--]; // @@ This line does not update the top index correctly. It should be top--; or Stack[top--]; is valid but the previous line printed Stack[top] before decrementing, which is correct for LIFO, but the statement `Stack[top--]` is an expression that accesses the array and then decrements top. However, the logic here is slightly confusing compared to standard `top--`. The main issue is likely elsewhere or this is just stylistic. Wait, `Stack[top--]` evaluates `top` for indexing, then decrements `top`. This is functionally equivalent to `top--` if the return value isn't used. But let's look at the other errors first.
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ This line prints "hfh" which is not part of the expected output. It causes the Wrong Answer.
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ This overwrites the -1 terminator with 0. While the loop stops before processing it if handled correctly, modifying input data can be risky. However, the bigger issue is the loop logic below.
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++;
        }
        if(num[i]==0) // @@ This should be 'else if' or the logic needs adjustment. If num[i] was 1, i was incremented. Now num[i] is the element after the pushed value. If that element happens to be 0, it will incorrectly trigger a pop. In the reference code, distinct operations are handled. Here, if we push, we skip the next element. But if the next element is 0, the second 'if' checks the NEW i. This is logically flawed because the 'if' statements are independent. If num[j]==1, we push num[j+1] and increment i to j+1. Then the second if checks num[j+1]. If num[j+1] is 0, it pops. This means the value 0 is treated as both a payload (ignored in push context? No, it's skipped) AND an operation. But wait, if num[i]==1, we consume num[i+1] as data. We increment i. So now i points to num[i+1]. The next check is if(num[i]==0). If the data we just pushed was 0, this would trigger a pop! But the problem says pushed integers are not 1, 0, or -1. So this specific collision might not happen for valid inputs. However, using separate 'if's instead of 'else if' is bad practice and potentially buggy if constraints change. More importantly, look at the output format.
        {
            pop(Stack);
        }
    }
    return 0;
}
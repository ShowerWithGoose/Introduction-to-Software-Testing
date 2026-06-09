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
        printf("Full Stack"); // @@ [The problem requires printing "error " for both stack full and stack empty cases, but this prints "Full Stack" instead of "error ".]
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
        Stack[top--]; // @@ [This line decrements top after accessing it, but the expression `Stack[top--]` does nothing useful. It should be just `top--;` or better yet, combine decrement in the previous line like `printf("%d ", Stack[top--]);`. However, the current code prints the correct value but fails to actually pop because the assignment is missing; but more critically, the order of operations here is misleading. The real issue is that the pop logic is split: print then do a useless assignment. It should be `top--;` alone, but even better to use `top--` in the print statement. However, the main error causing wrong output is the missing space or incorrect error message in push. But note: the bigger logical flaw is below in main loop handling.]
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ [The problem does not require any extra output like "hfh", which will cause the output to be incorrect. This debug print must be removed.]
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ [This overwrites the -1 terminator with 0, which corrupts the input sequence. For example, if input ends with -1, this changes it to 0, causing an unintended extra pop operation.]
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ [Incrementing loop variable inside the loop can cause skipping or double processing. More critically, if the last element is a 1 (push) without a following number (though problem guarantees valid input), it could go out of bounds. But the main issue is interaction with the next if: after i++, the next if checks num[i] which is the pushed value, possibly causing unintended pop if that value is 0.]
        }
        if(num[i]==0) // @@ [This should be 'else if' to avoid checking the same index again after a push. As written, after pushing and incrementing i, this condition checks the next element (the pushed value) and if it's 0, it pops immediately, which is wrong. For example, input "1 0 0 -1" would push 0, then because i is incremented to point to the 0 (the pushed value), this if triggers a pop — which is incorrect because the second 0 is a separate operation.]
        {
            pop(Stack);
        }
    }
    return 0;
}
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
        printf("Full Stack"); // @@ [The problem requires printing "error " (with a space) for both push on full and pop on empty, but this prints "Full Stack" instead of "error ".]
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
        Stack[top--]; // @@ [This line does not actually decrement 'top' correctly. It should be 'top--;' as a separate statement or use '--top' in the array access. As written, 'Stack[top--];' has no effect because the value is not used, and 'top' is decremented after being used—but since it's a standalone expression, it's equivalent to just 'top--;'. However, the bigger issue is that the printed value uses 'Stack[top]' before decrement, which is correct, but the unnecessary assignment to Stack[top--] is redundant and misleading. However, the real critical error is elsewhere.]
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ [The program prints extra debug output "hfh", which is not part of the expected output and will cause mismatch.]
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ [This overwrites the -1 terminator with 0, which corrupts the input sequence. The loop condition stops when m==-1, so num[i-1] is -1. Setting it to 0 turns the last operation into a pop, which is incorrect.]
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ [Incrementing loop variable 'i' inside the loop causes skipping of the next element. However, this is actually necessary to skip the pushed value, BUT combined with the for-loop's own increment, it skips two positions. This leads to incorrect parsing. For example, input "1 5 0 -1" becomes num = [1,5,0,-1], then after reading 1 at i=0, i becomes 1, then for-loop increments to 2, so 0 is processed. That seems okay, but the earlier overwrite of -1 breaks termination.]
        }
        if(num[i]==0) // @@ [After the 'i++' in the push block, this 'if' may access num[i] where i is beyond intended, especially if the last operation was a push. Also, using two separate 'if's (not else-if) means that after processing a push and incrementing i, the new num[i] might be 0 and get processed again in the same iteration, causing double-processing.]
        {
            pop(Stack);
        }
    }
    return 0;
}
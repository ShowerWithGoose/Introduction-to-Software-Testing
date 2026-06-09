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
        printf("Full Stack"); // @@ [The problem requires printing "error " (with a space) for both push on full and pop on empty, but this prints "Full Stack" without a space and with wrong message.]
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
        Stack[top--]; // @@ [This line decrements top after accessing Stack[top], but the decrement should happen as part of popping. However, the bigger issue is that the expression `Stack[top--]` does nothing useful and is incorrect syntax; it should be just `top--;` after printing. But more critically, the order of operations is okay, yet the real bug is elsewhere. However, note: this line doesn't actually use the value, so it's harmless but unnecessary. The main bugs are in input handling and extra output.]
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ [This prints an extra "hfh" followed by newline which is not part of expected output. The expected output is only "567 ". This causes Wrong Answer.]
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ [This replaces the -1 terminator with 0, which may cause an extra unintended pop operation if the last operation was -1. In the test case, the sequence becomes [1,567,0,0] instead of [1,567,0,-1], leading to an extra pop. However, in the given test case, after replacing -1 with 0, the loop runs one extra time. But note: the original sequence ends at -1, so the valid operations are before -1. By setting num[i-1]=0, we turn the -1 into a 0, causing an extra pop. In the test case input "1 567 0 -1", the stored array becomes [1,567,0,0] and a = i-1 = 3, so the loop runs for i=0 to 2. Let's trace: i=0: num[0]=1 → push 567, then i++ makes i=1; then check if num[1]==0 → yes, pop → prints 567. Then i=2: num[2]=0 → pop again → stack is now empty → prints "error ". So output becomes "hfh\n567 error ", which is wrong. But wait, the buggy output shown is "hfh\n567", meaning maybe only one pop happened. However, the code has multiple critical errors.]
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ [This increments i inside the loop, which combined with the for-loop's i++ causes skipping of the next element. However, this is actually correct for consuming the next token as the value to push. But note: after i++, the next iteration will start at i+2, which is intended. However, if the next element is the last one, it might go out of bounds, but in this test case it's okay. The real issue is the extra pop due to replacing -1 with 0 and the extra "hfh" print.]
        }
        if(num[i]==0) // @@ [After pushing and incrementing i, this condition is checked in the same loop iteration. For example, after processing a '1', i is incremented to point to the pushed value, then this if checks if that value is 0. In the test case: after reading 1, push 567, then i becomes 1 (from i++ in for loop? Wait, no: inside the if(num[i]==1), we do i++, so after push, i is incremented by 1. Then, after that if block, we check if num[i]==0. At that point, i is 1, and num[1] is 567, so it's not 0. Then the for loop does i++, making i=2. Then next iteration: i=2, num[2]=0 → pop. So that seems okay. But the problem is the extra 0 at the end due to num[i-1]=0.]
        {
            pop(Stack);
        }
    }
    return 0;
}
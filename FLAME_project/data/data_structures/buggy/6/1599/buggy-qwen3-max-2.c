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
        printf("Full Stack"); // @@ [The problem requires printing "error " (with a space) for both stack full and stack empty cases, but this prints "Full Stack" without a space and with different text.]
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
        Stack[top--]; // @@ [This line decrements top after accessing it, but the assignment `Stack[top--]` does nothing useful and is incorrect syntax for popping; it should just be `top--;`. However, more critically, the pop logic is correct in effect but the extra debug print in main causes wrong output.]
    }
}
int main()
{
    int m,i=0,j,a;
    printf("hfh\n"); // @@ [This debug print statement outputs "hfh" followed by a newline, which is not part of the expected output and directly causes the wrong answer.]
    do
    {
        scanf("%d",&m);
        num[i]=m;
        i++;
    }while (m!=-1);
    num[i-1]=0; // @@ [This overwrites the -1 terminator with 0, which may cause an extra unintended pop operation if the last operation was -1. However, in the given test case, this turns -1 into 0, leading to an extra pop. But in the test input "1 567 0 -1", after reading -1, i=4, then num[3]=0, so operations become [1,567,0,0]. This causes two pops: one valid (567), one on empty stack -> "error ". But expected output is only "567 ". However, the actual buggy output shown is "hfh\n567", meaning maybe the second pop didn't happen due to loop condition. Let's check loop: a = i-1 = 3, loop i from 0 to 2. So operations processed: num[0]=1 -> push 567, i becomes 1; then next iteration i=2: num[2]=0 -> pop -> prints "567 ". Then loop ends. So why overwrite -1 to 0? It doesn't affect this test case because loop stops before that index. But the real issue is the "hfh\n" print.]
    a=i-1;
    for(i=0;i<a;i++)
    {
        if(num[i]==1)
        {
            push(Stack,num[i+1]);
            i++; // @@ [This skips the next element (the pushed value) correctly, but if the array ends with 1, it could go out of bounds. Not the issue in this test case.]
        }
        if(num[i]==0) // @@ [After incrementing i in the push block, this condition may re-check the same index or skip logic. For example, after pushing, i is incremented, then this if checks the new i. In test case: after processing i=0 (push), i becomes 1, then this if checks num[1]==567 -> false. Then next loop i=2: num[2]==0 -> pop. So it works for this case. But using two separate ifs instead of else-if can cause issues if an element is both 1 and 0 (impossible) or if after incrementing i, num[i] becomes 0 in same iteration. However, in this specific test case, it's okay. The main errors are the "hfh\n" print and the "Full Stack" message.]
        {
            pop(Stack);
        }
    }
    return 0;
}
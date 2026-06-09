#include<stdio.h>
int top=-1;
int stack[200]={0};

int isEmpty(int s[])
{
    return top==-1;
}

int isFull(int s[])
{
    return top==199;
}

void push(int stack[],int item)
{
    if(isFull(stack))
        Error11("error"); // @@ [The function 'Error11' is called before it is declared or defined, which may cause a compilation error in strict C standards (implicit function declaration). Additionally, the problem requires outputting "error " (with a space), but this call passes "error" without space; however, Error11 appends a space, so that part is okay. The main issue is function ordering.]
    else 
        stack[++top]=item;
}
void Error11(char s[])
{
    printf("%s ",s);
}
int pop(int s[])
{
    if(isEmpty(s))
        Error11("error"); // @@ [Same as above: 'Error11' is used before definition if compiler doesn't allow implicit declarations. Also, when stack is empty, this prints "error ", which is correct per problem, but the bigger issue is that the pop function returns an undefined value (no return statement in the error case), leading to undefined behavior when the returned value is printed in main.]
    else 
        return s[top--];
}
int main()
{
    int a,b,ans;
    while(~scanf("%d",&a))
    {
        if(a==-1)
        {
            break;
        }
        else if(a==1)
        {
            scanf("%d",&b);
            push(stack,b);
        }
        else if(a==0)
        {
            printf("%d ",ans=pop(stack)); // @@ [When pop() is called on an empty stack, it prints "error " via Error11, but still returns an undefined value (since no return in error branch), which is then printed as "%d ". This results in printing "error <garbage> " instead of just "error ". The problem requires only "error " to be printed for invalid pop, not an additional number.]
        }
    }
}
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top=-1;
void push(int  s[],int item)
{
    if(top==MAXSIZE-1)
        printf("error ");
    else
        s[++top]=item;
}
void pop(int s[])
{
    if(top==-1)
        printf("error ");
    else
        printf("%d ",s[top--]);
}

int main()
{
    while(12315)
  {
    int flag;
    scanf("%d",&flag);
    if(flag==0)
    {
        pop(stack);
    }
    else if(flag==1)
    {
        int a;
        scanf("%d",&a);
        push(stack,a);
    }
    else if(flag==-1)
        break;
  }
  return 0;
}


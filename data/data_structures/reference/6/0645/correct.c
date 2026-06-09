#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include<alloca.h>

#define N 100
int stack[N];
int top;
void push(int x);
void pop(void);
int main()
{
    int n;
    top=-1;
    while(1)
    {
        scanf("%d",&n);
        if(n==1)
        {
            int x; scanf("%d",&x); push(x);
        }
        else if(n==0) pop();
        else if(n==-1) break;
    }
    return 0;
}

void push(int x)
{
    if(top==N-1) { printf("error "); return; }
    stack[++top]=x;
    return;
}

void pop(void)
{
    if(top==-1) { printf("error "); return; }
    printf("%d ",stack[top--]);
}

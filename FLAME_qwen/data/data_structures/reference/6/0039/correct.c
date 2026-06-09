#include <stdio.h>
#include <stdlib.h>

int  k[1000];
int top = -1;
void push(int num)
{
    if(top ==999)
        printf("error ");
    else
        k[++top] = num;
}

void pop()
{
    if(top == -1)
        printf("error ");
    else
        printf("%d ",k[top--]);
}
void push(int n);
void pop();

int main()
{
    int a, b;
    while(1)
    {
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                scanf("%d",&b);
                push(b);
                break;
            case 0:
                pop();
                break;
            case -1:
                return 0;
        }
    }
}






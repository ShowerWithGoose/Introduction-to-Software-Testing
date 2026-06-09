#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXLINE 100
//1表示入栈操作，后跟一个整数（不为1、0和-1)为
//入栈元素；0表示出栈操作；-1表示操作结束。
int top = -1;
int STACK[100];

int isfull()
{
    if(top==MAXLINE-1)
        return 1;
    else return 0;
}

int isempty()
{
    if(top==-1)
        return 1;
    else return 0;
}

int main()
{
    int op;
    int flag = 0;
    while(1)
    {
        scanf("%d",&op);
        switch(op)
        {
            case -1:
                flag = 1;
                break;
            case 0:
                if(isempty(STACK))
                    printf("error ");
                else
                    printf("%d ",STACK[top--]);
                break;
            case 1:
                if(isfull(STACK))
                    printf("error ");
                else
                    scanf("%d",&STACK[++top]);
                break;
        }
        if(flag) break;
    }
}

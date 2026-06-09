#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define MAX 100
int s[MAX];
int top;
int flag=0;
void init()
{
    top=-1;
}
int stackempty()
{
    return top==-1;
}
int stackfull()
 {
     return top==(MAX-1);
 }
int push(int s[],int e)
{
    if(stackfull()){
        printf("error ");
    }
    else{
        s[++top]=e;
    }
}
int pop(int s[])
{
    if(stackempty()){
        printf("error ");
        flag=1;
    }
    else{
        return s[top--];
}
}
int main()
{
    int in,act,a;
    scanf("%d",&in);
    init();
    while(in!=-1)
    {

        flag=0;
        if(in==1)
        {
            scanf("%d",&act);
            push(s,act);
        }
        else if(in==0)
        {
            a=pop(s);
            if(flag==0)
            printf("%d ",a);
        }
               scanf("%d",&in);
    }
    return 0;
}


#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a,item,s[1000],top=-1;
void push(int s[],int item)
{
    if(top==1000-1)
        printf("error");
    else
        s[++top]=item;
}
void pop(int s[])
{
    if(top==-1)
        printf("error");
    else
        printf("%d ",s[top--]); // @@ The expected output requires a space after each popped element. The original code missed the space in the format string, causing numbers to be concatenated.
}
int main()
{
    while(scanf("%d",&a)!=EOF)
    {
        if(a==-1)
            break;

        if(a==1)
        {
            scanf("%d",&item);
            push(s,item);
        }
        if(a==0)
        {
            pop(s);
        }

    }

return 0;


}
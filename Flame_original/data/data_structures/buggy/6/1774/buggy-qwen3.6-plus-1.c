#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a,item,s[1000],top=-1; // @@ Array size should be 100 to match the problem's maximum capacity constraint.
void push(int s[],int item)
{
    if(top==1000-1) // @@ Should check if top == 99 since the maximum stack capacity is 100.
        printf("error"); // @@ Missing trailing space; the output format requires "error " followed by a space.
    else
        s[++top]=item;
}
void pop(int s[])
{
    if(top==-1)
        printf("error"); // @@ Missing trailing space; the output format requires "error " followed by a space.
    else
        printf("%d",s[top--]); // @@ Missing trailing space after the number; the output format requires a space after each popped element.
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
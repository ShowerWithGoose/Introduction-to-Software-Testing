#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a,item,s[1000],top=-1;
void push(int s[],int item)
{
    if(top==1000-1)
        printf("error"); // @@ missing space after "error" (should be "error ")
    else
        s[++top]=item;
}
void pop(int s[])
{
    if(top==-1)
        printf("error"); // @@ missing space after "error" (should be "error ")
    else
        printf("%d",s[top--]); // @@ missing space after %d (should be "%d ")
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
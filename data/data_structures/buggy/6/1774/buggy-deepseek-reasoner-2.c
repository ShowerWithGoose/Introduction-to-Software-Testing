#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a,item,s[1000],top=-1; // @@ array size should be 100 to match max capacity
void push(int s[],int item)
{
    if(top==1000-1) // @@ should check top==99 (capacity 100)
        printf("error"); // @@ should print "error " with space
    else
        s[++top]=item;
}
void pop(int s[])
{
    if(top==-1)
        printf("error"); // @@ should print "error " with space
    else
        printf("%d",s[top--]); // @@ should print "%d " with space after number
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
#include <stdio.h>
#include<stdio.h> // @@ [duplicate include of stdio.h is unnecessary but not a compilation error; however, the real issue is missing space after "error" and incorrect stack size]
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a,item,s[1000],top=-1; // @@ [stack size should be 100 as per problem description, not 1000]
void push(int s[],int item)
{
    if(top==1000-1) // @@ [should check against 99 (for size 100), not 999; also, problem requires space after "error"]
        printf("error"); // @@ [missing space after "error" as required by output format]
    else
        s[++top]=item;
}
void pop(int s[])
{
    if(top==-1)
        printf("error"); // @@ [missing space after "error" as required by output format]
    else
        printf("%d",s[top--]); // @@ [missing space after printed number as required by output format]
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
#include <stdio.h>
#include<stdio.h> // @@ [Duplicate header inclusion; while not a compilation error by itself, it's redundant and may indicate poor code hygiene, but the real issue is missing space after "error" and incorrect stack size]
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a,item,s[1000],top=-1; // @@ [Stack size should be 100 as per problem description, not 1000]
void push(int s[],int item)
{
    if(top==1000-1) // @@ [Should check against capacity 99 (for size 100), not 999 (for size 1000)]
        printf("error"); // @@ [Missing space after "error" as required by output format]
    else
        s[++top]=item;
}
void pop(int s[])
{
    if(top==-1)
        printf("error"); // @@ [Missing space after "error" as required by output format]
    else
        printf("%d",s[top--]); // @@ [Missing space after printed number as required by output format]
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
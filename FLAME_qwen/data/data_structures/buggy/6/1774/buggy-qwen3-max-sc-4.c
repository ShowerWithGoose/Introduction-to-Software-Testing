#include <stdio.h>
#include<stdio.h> // @@ [duplicate include; not a compilation error but redundant]
#include<string.h> // @@ [unused header; not a compilation error but unnecessary]
#include<stdlib.h> // @@ [unused header; not a compilation error but unnecessary]
#include<math.h> // @@ [unused header; not a compilation error but unnecessary]
int a,item,s[1000],top=-1; // @@ [stack size is 1000, but problem states max capacity is 100]
void push(int s[],int item)
{
    if(top==1000-1) // @@ [should be 99 for capacity 100; using 1000-1 implies capacity 1000]
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
        if(a==0) // @@ [should be 'else if' to avoid unintended fall-through (though logically okay here, style issue)]
        {
            pop(s);
        }

    }

return 0; // @@ [missing newline before closing brace may cause formatting warning but not compilation error]


}
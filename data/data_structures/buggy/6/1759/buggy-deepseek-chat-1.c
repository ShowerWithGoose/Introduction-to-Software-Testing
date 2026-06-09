#define MAXN 110
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <string.h>
int st[MAXN]={},len=0;
int opt;
int main()
{
    while(scanf("%d",&opt))
    {
        switch(opt)
        {
            case -1 : 
            {
                return 0;
            }
            case 0 :
            {
                if(!len)
                {
                    printf("error ");
                    break ;
                }
                printf("%d ",st[--len]); // @@ [Error: The pop operation should output st[len-1] before decrementing, but here it decrements len first, so it outputs the wrong element. It should be st[--len] changed to st[len-1] followed by len--, or use st[--len] only if the stack is 0-indexed and len points to the next empty slot, which is correct for this implementation, but the problem expects the popped element to be the top of the stack. However, the reference program uses s[top--] where top is the index of the top element, so this is actually correct if len is the number of elements. But note: the reference program initializes top = -1 and uses s[++top] = n for push, so top is the index of the top element. Here, len starts at 0 and st[len++] = value for push, so len is the number of elements, and the top element is at st[len-1]. So st[--len] correctly outputs the top element and decrements len. This line is actually correct. The error is elsewhere.]
                break ;
            }
            case 1 :
            {
                scanf("%d",st[len++]); // @@ [Error: This line does not check if the stack is full (len >= MAXN). According to the problem, if a push operation is attempted when the stack is full, output "error ". Also, scanf should use &st[len] before incrementing, but here it uses st[len++] which is incorrect because it passes the value of st[len] (which is uninitialized) and then increments len. It should be scanf("%d", &st[len]); len++; or scanf("%d", st+len); len++;. Additionally, there is no check for stack overflow.]
                break ;
            }
        }
    }
    return 0;
}
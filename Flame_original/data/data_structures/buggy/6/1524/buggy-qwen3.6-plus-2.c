#include<stdio.h>
#include<stdlib.h>
struct Zhan{
    int top;
    int date[150];
};
int main()
{
    typedef struct Zhan z;
    z zhan;
    zhan.top=0;
    int n;
    int a;
    while(~scanf("%d",&n))
    {
        if(n==1)
        {
            if(zhan.top+1>100)//му│Ш  // @@ When the stack is full, the program prints "error " but fails to consume the integer to be pushed. This causes the input stream to become misaligned, as the next scanf will read the push value as an operation code.
            {
                printf("error ");
            }else
            {
                scanf("%d",&a);
                zhan.top++;
                zhan.date[zhan.top]=a;
            }
        }
        if(n==0)
        {
            if(zhan.top<1)
            {
                printf("error ");
            }else
            {
                printf("%d",zhan.date[zhan.top]); // @@ Missing a space after %d. The problem specification requires that each popped element be followed by a space, including the last one.
                zhan.top--;
            }
        }
        if(n==-1)
        {
            break;
        }
    }
    return 0;
}
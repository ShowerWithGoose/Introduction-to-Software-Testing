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
            if(zhan.top+1>100)//му│Ш 
            {
                printf("error ");
            }else
            {
                scanf("%d",&a);
                zhan.top++;
                zhan.date[zhan.top]=a; @@ [The push operation stores the new element at index `zhan.top` after incrementing, but the stack should store at the current top index before incrementing. This causes the first element to be stored at index 1 instead of 0, leading to incorrect pop behavior and potential out-of-bounds access.]
            }
        }
        if(n==0)
        {
            if(zhan.top<1)
            {
                printf("error ");
            }else
            {
                printf("%d",zhan.date[zhan.top]); @@ [When popping, it prints `zhan.date[zhan.top]`, but since `top` points to the next available slot (due to increment-before-store), the actual top element is at `zhan.top - 1`. This results in printing uninitialized or wrong data. Also, missing space after %d as per output format.]
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
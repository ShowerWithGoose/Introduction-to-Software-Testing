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
                zhan.date[zhan.top]=a; // @@ [The push operation stores the new element at index `zhan.top` after incrementing, which skips index 0 and causes off-by-one error. It should assign before incrementing or use `zhan.date[zhan.top++] = a;` correctly aligned with initial top=0.]
            }
        }
        if(n==0)
        {
            if(zhan.top<1)
            {
                printf("error ");
            }else
            {
                printf("%d",zhan.date[zhan.top]); // @@ [When popping, it prints `zhan.date[zhan.top]`, but since `top` points to the next empty slot (due to post-increment in push), the top element is actually at `zhan.top - 1`. This leads to printing uninitialized/garbage value or wrong element. Also missing space after %d as per output format.]
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
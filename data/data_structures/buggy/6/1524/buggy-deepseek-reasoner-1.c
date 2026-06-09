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
            if(zhan.top+1>100)//му│Ш @@ [The comment contains non-ASCII characters that may cause compilation warnings or errors on some compilers, especially if warnings are treated as errors.]
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
                printf("%d",zhan.date[zhan.top]); // @@ [Missing space after the popped integer; should be "%d " to match the required output format.]
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
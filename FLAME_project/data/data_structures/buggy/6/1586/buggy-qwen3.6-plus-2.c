#include<stdio.h>
typedef struct haha
{
    int x;
    int y[1000];
}haha;
int main()
{
    haha s;
    int q=0;
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        if(a==1)
        {
            printf("%d",&s.y[q]); // @@ [Error 1: The code prints the address of the array element instead of reading an input value to push. It should use scanf to read the value to be pushed. Error 2: It prints garbage/uninitialized memory or address, contributing to wrong output.]
            q++;
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error");
            }
            else
            {
                printf("%d ",s.y[--q]);
            }
            
        }
        else if(a==-1)
            {
                break;
            }
    }
    return 0;
}
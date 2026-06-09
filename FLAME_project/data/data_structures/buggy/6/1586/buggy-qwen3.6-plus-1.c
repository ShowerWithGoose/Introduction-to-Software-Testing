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
            printf("%d",&s.y[q]); // @@ [Error 1: The code attempts to print the address of the array element instead of reading an integer input. It should use scanf to read the value to be pushed. Error 2: It prints garbage or address instead of storing the value.]
            q++;
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error"); // @@ [Error 3: The problem requires "error " (with a trailing space), but this prints "error" without a space. Also, it doesn't handle the space separation correctly for subsequent outputs.]
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
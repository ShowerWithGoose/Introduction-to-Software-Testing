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
        if(a==1) // @@ Missing check for stack full condition (q == 100) before pushing, which should output "error ".
        {
            printf("%d",&s.y[q]); // @@ Incorrectly uses printf instead of scanf to read the integer to push; also incorrectly passes an address to %d.
            q++;
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error"); // @@ Missing a trailing space after "error" as required by the output format.
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
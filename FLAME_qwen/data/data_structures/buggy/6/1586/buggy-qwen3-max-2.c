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
            printf("%d",&s.y[q]); @@ [Incorrectly prints the address of s.y[q] instead of reading an integer to push; also missing check for stack full condition (max capacity 100)]
            q++;
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error"); @@ [Missing space after "error" as required by output format]
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
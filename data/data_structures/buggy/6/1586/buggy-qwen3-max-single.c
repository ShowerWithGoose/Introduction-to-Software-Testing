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
            printf("%d",&s.y[q]); @@ [Incorrectly prints address of array element instead of reading input value; should use scanf to read the value to push, not printf]
            q++;
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error "); @@ [Missing space after "error" to match expected output format which requires a space after every output token including "error"]
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
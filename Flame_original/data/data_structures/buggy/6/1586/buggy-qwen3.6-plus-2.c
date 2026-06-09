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
            printf("%d",&s.y[q]); // @@ [Should use scanf("%d", &s.y[q]) to read the integer to push onto the stack, not printf; also missing check for stack full (max capacity 100)]
            q++;
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error"); // @@ [Missing trailing space after "error" as specified in the output format]
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
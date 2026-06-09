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
            printf("%d",&s.y[q]); // @@ [Error: This line prints the address of s.y[q] instead of the value. It should be printf("%d ", s.y[q]); to store and later output the pushed value. Also missing space after output.]
            q++;
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error"); // @@ [Error: Missing space after "error" as required by the problem description. Should be printf("error ");]
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
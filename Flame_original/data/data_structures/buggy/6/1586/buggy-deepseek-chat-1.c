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
            printf("%d",&s.y[q]); // @@ [Error: Should use scanf to read the value to push, not printf. Also, &s.y[q] is the address, not the value. Should be: scanf("%d", &s.y[q]);]
            q++;
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error"); // @@ [Error: Missing space after "error" as required by output format. Should be: printf("error ");]
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
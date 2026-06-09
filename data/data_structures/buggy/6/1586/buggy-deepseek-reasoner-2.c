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
            printf("%d",&s.y[q]); // @@ [Error: Should be scanf to read the value to push, not printf. Also missing stack full check.]
            q++;
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error"); // @@ [Error: Missing trailing space; expected "error " as per problem specification.]
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
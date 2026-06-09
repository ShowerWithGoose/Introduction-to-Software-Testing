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
            printf("%d",&s.y[q]); // @@ [This prints the address of s.y[q] instead of reading and storing the next integer. It should read an integer using scanf and push it onto the stack.]
            q++;
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error "); // @@ [Missing space after "error" in original expected output format; however, more critically, the push logic is broken so this may not be the main issue. The primary bug is in the push handling.]
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
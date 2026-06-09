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
            printf("%d",&s.y[q]); // @@ This line prints the address of s.y[q] instead of storing the input value. Also, the program does not read the integer to push after the operation code 1, so the value '567' is not captured. The push operation should read the next integer and store it in s.y[q] without printing.
            q++;
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error"); // @@ The program should output "error " (with a trailing space) when a pop is attempted on an empty stack, but it outputs "error" without space.
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
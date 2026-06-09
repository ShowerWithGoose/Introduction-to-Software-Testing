#include<stdio.h>
int a[100]={0};
int main()
{
    int x,i=0;
    scanf("%d",&x);
    while(x!=-1)
    {
        if(x==1)
        {
            scanf("%d",&x);
            if(i==99)
            {
                printf("error ");
            }
            else
            {
                a[i]=x;
                i++;
            }
        }
        else
        {
            if(i==0)
            {
                printf("error ");
            }
            else
            {
                i--; // @@ The original code `a[i]=0; i--;` incorrectly modifies the stack content and then decrements. It should only decrement `i` to pop the element. More importantly, it fails to print the popped element.
                printf("%d ", a[i]); // @@ Missing output of the popped element. The problem requires outputting the sequence of elements popped from the stack.
            }
        }
        scanf("%d",&x);
    }
    return 0;
}
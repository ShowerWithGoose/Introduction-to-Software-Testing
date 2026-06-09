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
            scanf("%d",&x); // @@ This overwrites the operation code x with the pushed value, causing the loop to misinterpret the next operation.
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
                a[i]=0; // @@ This line is unnecessary and does not actually pop the element; it only sets the current top to 0 without decrementing i properly.
                i--;
            }
        }
        scanf("%d",&x);
    }
    return 0;
}
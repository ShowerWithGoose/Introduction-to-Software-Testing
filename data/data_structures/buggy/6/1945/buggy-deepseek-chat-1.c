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
            scanf("%d",&x); // @@ [Error: This line overwrites the operation code x with the pushed value, causing the loop to misinterpret the next operation. The pushed value should be stored in a separate variable.]
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
                a[i]=0; // @@ [Error: Setting a[i] to 0 is unnecessary and incorrect; the pop operation should only decrement i, not modify the array.]
                i--;
            }
        }
        scanf("%d",&x);
    }
    return 0;
}
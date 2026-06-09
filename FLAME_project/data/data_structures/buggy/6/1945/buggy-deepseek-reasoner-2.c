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
            if(i==99) // @@ should be if(i==100) because array size is 100, when i==100 stack is full
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
                a[i]=0; // @@ missing printf of popped element; should output a[i-1] before decrement
                i--;
            }
        }
        scanf("%d",&x);
    }
    return 0;
}
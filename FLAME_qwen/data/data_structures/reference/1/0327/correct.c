#include <stdio.h>
int a[11],book[11],cnt=0;
void fun(int b,int z)
{
    if(z==b)
    {
        for(int i=1;i<=b;i++)
        {
            if(book[i]==0)
            {
                a[z]=i;
            }
        }
        for(int i=1;i<b;i++)
        printf("%d ",a[i]);
        printf("%d\n",a[b]);
    }    
    else
    {
        for(int i=1;i<=b;i++)
        {
            if(book[i]==0)
            {
                a[z]=i;
                book[i]=1;
                fun(b,z+1);
                book[i]=0;
            }
        }
    }
}
int main()
{
    int x;
    scanf("%d",&x);
    fun(x,1);
    return 0;
}

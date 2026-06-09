#include <stdio.h>
int num[9];
int repeat(int a[],int n)
{
    int i,j;
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<n+1; j++)
        {
            if(a[i]==a[j])
            {
                return 1;
            }
        }
    }
    return 0;
}
void pl(int pt,int n)
{
    int i;
    if(pt>n)
    {
        if(repeat(num,n)==0)
        {
            for(i=1; i<=n; ++i)
            {
                printf("%d",num[i]);
            }
            printf("\n");
        }
    }
    else
    {
        for(i=1; i<=n; ++i)
        {
            num[pt]=i;
            pl(pt+1,n);
        }
    }
}
 
int main()
{
	int n;
    scanf("%d",&n);
    pl(1,n);
    return 0;
}



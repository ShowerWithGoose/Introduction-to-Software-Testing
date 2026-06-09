#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int a[11],b[11],s[11];
int f(int k,int n)
{
    int p,q;
    if(k==n)
        {for( q=0;q<n;q++)
            printf("%d ",b[q]);
        printf("\n");
    }
    else
    {
        for(p=0;p<n;p++)
        {
            if(s[p]==0)
            {
                b[k]=a[p];
                s[p]=1;
                f(k+1,n);
                s[p]=0;
            }
        }
    }

}
int main()
{
    int n,i,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        a[i]=i+1;
    k=0;
    f(k,n);
    return 0;
}


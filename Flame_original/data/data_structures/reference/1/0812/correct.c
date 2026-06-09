#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include <ctype.h>
int a[15],medium;

int main()
{
    int n,i,factorial=1,cnt,j,k,m;
    int max=11;
    int ans,p,q;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        a[i]=i;
        factorial*=i;
        printf("%d%c",a[i],i==n?10:32);
    }
    cnt=factorial-1;
    while(cnt--)
    {
        for(i=n;i>1;i--)
        {
            if(a[i-1]<a[i])
            {
                j=i-1;
                for(m=j+1;m<=n;m++)
                {
                    if(a[m]<max&&a[m]>a[j])
                    {
                        max=a[m];
                        k=m;
                    }
                }
                max=11;
                break;
            }
        }

        medium=a[j];
        a[j]=a[k];
        a[k]=medium;

        for(q=j+1,p=n;q<p;q++,p--)
        {
            ans=a[q];
            a[q]=a[p];
            a[p]=ans;
        }

        for(i=1;i<=n;i++)
        {
          printf("%d%c",a[i],i==n?10:32);
        }

    }


    return 0;
}


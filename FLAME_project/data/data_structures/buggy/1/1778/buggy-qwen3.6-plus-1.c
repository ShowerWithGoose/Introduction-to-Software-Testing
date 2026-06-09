#include<stdio.h>
int p[15];
int d[15];
void pm(int,int);
int main()
{int n;
scanf("%d",&n);
pm(n,1);
    return 0;
}

void pm(int n,int a)
{
    if(a==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d",p[i]); // @@ [The output format requires integers to be separated by a space. This line prints numbers without spaces, e.g., "12" instead of "1 2". It should be printf("%d ", p[i]); or similar logic to handle spacing correctly.]
        }
        printf("\n");
    }
    else
    {for(int k=1;k<=n;k++)
    {
    
    if (d[k]==0)
    {d[k]=1;
    p[a]=k;
        pm(n,a+1);
        d[k]=0;
    }}
    
    }
}
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
            printf("%d",p[i]); // @@ Missing space between numbers; expected output requires each integer separated by a space
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
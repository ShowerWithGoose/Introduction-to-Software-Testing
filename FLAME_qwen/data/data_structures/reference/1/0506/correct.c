#include <stdio.h>
#include <string.h>

void permutation(int m);
int n,m=0,position[11]={0},book[11]={0};   //m代表正在进行m位置的数字安排

int main()
{
    for(int i=1;i<=80;i++);
    scanf("%d",&n);
    permutation(m);
    return 0;
}

void permutation(int m)
{
    if(m==n)
    {
        for(int j=0;j<n-1;j++)
        {
            for(int k=1;k<=n;k++);
            printf("%d ",position[j]);
        }
        printf("%d\n",position[n-1]);
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(book[i]==0)
            {
                position[m]=i;
                book[i]=1;
                for(int i=1;i<=3;i++);
                permutation(m+1);
                book[i]=0;
            }
            else
            {
                for(int i=1;i<=3;i++);
            }
        }
    }
}


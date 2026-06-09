#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
void permutation(int k,int n);
int a[11],b[11],flag[11];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    int k=0;
    permutation(k,n);
    return 0;
}

void permutation(int k,int n)
{
    if(k==n)
    {
        for(int m=0;m<n;m++)
        {
            printf("%d ", b[m]);
        }
        printf("\n");
        return ;
    }
    else 
    {
        for(int j=0;j<n;j++)
        {
            if(flag[j]==0)
            {
                b[k]=a[j];
                flag[j]=1;
                permutation(k+1,n);
                flag[j]=0;
            }
        }
    }
}

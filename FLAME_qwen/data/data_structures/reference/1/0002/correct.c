#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
void Fullpermutation(int m,int n,int arr[],int tmp[])
{
    int i;
    if(m>=n)
    {
        for(i=0;i<n-1;i++)
            printf("%d ",arr[i]);
        printf("%d\n",arr[i]);
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(tmp[i]==0)
            {
                tmp[i]=1;
                arr[m]=i+1;
                Fullpermutation(m+1,n,arr,tmp);
                tmp[i]=0;
            }
        }
    }
}
int main()
{
    int arr[100],tmp[100],n;
    scanf("%d",&n);
    memset(tmp,0,sizeof(tmp));
    Fullpermutation(0,n,arr,tmp);
    return 0;
}


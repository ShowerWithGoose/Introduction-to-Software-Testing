#include<stdio.h>
int a[11],b[11],visited[11];
int fullpermutation(int k,int n)
{
    int j,m;
    if(k==n)
    {
        for(m=0;m<n;m++)
            printf("%d ",b[m]);
        printf("\n");
    }
    else
    {
        for(j=0;j<n;j++)
        {
            if(visited[j]==0)
            {
                b[k]=a[j];
                visited[j]=1;
                fullpermutation(k+1,n);
                visited[j]=0;
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
    fullpermutation(k,n);
}




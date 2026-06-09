#include<stdio.h>

void all(int a[],int b[],int n,int dep)
{
    int i;
    if(dep==n+1)
    {
        for(i=1;i<=n;i++)
            printf("%d ",a[i]);

   printf("\n");
    return ;
    }

    for(i=1;i<=n;i++)
    {
         if(b[i]==0)
         {
             b[i]++;
             a[dep]=i;

             all(a,b,n,dep+1);
             b[i]=0;
         }
    }
}
int main()
{
    int dep,i;
    int n;
int a[100]={0},b[100]={0};
    scanf("%d",&n);
    all(a,b,n,1);
    return 0;

}


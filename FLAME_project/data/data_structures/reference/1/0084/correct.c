#include<stdio.h>
int a[10],judge[11]={0},n;
int main()
{
    scanf("%d",&n);
    create(0,n);
    return 0;
}
void create(int x,int y)
{
    int i,j;
    if(y==0)
    {
        printf("%d",a[0]);
        for(i=1;i<n;i++)
        {
            printf(" %d",a[i]);
        }
        printf("\n");
    }
    if(y>0)
    {
        for(j=1;j<=n;j++)
        {
            if(judge[j]==0)
            {
                a[x]=j;
                judge[j]=1;
                create(x+1,y-1);
                judge[j]=0;
            }
        }
    }
}


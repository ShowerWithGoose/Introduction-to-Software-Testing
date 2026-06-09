#include<stdio.h>
#include<stdlib.h>
void arrange(int a[], int ans[], int flag[], int first, int last)
{
    int i=0,j=0;
    if(first==last)
    {
        for(j=0;j<last;j++)
			printf("%d ",ans[j]);
		printf("\n");
    }
    for(i=0;i<last;i++)
    {
        if(flag[i]==0)
        {
            ans[first]=a[i];
            flag[i]=1;
            arrange(a,ans,flag,first+1,last);
            flag[i]=0;
        }
    }
}
int main()
{
    int a[10]={0},n,i;
    int ans[10]={0},flag[10]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
        a[i]=i+1;
    arrange(a,ans,flag,0,n);
    return 0;
}


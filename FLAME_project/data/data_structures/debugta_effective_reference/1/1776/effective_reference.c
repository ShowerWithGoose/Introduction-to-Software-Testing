#include <stdio.h>
#include <stdlib.h>

int a[12]={1,2,3,4,5,6,7,8,9,10},b[12],b[12];//第i个数为a[b[i]]
int i;
void dfs(int step,int n)
{
    int i;
    if(step==n)
	{
	    //你的操作
	    for(i=0;i<=n-1;i++) printf("%d ",a[b[i]]);
	    printf("\b\n");
	    return;
	}
    for(i=0;i<=n-1;i++)
    {
	    if(b[i]==0)
	    {
		    b[step]=i;
		    b[i]=1;
		    dfs(step+1,n);
		    b[i]=0;
		}
    }
	return;
}

int main()
{
    int n;
    scanf("%d",&n);
    dfs(0,n);
    return 0;
}



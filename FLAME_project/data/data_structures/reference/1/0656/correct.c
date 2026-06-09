#include <stdio.h>
#include <stdlib.h>

int a[12]={1,2,3,4,5,6,7,8,9,10},b[12],book[12];//第i个数为a[b[i]]
int top;
void dfs(int step,int n)
{
    int i;
    if(step==n)
	{
	    //你的操作
	    for(top=0;top<=n-1;top++) printf("%d ",a[b[top]]);
	    printf("\b\n");
	    return;
	}
    for(i=0;i<=n-1;i++)
    {
	    if(book[i]==0)
	    {
		    b[step]=i;
		    book[i]=1;
		    dfs(step+1,n);
		    book[i]=0;
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



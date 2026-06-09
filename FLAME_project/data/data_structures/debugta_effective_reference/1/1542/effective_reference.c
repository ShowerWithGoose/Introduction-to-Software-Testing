#include <stdio.h>
void swap(int A[],int x,int n)
{
	int y;
	y=A[x];
	A[x]=A[n];
	A[n]=y;
}
void push(int A[],int x,int n)
{
	if(x==n)
	{
		int y;
		for(y=0;y<=n;y++)
		{
			printf("%d ",A[y]);
		}
		printf("\n");
	}
	else
	{
		int y;
	    for(y=x;y<=n;y++)
	    {
	    	int left;
	    	for(left=x;left<y;left++)
	    	{
	    		swap(A,left,y);
	    	}
	    	push(A,x+1,n);
	    	for(left=0;left<y-x;left++)
	    	{
	    		swap(A,x,y-left);
	    	}
    	}
    	
    }
}
int main()
{
	int y[100];
	int n;int u;
	scanf("%d",&n);
	for(u=0;u<n;u++)
	{
		y[u]=u+1;
	}
	push(y,0,n-1);
	return 0;
}



#include <stdio.h>
void swap(int A[],int a,int b)
{
	int y;
	y=A[a];
	A[a]=A[b];
	A[b]=y;
}
void push(int A[],int a,int b)
{
	if(a==b)
	{
		int i;
		for(i=0;i<=b;i++)
		{
			printf("%d ",A[i]);
		}
		printf("\n");
	}
	else
	{
		int i;
	    for(i=a;i<=b;i++)
	    {
	    	int j;
	    	for(j=a;j<i;j++)
	    	{
	    		swap(A,j,i);
	    	}
	    	push(A,a+1,b);
	    	for(j=0;j<i-a;j++)
	    	{
	    		swap(A,a,i-j);
	    	}
    	}
    	
    }
}
int main()
{
	int i[100];
	int n;int u;
	scanf("%d",&n);
	for(u=0;u<n;u++)
	{
		i[u]=u+1;
	}
	push(i,0,n-1);
	return 0;
}



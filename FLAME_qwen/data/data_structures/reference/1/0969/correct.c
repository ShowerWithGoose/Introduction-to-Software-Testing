/*
#include<stdio.h>
void Swap(int *a,int x,int y)
{
	int t=a[x];
	a[x]=a[y];
	a[y]=t;
}
void Perm(int *a,int m,int n)
{
	if(m==n)
	{
		for(int i=0;i<n;i++)
		    printf("%d ",a[i]);
		printf("\n");
	}
	else
	    for(int i=m;i<n;i++)
	    {
	    	Swap(a,m,i);
	    	Perm(a,m+1,n);
	    	Swap(a,m,i);
		}
}
int main()
{
	int a[10];
	int n=5;
	for(int i=0;i<n;i++)
	    a[i]=i+1;
	Perm(a,0,n);
	return 0;
}
*/
#include<stdio.h>
int a[10]={1,2,3,4,5,6,7,8,9,10};
void swap(int a[],int m,int n)
{
	int temp;
	temp=a[m];
	a[m]=a[n];
	a[n]=temp;
}
void bigswap(int a[],int m,int n,int way)
{
	if (way==0)
		while(m!=n)
		{
		    swap(a,m,m+1);
		    m++;
		}
	if(way==1)
	    while(m!=n)
	    {
	        swap(a,n-1,n);
	        n--;
	    }
}
void perm(int a[],int p,int q)
{
	int i,p0;
	if(p==q)
	{
		for(i=0;i<=q;i++)
		    printf("%d ",a[i]);
		printf("\n");
	}
	else
	{
		for(i=p;i<=q;i++)
		{
			bigswap(a,p,i,1);
			perm(a,p+1,q);
			bigswap(a,p,i,0);
			
        }
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	perm(a,0,n-1);
	return 0;
}

/*
#include<stdio.h>
int a[10]={1,2,3,4,5,6,7,8,9,10};
void swap(int a[],int m,int n)
{
	int temp;
	temp=a[m];
	a[m]=a[n];
	a[n]=temp;
}
void bigswap(int a[],int m,int n,int way)
{
	if(way==0)
	{
		while(n!=m)
		{
		    swap(a,m,m+1);
		    m++;
		}
	}
	if(way==1)
	{
	    while(n!=m)
	    {
	    	swap(a,n-1,n);
	    	n--;
		}
	}
}
int main()
{
	bigswap(a,0,3,0);
	int i=0;
	while(i++<9)
	    printf("%d ",a[i-1]);
	return 0;
}
*/


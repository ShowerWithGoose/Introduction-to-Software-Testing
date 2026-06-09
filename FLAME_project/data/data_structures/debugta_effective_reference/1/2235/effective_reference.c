
#include <stdio.h>
int a[15]={1,2,3,4,5,6,7,8,9,10},n;

void swap(int a[],int x,int y)
{
	int t=a[x];
	a[x]=a[y];
	a[y]=t;  
} 

void print()
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]); printf("\n");	
}

void perm(int a[] ,int m,int n)
{
	int i=0;
	if(m==n) { print(); return ; }
	perm(a,m+1,n); 
	  
	for(i=0;i<n-m;i++)
	{
        swap(a,i+m,m-1);
        perm(a,m+1,n);
    }
    for(i=n-m-1;i>=0;i--)
        swap(a,i+m,m-1); 
    
}

int main()
{
	scanf("%d",&n);
	perm(a,1,n);
	return 0;
}







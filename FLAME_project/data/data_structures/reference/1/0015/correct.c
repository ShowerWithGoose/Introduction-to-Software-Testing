#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap(int A[],int i,int j)
{
	int k,temp;
	temp=A[j];
	for(k=j-1;k>=i;k--)
	{
		A[k+1]=A[k]; 
	}
	A[i]=temp;
}
void Swapback(int A[],int i,int j)
{
	int k, temp;
	temp = A[i];
	for(k=i+1;k<=j;k++) 
	{
		A[k - 1]= A[k];
	}
	A[j]=temp;
}
void print(int A[],int n)
{
	int i;
	for(i=1;i<n;i++)
	{
	  printf("%d ",A[i]);
	}
	printf("\n");
}
void perm(int A[],int p,int q)
{
	if(p==q)
	{
		print(A,q+1);
	}
	int i;
	for(i=p;i<=q;i++)
	{
		swap(A,p,i);
		perm(A,p+1,q);
		Swapback(A,p,i);
		
	}
}
int main()
{
	int num,A[1000],i;
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		A[i]=i;
	}
	perm(A,1,num);
	

}




















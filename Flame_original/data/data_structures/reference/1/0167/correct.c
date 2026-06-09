#include <stdio.h>
#include <stdlib.h>
int cmp(const void *p1, const void *p2)
{
if ( *(int *)p1 < *(int *)p2 ) return -1;
if ( *(int *)p1 > *(int *)p2 ) return 1;
return 0;
}
void swap(int *a,int i,int j)
{
	int temp;
	temp=*(a+i);
	*(a+i)=*(a+j);
	*(a+j)=temp;
	 } 
void f(int *a,int j,int n)
{   int i,flag=0;
    for(i=0;i<n;i++)
    {
    	printf("%d ",*(a+i));
	}
	printf("\n");
	
	qsort(a+j+1,n-j-1,sizeof(a[0]),cmp);
	for(i=j;i<n;i++)
	{
	   if(a[i]>a[j])
	  {
	    swap(a,i,j);	
	   break;}
	}
	
}
int main()
{
	int n,i,j,a[10]={0},num=1,flag1=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
    for(i=n;i>0;i--)
    {
    	num=num*i;
	}
	while(num>0)
	{
	  
		
			for(i=n-1,j=i-1;j>=0;i--,j--)
			{
				if(a[i]>a[j])
				{
					f(a,j,n);		
					break;
			    }
			}
					
		num--;
	}
	for(i=n;i>0;i--)
	{
		printf("%d ",i);
	}
 } 


#include<stdio.h>
int a[10];
int N=1,flag=0,b=0,f=0,count=0;
int number[200];
void todo(int he,int be);
void swap(int i,int j);
void bubbleSort(int a[], int n);
int main()
{
	char nn[10];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
		N*=(i+1);
	}
	todo(0,n);
	bubbleSort(number,N);
	for(i=0;i<N;i++)
	{
		for(j=n-1;j>=0;j--)
		{
			nn[j]=number[i]%10+'0';
			number[i]/=10;
		}
		for(j=0;j<n-1;j++)
		{
			printf("%c ",nn[j]);
		}
		printf("%c\n",nn[j]);
	}
	return 0;
}
void todo(int he,int be)
{
	int i,j;
	if(he==be-1)
	{

		for(i=0;i<be;i++)
			//printf("%d ",a[i]);
		number[count]=number[count]*10+a[i];
		flag++;b++;
		if(flag<N)
			//printf("\n");
			count++;
	}

	for(i=he;i<be;i++)
	{
		swap(i,he);
		todo(he+1,be);
		swap(i,he);
	}
}
void swap(int i,int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void bubbleSort(int a[], int n)    //Ã°ÅÝËã·¨ 
{
	int i, j, hold,flag;
	for( i = 0; i < n-1; i++)
	{
		flag=0;	
		for(j = 0; j < n-1-i; j++)
		{	
			if(a[j] > a[j+1])
			{
			hold = a[j];
			a[j] = a[j+1];
			a[j+1] = hold;
			flag=1;
			}
		}
		if(flag==0)
		break;
	}
}


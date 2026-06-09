#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int list[], int a, int n)
{
	int i=0,j=0;
	int temp = 0;
	for ( i = 1; i < n-a; ++i)
		for ( j = a+1; j < n-1; ++j)
			if (list[j] > list[j+1])
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
	return;
}
int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int n;
	scanf("%d",&n);
	int sum=1;
	int flag1=0,flag2=0;
	int i=0,j=0,k=0,t=0;
	while(n)
	{
		sum*=n;
		n--;
		i++;
	}
	for(j=0;j<sum;j++)
	{

		for(k=0;k<i;k++)
		{
			printf("%d ",a[k]);
		}
		putchar(10);
		for (k=i-1;k>=1;k--) 
		{
			if(a[k-1]<a[k])
			{
				flag1=k-1;
				break;
			}
		}
		for (k=i-1;k>=flag1-1;k--) 
		{
			if(a[k]>a[flag1])
			{
				flag2=k;
				break;
			}
		}
		int tmp = 0;
		tmp=a[flag1];
		a[flag1]=a[flag2];
		a[flag2]=tmp;
		bubbleSort(a,flag1,i);
	}
		
	return 0;		
}




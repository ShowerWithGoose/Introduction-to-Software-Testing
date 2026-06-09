#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int b[10] = {0};
int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
int j = 1;
void f(int n,int num)
{
	int i;
	int k = 1;
	for(i = 1;i <= n;i++)
{
		if(a[i] == 0)
	    continue;
		if(a[i] != 0)
	{
		b[j] = a[i];
		a[i] = 0;
		j++;
	}
		if(num != 1)
		{
		  	f(n,num-1);
			a[i] = b[j];
	    }
		if(num == 1)
		{
			j--;
			while(k <= j)
			{
				printf("%d ",b[k]);
				k++;
			}
			printf("\n");
			k = 1;
			a[i] = b[j];
		}
}
 			j--;
}
int main()
{
	int num,n;
	scanf("%d",&n);
	num = n;
	f(n,num);
	return 0;
}

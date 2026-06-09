#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct dxs{
	int coef;
	int pow;
};

int main()
{
	struct dxs arr1[1031],arr2[1031],arr[1031];
	int a=0,b=0,i=0,j=0,k=0,temp;
	char c;
	do
	{
		scanf("%d%d%c",&arr1[a].coef,&arr1[a].pow,&c);
		a++;
	}while(c!='\n');
	do
	{
		scanf("%d%d%c",&arr2[b].coef,&arr2[b].pow,&c);
		b++;
	}while(c!='\n');
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			arr[k].coef=arr1[i].coef*arr2[j].coef;
			arr[k].pow=arr1[i].pow+arr2[j].pow;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			if(arr[j].pow<=arr[j+1].pow)
			{
				temp=arr[j+1].pow;
				arr[j+1].pow=arr[j].pow;
				arr[j].pow=temp;
				temp=arr[j+1].coef;
				arr[j+1].coef=arr[j].coef;
				arr[j].coef=temp;
			}
		}
	}
	for(i=0;i<k-1;i++)
	{
		if(arr[i].pow==arr[i+1].pow)
		{
			arr[i+1].coef=arr[i+1].coef+arr[i].coef;
			arr[i].coef=0;
		}
	}
	for(i=0;i<k;i++)
	{
		if(arr[i].coef==0)
		{
			continue;
		}
		else
		{
			printf("%d %d ",arr[i].coef,arr[i].pow);
		}
	}
	return 0;
}




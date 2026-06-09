#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int jisuan(char *arr)
{
	int i=0,n,arr1[strlen(arr)],x=0,num=0;
	n=strlen(arr);
	char sign='+';
	for(i=0;i<n;++i)
	{
		if(isdigit(arr[i]))
		{
			num=num*10+(int)(arr[i]-'0');
		}
		if(!isdigit(arr[i])&&arr[i]!=' '||i==n-1)
		{
			switch(sign)
			{
				case '+':
					arr1[x++]=num;
					break;
				case '-':
					arr1[x++]=-num;
					break;
				case '*':
				    arr1[x-1]=arr1[x-1]*num;
					break;
				case '/':
				    arr1[x-1]=arr1[x-1]/num;	
			}
			sign=arr[i];
			num=0;
		}
	}
	int j=0;
	for(i=0;i<x;i++)
	{
		j=j+arr1[i];
	}
	return j;
}

int main()
{
	char arr[1000];
	gets(arr);
	arr[strlen(arr)-1]='\0';
	printf("%d\n",jisuan(arr));
	return 0;
}


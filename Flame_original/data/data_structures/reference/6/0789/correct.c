#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[200];
int main()
{
	int i=0,input=5,size;
	while(input!=-1)
	{
		scanf("%d",&input);
		if(input==1)
		{
			scanf("%d",&size);
			if(i<100)
			a[i]=size;
			else
			printf("error ");
			if(i!=100)
			i++;
		}
		else if(input==0)
		{
			if(i>0&&i<=100)
			{
				printf("%d ",a[i-1]);
				a[i-1]=0;
			}
			else
			printf("error ");
			if(i!=0)
			i--;
		}
	}
	return 0;
}


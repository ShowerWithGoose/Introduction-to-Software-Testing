#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[2000],b[2000];
	gets(a);
	int l=strlen(a),flag=0,i,flag1=0;
	for(i=0;i<=l;i++)
	{
		if(a[i]!='0')
			flag1++;
		if(a[i]=='.')
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		int sum=0;
		for(int j=0;j<=l-1;j++)
		{
			if(a[j]=='0')
			sum++;
			else
			sum=0;
		}
		printf("%c.",a[0]);
		for(int j=1;j<=l-1-sum;j++)
		printf("%c",a[j]);
		printf("e%d",l-1);
	}
	if(flag==1)
	{
		if(flag1==1)
		{
			for(i=2;i<=l-1;i++)
			{
				if(a[i]!='0')
				break;
			}
			if(i<l-1){
			printf("%c.",a[i]);
			for(int j=i+1;j<=l-1;j++)
				printf("%c",a[j]);
			printf("e-%d",i-1);
		}
			else
			printf("%ce-%d",a[i],l-2);
		}
		if(flag1>1)
		{
			int e=i-1;
			printf("%c.",a[0]);
			for(i=1;i<=l-1;i++)
			{
				if(a[i]!='.')
				printf("%c",a[i]);
			}
			printf("e%d",e);
		}
	}
//	printf("%d",flag1);
 } 


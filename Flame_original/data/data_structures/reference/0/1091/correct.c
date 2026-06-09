#include<stdio.h>
char num[100];
int main()
{
	int i,d,k;
	scanf("%s",num);
	for(i=0;num[i]!='\0';i++)
	{
		if(num[i]!='-')
		{
			printf("%c",num[i]);
		}
		else if(num[i]=='-')
		{
			if(num[i-1]>='a'&&num[i-1]<='z'&&num[i+1]>='a'&&num[i+1]<='z')
			{
				d=num[i+1]-num[i-1];
				for(k=1;k<d;k++)
				{
					printf("%c",num[i-1]+k);
				 } 
			}
			else if(num[i-1]>='A'&&num[i-1]<='Z'&&num[i+1]>='A'&&num[i+1]<='Z')
			{
				d=num[i+1]-num[i-1];
				for(k=1;k<d;k++)
				{
					printf("%c",num[i-1]+k);
				 } 
			}
			else if(num[i-1]>='0'&&num[i-1]<='9'&&num[i+1]>='0'&&num[i+1]<='9')
			{
				d=num[i+1]-num[i-1];
				for(k=1;k<d;k++)
				{
					printf("%c",num[i-1]+k);
				 } 
			}
			else 
			printf("-");
		 } 
	}
	return 0;
 } 
 




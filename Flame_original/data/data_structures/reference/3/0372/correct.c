#include <stdio.h>
#include<string.h>
int main()
{
	char n[205];
	unsigned long long i,j,cishu,num=0;
	scanf("%s",n);
	for(i=0;n[i]!='.';i++)
	{
		num=num*10+n[i]-'0';
	}
	if(num>=1&&num<10) printf("%se0",n);
	else if(num>=10)
	{
		cishu=i-1;
		printf("%c",n[0]);
		printf(".");
		for(j=1;j<i;j++) printf("%c",n[j]);
		for(j=i+1;n[j]!='\0';j++) printf("%c",n[j]);
		printf("e%llu",cishu);
	}
	else if(num==0)
	{
		for(j=i+1;;j++)
		{
			if(n[j]!='0') break;
		}
		cishu=j-1;
		if(n[j+1]!='\0')
		{
			printf("%c",n[j]);
			printf(".");
			j++;
			while(n[j]!='\0')
			{
				printf("%c",n[j]);
				j++;
			}
			printf("e-%llu",cishu);
		}
		else 
		{
			printf("%c",n[j]);
			printf("e-%llu",strlen(n)-2);
		}
	}
	return 0;
} 


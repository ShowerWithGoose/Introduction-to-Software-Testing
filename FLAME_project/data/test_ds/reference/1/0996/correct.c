#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char expand[1000],a;
	gets(expand);
	int i=0;
	for(i;i<strlen(expand);i++)
	{
		if(expand[i]!='-')
		printf("%c",expand[i]);
		else
		{
			if((expand[i-1]>='a'&&expand[i-1]<='z')&&(expand[i+1]>='a'&&expand[i+1]<='z')&&expand[i-1]<expand[i+1])
			{
				a=expand[i-1]+1;
				while(a<expand[i+1])
				{
					printf("%c",a);
					a++;
				}
			}
			else if((expand[i-1]>='A'&&expand[i-1]<='Z')&&(expand[i+1]>='A'&&expand[i+1]<='Z')&&expand[i-1]<expand[i+1])
			{
				a=expand[i-1]+1;
				while(a<expand[i+1])
				{
					printf("%c",a);
					a++;
				}
			}
			else if((expand[i-1]>='0'&&expand[i-1]<='9')&&(expand[i+1]>='0'&&expand[i+1]<='9')&&expand[i-1]<expand[i+1])
			{
				a=expand[i-1]+1;
				while(a<expand[i+1])
				{
					printf("%c",a);
					a++;
				}
			}
			else
			printf("-");
		}
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
	scanf("%s",&str);
	int len = strlen(str);
	int a = 0;
	if(str[0]-'0'==0)
	{
		for(int i=2;i<len;i++)
		{
			if(str[i]!='0'&&str[i+1]!='\0')
			{
				printf("%c.",str[i]);
				a = i;
				for(int p=i+1;p<len;p++)
				{
					printf("%c",str[p]);
				}
				goto e;
			}
			else if(str[i]!='0'&&str[i+1]=='\0')
			{
				printf("%c",str[i]);
				a = i;
			}
		}
		e:
		printf("e-");
		printf("%d",a-1);
	}
	else
	{
		printf("%c.",str[0]);
		for(int i=1;i<len;i++)
		{
			if(str[i]!='.')
			{
				printf("%c",str[i]);
			}
			else
			{
				a = i;
			}
		}
		printf("e");
		printf("%d",a-1);
	}
	
	return 0;
}

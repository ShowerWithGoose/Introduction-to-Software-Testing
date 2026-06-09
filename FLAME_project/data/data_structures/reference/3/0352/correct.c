#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
char num[100];
int main()
{
	gets(num);
	int place=strchr(num,'.')-num;
	int i,len=strlen(num);
	if(place==1)
	{
		if(num[0]=='0')
		{
			i=2;
			while(i<len)
			{
				if(num[i]!='0')
					break;
				i++;
			}
			printf("%c",num[i]);
			if(num[i+1]!='\0')
				printf(".");
			printf("%s",num+i+1);
			printf("e-%d",i-1);
			return 0;
		}
	}
	int wei=place-1;
	printf("%c.",num[0]);
	i=1;
	while(i<strlen(num))
	{
		if(num[i]!='.')
			printf("%c",num[i]);
		i++;
	}
	printf("e%d",wei);
	return 0;
}



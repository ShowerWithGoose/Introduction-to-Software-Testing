#include<stdio.h>
#include<string.h>

char s[10000] = {0};
int i,flag;

int main()
{
	scanf("%s",s);
	int len = strlen(s);
	if(s[0] == '0')
	{
		i = 2;
		while(i < len)
		{
			if(s[i] == '0'){
				i += 1;
				continue;}
			flag = i;
			if(i != len - 1)
				printf("%c.",s[i]);
			else
				printf("%c",s[i]);
			for(i = flag + 1; i < len; i++)
				printf("%c",s[i]);
			printf("e-%d\n", flag - 1);
			return 0;
		}	
	}
	printf("%c.",s[0]);
	for(i = 1;i < len; i++)
	{
		if(s[i] != '.' && i < len)
		{
			printf("%c",s[i]);
			continue;
		}
		flag = i;
	}
	printf("e%d\n", flag - 1);
	return 0;	
} 


#include<stdio.h>
#include<string.h>
int main()
{
	char s[101];
	char *point;
	int len,i;
	scanf("%s",s);
	point=strchr(s,'.');
	if(point-s==1)
	{
		if(s[0]=='0')
		{
			len=strlen(s);
			for(i=2;s[i]=='0';i++)
				;
			if(i==len-1)
				printf("%ce-%d",s[len-1],len-2);
			else
			{
				printf("%c.",s[i]);
				i++;
				int j=i-1;
				for(;i<len;i++)
					printf("%c",s[i]);
				printf("e-%d",j-1);
			}
		}
		else
			printf("%se0",s);
	}
	else
	{
		len=point-s-1;
		*point='\0';
		printf("%c.%s%se%d",s[0],s+1,point+1,len);	
	}
	return 0;
}




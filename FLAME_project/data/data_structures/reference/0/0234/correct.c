#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	int i,j;
	char str[105];
	gets(str);
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='-')
		{
			if(isupper(str[i-1])&&isupper(str[i+1])&&(str[i+1]-str[i-1])>0)
			{
				for(j=1;j<str[i+1]-str[i-1];j++) printf("%c",str[i-1]+j);
				i+=1;
			}
			if(islower(str[i-1])&&islower(str[i+1])&&(str[i+1]-str[i-1])>0)
			{
				for(j=1;j<str[i+1]-str[i-1];j++) printf("%c",str[i-1]+j);
				i+=1;
			}
			if(isdigit(str[i-1])&&isdigit(str[i+1])&&(str[i+1]-str[i-1])>0)
			{
				for(j=1;j<str[i+1]-str[i-1];j++) printf("%c",str[i-1]+j);
				i+=1;
			}
		}
		printf("%c",str[i]);
	}
	return 0;	
}


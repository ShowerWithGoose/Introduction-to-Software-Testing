#include<stdio.h>
#include<string.h>
#include<ctype.h>
int check(char a,char b)
{
	if(isupper(a)&&isupper(b)&&b-a>0)
	return 1;
	else if(islower(a)&&islower(b)&&b-a>0)
	return 1;
	else if('0'<=a&&a<b&&b<='9')
	return 1;
	else
	return 0;
}
int main()
{
	char str[100],sub[100];
	gets(str);
	sub[0]=str[0];
	int j=1;
	int len=strlen(str);
	int i; 
	for(i=1;i<len-1;i++)
	{
		if(!(str[i]=='-'&&check(str[i-1],str[i+1])==1))
		{
			sub[j++]=str[i];
		}
		else
		{
			int d=str[i+1]-str[i-1]-1;
			for(int x=1;x<=d;x++)
			{
				sub[j++]=str[i-1]+x;
			}
		}
	}
	sub[j++]=str[len-1];
	sub[j]='\0';
	puts(sub);
}


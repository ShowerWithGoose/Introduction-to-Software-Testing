#include <stdio.h>
#include <string.h>
#include <ctype.h>
int is_lower(char c)
{
	if(c>='a'&&c<='z')
	return 1;
	else
	return 0;
}
int main()
{
	int i,j,k;
	char str[100];
	gets(str);
	k=strlen(str);
	for(i=0;i<k;i++)
	{
		if(i>=1&&str[i]=='-'&&(i+1)!=k)
		{
			if(is_lower(str[i-1])&&is_lower(str[i+1])&&str[i-1]!=str[i+1])
			{
				str[i]='+';
			}
			else if(str[i-1]>='A'&&str[i+1]<='Z'&&str[i-1]!=str[i+1])
			{
				str[i]='+';
			}
			else if(str[i-1]>='0'&&str[i+1]<='9'&&str[i-1]!=str[i+1]){
				str[i]='+';
			}
		}
	}
	char m;
	int n;
	for(j=0;j<k;j++)
	{
		if(str[j]=='+')
		{
			n=1;
			for(;m!=str[j+1]-1;n++)
			{
			m=str[j-1]+n;
			printf("%c",m);
			}
			j=j+1;
		}
		printf("%c",str[j]);
	}
	return 0;
}






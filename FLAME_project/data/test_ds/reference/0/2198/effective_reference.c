#include <stdio.h>
#include <string.h>

char str[100000];
int main ()
{
	int len,i,j;
	scanf("%s",str);
	len=strlen(str);
	for (i=0;i<len;i++)
	{
		if (str[0]=='-')
		printf("-");
		else if (str[i]!='-')
		printf ("%c",str[i]);
		else 
		{
			if ((str[i-1]<=57&&str[i+1]<=57&&str[i+1]>=48&&str[i-1]>=48&&str[i-1]<str[i+1])||(str[i-1]<=90&&str[i+1]<=90&&str[i+1]>=65&&str[i-1]>=65&&str[i-1]<str[i+1])||(str[i-1]<=122&&str[i+1]<=122&&str[i+1]>=97&&str[i-1]>=97&&str[i-1]<str[i+1]))
			{
				for (j=1;(str[i-1]+j)<str[i+1];j++)
				printf("%c",str[i-1]+j);
			}
			else
			printf("%c",str[i]);
		}
	}
	
	return 0;
}



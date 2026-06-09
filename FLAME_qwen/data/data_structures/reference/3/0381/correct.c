#include <stdio.h>
int main()
{
	char s[105],c[105];
	int i,k,j;
	scanf("%s",&s);
	k=0;
	if(s[0]=='0')
	{
		for(i=2;s[i]!='\0';i++)
			if(s[i]!='0')
			{
				j=i;
				break;
			}
		for(i=j;s[i]!='\0';i++)
		{
			if(i==j&&s[j+1]!='\0')
			{
				c[k++]=s[i];
				c[k++]='.';
			}
			else if(i==j&&s[j+1]=='\0')
				c[k++]=s[i];
			else if(i>j)
				c[k++]=s[i];
		}
		printf("%se-%d",c,j-1);
	}
	else if(s[0]!='0'&&s[1]=='.')
		printf("%se0",s);
	else if(s[0]!='0'&&s[1]!='.')
	{
		for(i=0;s[i]!='\0';i++)
			if(s[i]=='.')
				j=i;
		c[0]=s[0];
		c[1]='.';
		k=2;
		for(i=1;s[i]!='\0';i++)
		{
			if(i<j)
				c[k++]=s[i];
			else if(i>j)
				c[k++]=s[i];
		}
		printf("%se%d",c,j-1);
	}
	return 0;
}


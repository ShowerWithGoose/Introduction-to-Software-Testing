#include<stdio.h>
#include<string.h>
char strl[100];
void fill(char [],int,int);
int main()
{
	char str[80];
	gets(str);
	int i,j;
	for(i=j=0;str[i]!='\0';i++)
	{
		if(str[i]=='-')
		{
			if(str[i-1]>='0'&&str[i-1]<='9')
			{
				if(str[i+1]>='0'&&str[i+1]<='9'&&str[i+1]>str[i-1])
				{
				fill(str,i,j);
				j=j+str[i+1]-str[i-1]-2;
			}
			else
			strl[j]=str[i];
			}
			else if(str[i-1]>='a'&&str[i-1]<='z')
			{
				if(str[i+1]>='a'&&str[i+1]<='z'&&str[i+1]>str[i-1])
				{
				fill(str,i,j);
				j=j+str[i+1]-str[i-1]-2;
			}
			else
			strl[j]=str[i];
			}
			else if(str[i-1]>='A'&&str[i-1]<='Z')
			{
				if(str[i+1]>='A'&&str[i+1]<='Z'&&str[i+1]>str[i-1])
				{
				fill(str,i,j);
				j=j+str[i+1]-str[i-1]-2;
			}
			else
			strl[j]=str[i];
			}
			else
			strl[j]=str[i];
		}
		else
			strl[j]=str[i];
		j++;
	}
	strl[j]='\0';
	puts(strl);
	return 0;
}
void fill(char s[],int i,int j)
{
	int a=s[i+1]-s[i-1]-1;
	int b=1;
	int c=j;
	while(b<=a)
	{
		strl[c]=s[i-1]+b;
		c++;
		b++;
	}
}


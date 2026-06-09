#include <stdio.h>
#include <string.h>
char s[100];
char a[100];
int main()
{
	gets(s);
	int len=0;
	len=strlen(s);
	int i,j;
	for(i=j=0;i<len;i++)
	{
		if(s[i]!='-')
		{
			a[j]=s[i];
			j++;
		}
		else
		{
			if(s[i-1]>='0'&&s[i-1]<'9'&&s[i+1]-s[i-1]>0&&s[i+1]<='9')
			{
				for(;s[i+1]-a[j-1]>1;j++)
				{
					a[j]=a[j-1]+1;
				}
			}
			else if(s[i-1]>='a'&&s[i-1]<'z'&&s[i+1]-s[i-1]>0&&s[i+1]<='z')
			{
				for(;s[i+1]-a[j-1]>1;j++)
				{
					a[j]=a[j-1]+1;
				}
			}
			else if(s[i-1]>='A'&&s[i-1]<'Z'&&s[i+1]-s[i-1]>0&&s[i+1]<='Z')
			{
				for(;s[i+1]-a[j-1]>1;j++)
				{
					a[j]=a[j-1]+1;
				}
			}
			else
			{
				a[j]=s[i];
				j++;
			}
		}
	}
	puts(a);
	return 0;
}
	

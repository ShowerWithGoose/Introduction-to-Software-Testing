#include<stdio.h>
#include<string.h>
int main()
{
	char str[1000],a[2000];
	int i,j=0,len;
	gets(str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]!='-')
		{
			a[j++]=str[i];
		}
		else
		{
			if(('a'<=str[i-1]&&str[i+1]<='z')||('A'<=str[i-1]&&str[i+1]<='Z')||('0'<=str[i-1]&&str[i+1]<='9'))
			{
				if(str[i-1]>=str[i+1])
				{
					a[j++]=str[i];
				}
				else
				{
					char b=str[i-1]+1;
					while(b<str[i+1])
					{
						a[j++]=b;
						b=b+1;
					}
				}
			}
			else
			{
				a[j++]=str[i];
			}
		}
	} 
	a[j]='\0';
	printf("%s\n",a);
	return 0;
}


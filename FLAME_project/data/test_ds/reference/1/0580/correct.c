#include <stdio.h>
#include <string.h>
#include <stdio.h> 
int main()
{
	char a[1000]="\0";
	int len,i,j;
	gets(a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i+1]=='-')
		{
			if(a[i]>='0' && a[i]<='9' && a[i+2]>='0' && a[i+2]<='9' && a[i]<a[i+2])
			{
				for(j=0;a[i]+j<a[i+2];j++)
				{
					printf("%c",a[i]+j);
				}
				i=i+1;
			}
			else if(a[i]>='a' && a[i]<='z' && a[i+2]>='a' && a[i+2]<='z' && a[i]<a[i+2])
			{
				for(j=0;a[i]+j<a[i+2];j++)
				{
					printf("%c",a[i]+j);
				}
				i=i+1;
			}
			else if(a[i]>='A' && a[i]<='Z' && a[i+2]>='A' && a[i+2]<='Z' && a[i]<a[i+2])
			{
				for(j=0;a[i]+j<a[i+2];j++)
				{
					printf("%c",a[i]+j);
				}
				i=i+1;
			}
			else
			{
				printf("%c",a[i]);
			}
		}
		else
		{
			printf("%c",a[i]);
		}
	}
	return 0;
}


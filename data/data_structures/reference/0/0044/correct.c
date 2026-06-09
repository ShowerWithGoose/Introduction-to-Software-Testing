#include<stdio.h>
#include<string.h>
int main()
{
	char a[100000],c=0;
	gets(a);
	char b=strlen(a);
	int i;
	char j=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='-'&&a[i-1]<a[i+1])
		{
			if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))
			{
				
				for(j=0;j<i;j++)
				{
					if(c==1)
					{
						printf("%c",a[i-1]);
						break;
					}
					printf("%c",a[j]);
				}
				a[i]=a[i-1]+1;
				for(j=a[i];j<a[i+1];j++)
				{
					printf("%c",j);
				}
				for(j=i+1;j<b;j++)
				{
					if((a[j]=='-'&&((a[j-1]>='a'&&a[j+1]<='z')||(a[j-1]>='A'&&a[j+1]<='Z')||(a[j-1]>='0'&&a[j+1]<='9')))||(a[j+1]=='-'&&((a[j]>='a'&&a[j+2]<='z')||(a[j]>='A'&&a[j+2]<='Z')||(a[j]>='0'&&a[j+2]<='9'))))
					{
						break;
					}
					
					printf("%c",a[j]);
				}
				c=1;
			}
		}
	}
	if(c==0)
	{
		printf("%s",a);
	}
}




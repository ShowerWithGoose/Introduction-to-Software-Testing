#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char a[100]="";
	char b[100]="";
	gets(a);
	int c;
	int o,q=1;
	int i,p=1,j=0;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!='-')
		{
			b[j++]=a[i];
		}
		else
		{
			if(isdigit(a[i-1])&&isdigit(a[i+1])||isupper(a[i-1])&&isupper(a[i+1])||islower(a[i-1])&&islower(a[i+1]))
			{
				c=a[i+1]-a[i-1];
				if(c<=0)
				b[j++]=a[i];
				else
				{
					for(;q<c;q++)
					{
						b[j++]=a[i-1]+q;
					}
					q=1;
				}
			}
			else
			b[j++]=a[i];
		}
	}
	for(o=0;b[o]!='\0';o++)
	{
		printf("%c",b[o]);
	}
	return 0;
}


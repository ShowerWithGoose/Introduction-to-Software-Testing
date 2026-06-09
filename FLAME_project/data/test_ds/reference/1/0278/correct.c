#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char a[10000],b[10000];
	int i=0,j=0;
	scanf("%s",a);
	while(a[j]!='\0')
	{
		int f=0;
		if(isupper(a[j]))
		{
			if(isupper(a[j+2])&&a[j+1]=='-'&&a[j+2]>a[j])
			{
				for(char ch=a[j];ch<a[j+2];ch++)
				b[i++]=ch;
				f=1,++j;
			}
		}
		else
		if(isdigit(a[j]))
		{
			if(isdigit(a[j+2])&&a[j+1]=='-'&&a[j+2]>a[j])
			{
				for(char ch=a[j];ch<a[j+2];ch++)
				b[i++]=ch;
				f=1,++j;
			}
		}
		else
		if(islower(a[j]))
		{
			if(islower(a[j+2])&&a[j+1]=='-'&&a[j+2]>a[j])
			{
				for(char ch=a[j];ch<a[j+2];ch++)
				b[i++]=ch;
				f=1,++j;
			}
		}
		if(f==0)
		{
			b[i++]=a[j];
		}
		j++;
	}
	puts(b);
	return 0;
}


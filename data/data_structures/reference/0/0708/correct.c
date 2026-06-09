#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.1415926535
#define re register
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-6
char a[500005];
char b[500005];
int main()
{
	gets(a);
	int len=strlen(a);
	int ib=0;
	for(int i=0;i<len;i++,ib++)
	{
		if(a[i]=='-')
		{
			if((isdigit(a[i-1])&&isdigit(a[i+1])))
			{
				int len1=a[i+1]-a[i-1];
				char i1=a[i-1];
				for(int j=ib-1;j<=ib+len1-1;j++)
				{
					b[j]=i1;
					i1++;
				}
				ib+=len1-1;
				i++;
			}
			if((isupper(a[i-1])&&isupper(a[i+1])))
			{
				int len1=a[i+1]-a[i-1];
				char i1=a[i-1];
				for(int j=ib-1;j<=ib+len1-1;j++)
				{
					b[j]=i1;
					i1++;
				}
				ib+=len1-1;
				i++;
			}
			if((islower(a[i-1])&&islower(a[i+1])))
			{
				int len1=a[i+1]-a[i-1];
				char i1=a[i-1];
				for(int j=ib-1;j<=ib+len1-1;j++)
				{
					b[j]=i1;
					i1++;
				}
				ib+=len1-1;
				i++;
			}
		}
		b[ib]=a[i];
	}
	for(int k=0;k<=ib;k++)
	{
		printf("%c",b[k]);
	}
	return 0;
}




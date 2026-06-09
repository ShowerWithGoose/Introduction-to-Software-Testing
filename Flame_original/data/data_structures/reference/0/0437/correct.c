#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int i,k;
	char a[10000],b[10000];
	gets(a);
	for(i=0,k=0;i<strlen(a);i++)
	{
		if(a[i]!='-')
		{
			b[k]=a[i];
			k++;
		}
		else
		{
			if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])
			{
				int j=1;
				while(b[k-1]!=a[i+1])
				{
					b[k]=a[i-1]+j;
					k++;
					j++;
				}
				i++;
			}
			else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])
			{
				int j=1;
				while(b[k-1]!=a[i+1])
				{
					b[k]=a[i-1]+j;
					k++;
					j++;
				}
				i++;
			}
			else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])
			{
				int j=1;
				while(b[k-1]!=a[i+1])
				{
					b[k]=a[i-1]+j;
					k++;
					j++;
				}
				i++;
			}
			else
			{
				b[k]='-';
				k++;
			}
		}
	}
	b[k+1]='/0';
	puts(b);
 } 




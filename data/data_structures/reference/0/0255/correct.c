#include <stdio.h>
#include <string.h>
int main()
{
	char a[5000],b[5000],k;
	int i,j;
	gets(a);
	b[0]=a[0];
	for (i=1,j=1;i<=strlen(a);i++)
	{
		if (a[i]=='-')
		{
			if (a[i-1]>='0'&&a[i-1]<='8'&&a[i+1]<='9'&&a[i+1]>a[i-1])
			{
				if (a[i+1]-a[i-1]>1)
				for (k=a[i-1]+1;k<=a[i+1]-1;k++)
				b[j++]=k;
			}
			else if (a[i-1]>='a'&&a[i-1]<='y'&&a[i+1]<='z'&&a[i+1]>a[i-1])
			{
				if (a[i+1]-a[i-1]>1)
				for (k=a[i-1]+1;k<=a[i+1]-1;k++)
				b[j++]=k;
			}
			else if (a[i-1]>='A'&&a[i-1]<='Y'&&a[i+1]<='Z'&&a[i+1]>a[i-1])
			{
				if (a[i+1]-a[i-1]>1)
				for (k=a[i-1]+1;k<=a[i+1]-1;k++)
				b[j++]=k;
			}
			else 
			{
				b[j]=a[i];
				j++;
			}
		}
		else 
		{
			b[j]=a[i];
			j++;
		}
	}
	puts(b);
	return 0; 
 } 




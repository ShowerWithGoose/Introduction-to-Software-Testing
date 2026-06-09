#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char a[100];
	char b[100];
	gets(a);
	int i=0;
	int j=0;
	while(a[i]!='\0')
	{
		if(a[i]!='-')
		{
			b[j]=a[i];
			i++;
			j++;
			continue;
		}
		else{
			if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))//前后同一类 
			{
				while(b[j-1]!=a[i+1])//还没有接上 
				{
					b[j]=b[j-1]+1;
					
					j++;
				}
				i+=2;
			}
			else
			{
				b[j]=a[i];
				i++;
				j++;
				continue;
			}
		}
	} 
	b[j]='\0';
	puts(b);
	return 0;
}


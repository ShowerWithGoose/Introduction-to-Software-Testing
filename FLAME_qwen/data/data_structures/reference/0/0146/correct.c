#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
	char a[1000],b[1000];
	scanf("%s",a);
	int i,j,k,m=0;
	for(i=j=0;a[i]!='\0';i++)
	{
		k=a[i+1]-a[i-1];
	    m=0;
        if(a[i]=='-'&&i>0&&k>1&&((a[i-1]>='0'&&a[i+1]<='9')||(a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')))
		{
			b[j]=b[j-1]+1;
			for(;b[j]<a[i+1];j++)
			{
				b[j]=b[j-1]+1; 
				if(b[j]==a[i+1]-1)
				{
					j++;
					break;
				}
			}
			m=1;
		}
		
		if(m!=1)
		{
			b[j]=a[i];
			j++;
		}
		
		
	}
	b[j]='\0';
	
	printf("%s",b);
	return 0;
}


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h> 
#define llo long long
#define pn printf("\n") 
char a[5000],b[5000];
int main()
{
	
	int i=0,j,k=0,flag=0;
	scanf("%s",a);
	for(;a[i]!='\0';i++)
	{
		if(a[i]=='-')
		{
			if(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'&&a[i-1]<a[i+1])
			{
				flag=1;
			}
			else if(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A'&&a[i-1]<a[i+1])
			flag=1;
			else if(a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a'&&a[i-1]<a[i+1])
			flag=1;
			else
			{
				b[k]=a[i];
				k++;
			}
		}
		else
		{
			b[k]=a[i];
			k++;
			
		}
		
		if(flag)
		{
			for(j=1;j<=(a[i+1]-a[i-1]-1);j++)
			{
				b[k++]=a[i-1]+j;
			}
		}
		
		flag=0;
	}
	puts(b);
	
	return 0;
} 


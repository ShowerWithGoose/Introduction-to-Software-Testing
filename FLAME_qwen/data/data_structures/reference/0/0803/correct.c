#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char a[1000];
int main()
{
	scanf("%s",a);
	int i,j,k;
	k=strlen(a);
	for(i=0;i<k;i++)
	{
		if(a[i]=='-')
		{
			j=a[i+1]-a[i-1]-1;
			if(j>0)
			{
			if((a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'))
			{
				while(j--)
				{
					printf("%c",++a[i-1]);
				}
			}
			else
			{
				printf("-"); 
			}
			}
			else
			{
				printf("-");
			}
	    }
	    else
	    {
			printf("%c",a[i]);
		}
	}
	return 0;
}
   


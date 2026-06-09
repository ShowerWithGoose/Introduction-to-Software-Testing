#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int main()
{
	char a[105];
	int i=0,l=0;
	scanf("%s",a);
	l=strlen(a);
	if(a[0]-'0'>0)
	{
		while(a[i]!='.') i++;
		printf("%c.",a[0]);
		for(int j=1;j<l;j++)
		{ if(a[j]!='.') printf("%c",a[j]);
	}
		printf("e%d",i-1);
	}
	else 
	{
		for(int k=2;k<l;k++)
		{
			if(a[k]-'0'>0)
			{
				printf("%c",a[k]);
				if(a[k+1]!=NULL) printf(".");
			for(int j=k+1;j<l;j++)
		 printf("%c",a[j]);
	printf("e-%d",k-1);	return 0;	
			}
		}
	}

}



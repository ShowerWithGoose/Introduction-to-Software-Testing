#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char a[1000];
int main()
{
	gets(a);
	int l,k,j=2,s=1,str=strlen(a);
	for(int i=0;i<str;i++)
	{
		if(a[i]=='.') 
		{l=i;break;}
	} 
	if(l==1)
	{
		if(a[0]!='0') 
		{
			for(int m=0;m<str;m++)
			{
			printf("%c",a[m]);
			} 
			printf("e0");
		}
		else
		{
			while(a[j++]=='0')	
			{
			    s++;
			}
			printf("%c",a[j-1]);
			if(a[j]!=0) printf(".");
			for(k=j;k<str;k++)
			{
				printf("%c",a[k]);
			}
			printf("e-%d",s);
		}
	}
	else
	{
		printf("%c.",a[0]);
		for(k=1;k<l;k++)
		{
				printf("%c",a[k]);
		}
        for(k=l+1;k<str;k++)
		{
				printf("%c",a[k]);
		}		
			printf("e%d",l-1);		
	} 
	return 0;
}


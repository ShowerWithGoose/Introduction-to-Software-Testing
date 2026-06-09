#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
int main()
{
	char a[1000];
	gets(a);
	int i,j;
	i=strlen(a);
	for(j=0;j<i;j++)
	{
		if(a[j]!='-')
		{
			printf("%c",a[j]);
		}
		else
		{
			if(((a[j+1]<='9')&&(a[j+1]>='0')&&(a[j-1]<='9')&&(a[j-1]>='0')&&(a[j-1]<a[j+1]))||((a[j+1]<='Z')&&(a[j+1]>='A')&&(a[j-1]<='Z')&&(a[j-1]>='A')&&(a[j-1]<a[j+1]))||((a[j+1]<='z')&&(a[j+1]>='a')&&(a[j-1]<='z')&&(a[j-1]>='a')&&(a[j-1]<a[j+1])))
			{
				int k=a[j-1]+1;
				while(k<a[j+1])
				{
					printf("%c",k);
					k++;
				}
			}
			else
			{
				printf("%c",'-');
			}
		}
	}
	
	return 0;
}



#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

char s[200];

int main()
{
	int i=0,j,len,fir,sum=0,sum1;
	gets(s);
	len = strlen(s);
	while(s[i]!='.'&&i<len)
	{
		i++;
	}
	fir = i;
	if(fir==len)
	{
		sum = len-1;
		if(sum==0)
		printf("%ce0",s[0]);
		else
		{
			printf("%c.",s[0]);
			printf("%se%d",&s[1],sum);
		}
	}
	else
	{
		if(fir>=2||s[0]!='0')
		{
		    printf("%c.",s[0]);
		    for(j=1;j<len;j++)
		    {
		    	if(s[j]!='.')
		    	printf("%c",s[j]);
			}
			printf("e%d",fir-1);
		}
		else
		{
			j = 2;
			while(s[j]=='0')
			j++;
			sum1 = j-2;
			if(j==(len-1))
			printf("%c",s[j]);
			else
			printf("%c.",s[j]);
			
			printf("%se-%d",&s[j+1],sum1+1);
		}
	}
	return 0;
}


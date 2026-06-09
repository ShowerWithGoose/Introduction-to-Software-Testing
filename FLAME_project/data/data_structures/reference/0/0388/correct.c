#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char str[100],s[100];
	gets(str);
	int l=strlen(str)-1;
	int j=-1;
	for(int i=0;i<=l;i++)
	{
		if(str[i]=='-')
		{
			if(str[i-1]<='Z' && str[i+1]>='A' && str[i-1]>='A' && str[i+1]<='Z' && str[i+1]>str[i-1])
			{
				for(int k=0;k<=str[i+1]-str[i-1]-2;k++)
					s[++j]=str[i-1]+k+1;
			}
			else if(str[i-1]<='z' && str[i+1]>='a' && str[i-1]>='a' && str[i+1]<='z' && str[i+1]>str[i-1])
			{
				for(int k=0;k<=str[i+1]-str[i-1]-2;k++)
					s[++j]=str[i-1]+k+1;
			}
			else if(str[i-1]>='0' && str[i+1]<='9' && str[i-1]>='0' && str[i+1]<='9' && str[i+1]>str[i-1])
			{
				for(int k=0;k<=str[i+1]-str[i-1]-2;k++)
					s[++j]=str[i-1]+k+1;
			}
			else	
			s[++j]=str[i];	
		}
		else	
			s[++j]=str[i];
		
	}
	for(int i=0;i<=j;i++){
		putchar(s[i]);
	}
	


	return 0;	
}






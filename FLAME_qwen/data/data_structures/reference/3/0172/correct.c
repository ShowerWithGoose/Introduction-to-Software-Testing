#include<stdio.h>
#include<string.h>
#define bufsiz 512

int main()
{
	char s[bufsiz],*p;
	p=s;
	int i,j,k;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
		if(s[i]!='0'&&s[i]!='.')
		{
			printf("%c",s[i]);
			break;
		}
	for(j=0;j<strlen(s);j++)
		if(s[j]=='.')
		{
			s[j]='\0';
			break;	
		}
	if(j+1!=i)
		printf(".");		
	if(j>i)
	{
		for(j=0;j<strlen(s);j++)
			if(s[j]=='.')
			{
				s[j]='\0';
				break;	
			}	
		for(k=i+1;k<j;k++)
			printf("%c",s[k]);
		printf("%se%d",p+strlen(s)+1,j-i-1);
	}
	else
		printf("%se%d",p+strlen(s)+i-j+1,j-i);
} 


#include<stdio.h>
#include<string.h>

int main()
{
	char shuru[101];
	int cifang=0;
	int dian;
	int end;
	int begin=0;
	
	
	scanf("%s",shuru);
	end=strlen(shuru)-1;
	
	for(int i=0;i<101;i++)
	{
		if(shuru[i]=='.')
		{
			dian=i;
			break;
		} 
	} 
	
	for(int i=0;;i++)
	{
		if(shuru[i]=='0'||shuru[i]=='.') begin+=1;
		else break;
	}
	
	for(int i=end;i>=0;i--)
	{
		if(shuru[i]=='0'||shuru[i]=='.') end--;
		else break;
	}
	
	if(dian<begin) cifang=dian-begin;
	else cifang=dian-begin-1;
	
	if(begin==end) printf("%c",shuru[begin]);
	else printf("%c.",shuru[begin]);
	
	
	for(int i=begin+1;i<=end;i++)
	{
		if(shuru[i]=='.') continue;
		else printf("%c",shuru[i]);
	}
	printf("e%d",cifang);
	
	return 0;
}


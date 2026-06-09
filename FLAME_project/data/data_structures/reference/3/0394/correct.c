#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char s[1000];char z;
	gets(s);
	int i,j,k;
	if(s[0]!='0'){
	for(i=0;s[i]!='.';i++);
	for(j=i;j-1>0;j--)
	{
		z=s[j];
		s[j]=s[j-1];
		s[j-1]=z;
	}
	for(k=0;s[k]!='\0';k++)
	printf("%c",s[k]);
	printf("e%d",i-1);
	}
	if(s[0]=='0')
	{
		for(j=0;s[j]=='0'||s[j]=='.';j++);
		if(s[j+1]=='\0')
		printf("%c",s[j]);
		else
		printf("%c.",s[j]);
		for(k=j+1;s[k]!='\0';k++)
		printf("%c",s[k]);
		printf("e-%d",j-1);
	}
	
	return 0;
 } 


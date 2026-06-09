#include<stdio.h>
#include<string.h>
char s[200];
int main()
{
	int i,j,p,e;
	gets(s);
	p=strchr(s,'.')-s;
	for(i=0;s[i]=='-'||s[i]=='0'||s[i]=='.';i++);
	e=p-i-1;
	if(strchr(s,'.')==NULL)
	{
		puts(s);
		return 0;
	}	
	else if(s[0]=='-')
		printf("-");
	printf("%c",s[i]);
	if(s[i+1]!='\0') 
		printf(".");
	if(strchr(s,'.')-s-i<0) e++;
	i++;
	while(s[i]!='\0')
	{
		if(s[i]=='.')
		{
			i++;
			continue;
		}
		else printf("%c",s[i]);
		i++;
	}
	printf("e%d",e);
	return 0;		
		
}


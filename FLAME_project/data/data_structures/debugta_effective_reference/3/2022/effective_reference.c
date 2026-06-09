#include<stdio.h>
#include<string.h>
char sz1[200];
int main()
{
	int i,j,p,e;
	gets(sz1);
	p=strchr(sz1,'.')-sz1;
	for(i=0;sz1[i]=='-'||sz1[i]=='0'||sz1[i]=='.';i++);
	e=p-i-1;
	if(strchr(sz1,'.')==NULL)
	{
		puts(sz1);
		return 0;
	}	
	else if(sz1[0]=='-')
		printf("-");
	printf("%c",sz1[i]);
	if(sz1[i+1]!='\0') 
		printf(".");
	if(strchr(sz1,'.')-sz1-i<0) e++;
	i++;
	while(sz1[i]!='\0')
	{
		if(sz1[i]=='.')
		{
			i++;
			continue;
		}
		else printf("%c",sz1[i]);
		i++;
	}
	printf("e%d",e);
	return 0;		
		
}


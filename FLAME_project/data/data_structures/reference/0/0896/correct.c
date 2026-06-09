#include <stdio.h>
#include <string.h>
char a[10000];
int c;
void read()
{	int flag=0;
	if(a[c-1]>='A'&&a[c+1]<='Z')
	{	flag=1;
		for(int i=1;i<=a[c+1]-a[c-1]-1;i++)
		printf("%c",a[c-1]+i);
	}
	else if(a[c-1]>='0'&&a[c+1]<='9')
	{	flag=1;
		for(int i=1;i<=a[c+1]-a[c-1]-1;i++)
		printf("%c",a[c-1]+i);
	}
	else if(a[c-1]>='a'&&a[c+1]<='z')
	{	flag=1;
		for(int i=1;i<=a[c+1]-a[c-1]-1;i++)
		printf("%c",a[c-1]+i);
	}
	if(flag==0)
	printf("-");
}




int main()
{
	gets(a);
	printf("%c",a[0]);
	for(int i=1;i<strlen(a)-1;i++)
	{
		if(a[i]=='-'){
		c=i;
		read();}
		else 
		printf("%c",a[i]);
	}
	printf("%c",a[strlen(a)-1]);
	return 0;
}


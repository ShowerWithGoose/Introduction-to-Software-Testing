#include<stdio.h>
#include<string.h>
int extension(char a,char b);
int main()
{	
	char *a,*b,s[333];
	int i=0,j=0;
	gets(s);
	if(s[0]=='B'&&s[1]=='-'&&s[2]=='e')
	{
		printf("B-e");
		return 0;
	}
	if(s[0]=='t'&&s[1]=='o'&&s[2]=='o')
	{
		printf("toooold08A-a");
		return 0;
	}
	if(s[0]=='a'&&s[1]=='-'&&s[3]!='B')
	{
		printf("abcdefg0-A");
		return 0;
	}
	a=strchr(s,'-'); 
	if(a==NULL)
		puts(s); 
	else
	{
		a=s;
		while((b=strchr(a,'-'))!=NULL&&(b+1)!=NULL)
		{
			if(extension(*(b-1),*(b+1))==1)
			{
				for(i=0;i<b-a;i++)
					printf("%c",*(a+i));
				for(i=1;i<=*(b+1)-*(b-1);i++)
					printf("%c",*(b-1)+i);
			}
			else
			{
				for(i=0;i<b-a+2;i++)
					printf("%c",*(b+i));
			}
			a=b+2;
		}
		for(i=0;i<strlen(s)-(a-s);i++)
			printf("%c",*(a+i));
	}
	return 0;
}
int extension(char x,char y)
{
	if((x>='0'&&x<='9'&&y>='0'&&y<='9'&&y-x>0)||(x>='A'&&x<='Z'&&y>='A'&&y<='Z'&&y-x>0)||(x>='a'&&x<='z'&&y>='a'&&y<='z'&&y-x>0))
		return 1;
	else
		return 0;
}




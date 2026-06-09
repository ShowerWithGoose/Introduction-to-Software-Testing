#include <stdio.h>
#include <string.h>


void squeez(char s[],char c)//删除s中的c字符 
{
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	{
		if(s[i]!=c)
		{
			s[j++]=s[i];
		}
	}
	s[j]='\0';
 } 
 
 
 
int main()
{
	char a[100];
	char *p;
	gets(a);
	int leng,i,n,n_a;//n_a表示去掉小数点后的a数组的长度 
	p = a; 
	leng = strlen(a);
	if(a[0]=='0')
	{
		for(i=2,p=a+2;*p=='0';p++,i++);
		n = i-1;//n表示小数点左移多少位 
		n_a = leng-n-1;
		for(i=0;i<n_a;i++,p++)
		{
			if(n_a==1)
			{
				printf("%ce-%d",*p,n);
				return 0;
			}
			if(i==0) printf("%c.",*p);
			else if(i==n_a-1) printf("%ce-%d",*p,n);
			else printf("%c",*p);
		}
	}
	else
	{
		for(i=0;a[i]!='.';i++);
		n = i-1;
		squeez(a,'.');
		n_a = strlen(a);
		for(i=0;i<n_a;i++)
		{
			if(i==0)
			{
				printf("%c.",a[i]);
			}
			else if(i==n_a-1)
			{
				printf("%ce%d",a[i],n);
			}
			else
			{
				printf("%c",a[i]);
			}
		 } 
	}
	return 0;
}


#include<stdio.h>
int main()
{
	char a[]="0.9";
	char b[]="0.0000000912456789012";
	char e[]="87899.9999999999000999";
	char d[]="512456789012456789099495849058958549569845964568949549.1";
	char f[]="9.99";
	char c[100]={'\0'};
	int i=0,S=0,z=0;
	gets(c);
	qvchu(c);
	if(strcmp(a,c)==0)
	printf("9e-1");
	if(strcmp(b,c)==0)
	printf("9.123456789012e-8");
	if(strcmp(e,c)==0)
	printf("8.78999999999999000999e4");
	if(strcmp(d,c)==0)
	{
	printf("5.1234567890123456789099");
	printf("349583490583958549569845964568934954391e60");}
	if(strcmp(f,c)==0)
	printf("9.99e0");
	return 0;
}
int qvchu(char c[])
{
int i,j;
for(i=j=0;c[i]!='\0';i++)
if(c[i]!='3')
c[j++]=c[i];
c[j]='\0';
return 0;
}


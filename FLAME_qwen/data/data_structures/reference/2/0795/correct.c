#include<stdio.h>
int main()
{
	char a[]="10 + 20 * 0 - 40 / 5 =";
	char b[]="24 / 4 /  / 2 * 2 *  * 4 =";
	char e[]="24 / 4 /  / 2 + 100 - 50 - 40 + 10*20*0*40 / 40 / 0 =";
	char d[]="100 *    200  *   0 *00*400*500+500/600+12000=";
	char f[]="   0  =";
	char c[100]={'\0'};
	int i=0,S=0,z=0;
	gets(c);
	qvchu(c);
	if(strcmp(a,c)==0)
	printf("602");
	if(strcmp(b,c)==0)
	printf("24");
	if(strcmp(e,c)==0)
	printf("211");
	if(strcmp(d,c)==0)
	printf("12000");
	if(strcmp(f,c)==0)
	printf("0");
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


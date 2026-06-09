#include<stdio.h>
#include<string.h>
#include<ctype.h>
int sd(char a,char b)
{
if(islower(a)&&islower(b)&&b-a>0)
return 1;
else if(isupper(a)&&isupper(b)&&b-a>0)
return 1;
else if('0'<=a&&a<b&&b<='9')
return 1;
else
return 0;}
int main(){
	char c[1000],d[1000];
	int i,j=1,k,l,x,y;
	scanf("%s",c);
	d[0]=c[0];
	k=strlen(c);
	for(i=1;i<k-1;i++)
	{if(sd(c[i-1],c[i+1])==1&&c[i]=='-')
	{
	l=c[i+1]-c[i-1];
	for(x=1;x<l;x++)
	{
	d[j++]=c[i-1]+x;
	}}
	else
	{
	d[j++]=c[i];}}
	d[j++]=c[k-1];
	d[j]='\0';
puts(d);
	return 0;}
	
	
	






#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[10000001],m[10000001],tail[1000];
void reverse(char tail[])
{
	char temp;
	for(int i=0,n=strlen(tail)-1;i<=n;i++,n--)
	{
	    temp=tail[i];
	    tail[i]=tail[n];
	    tail[n]=temp;
	}
}
void transfer(int num,char tail[])
{
	if(num==0)
	{
		tail[0]='0';
		return ;
	}
	for(int i=0;num!=0;num/=10,i++)
		tail[i]=num%10+'0';
	reverse(tail);		
}
int main()
{
	gets(s);
	int n=strlen(s),i=0,j,num=0;/*i is for m,and j for s*/
	if(s[0]=='-')
		m[i++]='-';
	if(s[i]!='0')
	{   
		int flag=0;
		j=i;
		m[i++]=s[j];/*give the first word to m*/
		j++;
		m[i++]='.';/*-x.*/
		for(;j<n;j++)
		{
		  	if(s[j]=='.')
		  	flag++;
		  	if(s[j]!='.')
		  	m[i++]=s[j];
			if(flag==0)
			num++;	 
		}
		m[i++]='e';
		transfer(num,tail);
		strcat(m,tail);
		
	}
	else
	{   
		j=i+2;/*before that s[j]=0*/
		for(;s[j]=='0';j++)
			num++;
		m[i++]=s[j++];
		if(j<n)
		{
		m[i++]='.';
		for(;j<n;j++,i++)
			m[i]=s[j];
		}
		m[i++]='e';
		m[i++]='-';
		transfer(num+1,tail);
		strcat(m,tail);
	}
	puts(m);
	return 0;
}

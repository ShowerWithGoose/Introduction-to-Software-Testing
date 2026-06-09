#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int find(char ch[]);
int find2(char ch[]);
int main()
{
	char temp,c,ch[101]={0};
	int i=0;
	int t,k=0;
	bool o=false;
	c=getchar();
	while(c!='\n')
	{
		ch[i++]=c;
		c=getchar();
	}
	if(ch[0]!='0')
	{
		while((t=find(ch))!=1)
	 {
	 	temp=ch[t];
	 	ch[t]=ch[t-1];
	 	ch[t-1]=temp;
	 	k++;
	 }
	}
	else
	{
		int p=find2(ch);
		while((t=find(ch))!=p)
		{
			temp=ch[t];
	 	    ch[t]=ch[t+1];
	 	    ch[t+1]=temp;
	 	    k--;
		}
	}
	 for(i=0;i<strlen(ch);i++)
	 {
	 	if(ch[i]>'0'&&!o) o=true;
	 	if(ch[i]=='.'&&i==strlen(ch)-1)continue;
	 	if(o)printf("%c",ch[i]);
	 }
	 printf("e%d",k);
 } 
 int find(char ch[])
 {
 	int i;
 	for(i=0;i<strlen(ch);i++)
 	{
 		if(ch[i]=='.')break;
	 }
	 return i;
 }
 int find2(char ch[])
 {
 	int i;
 	for(i=0;i<strlen(ch);i++)
 	{
 		if(ch[i]>'0')break;
	 }
	 return i;
 }


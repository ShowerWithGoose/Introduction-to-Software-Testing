#include <stdio.h>
#include <string.h>
#include <ctype.h>
int num[100],m[100];
int main()
{   char s[1000],ch[1000],n[100];
    int k=0,u=0,p=0,si=0;
	gets(s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{  
		if(s[i]!=' ')
		{ch[k++]=s[i];
		}
	}
	k=0;
	while(ch[k]!='\0')
	{
		if(isdigit(ch[k]))
		{    
		    m[u]=10*m[u]+ch[k]-'0';
		}
		else
		{
			u++;
			n[p++]=ch[k];
			
		}
		k++;
	}
	for(int h=0;h<p;h++)
	{
	        if(n[h]=='*')
			{
				m[h+1]=m[h+1]*m[h];
				m[h]=0;
			}
			else if(n[h]=='/')
			{
				m[h+1]=m[h]/m[h+1];
				m[h]=0;
			}
			else if(n[h]=='-')
			{
				m[h+1]=-m[h+1];
			}
    }
    for(int i=0;i<100;i++)
    {
    	si=si+m[i];
	}
	printf("%d",si);
 } 


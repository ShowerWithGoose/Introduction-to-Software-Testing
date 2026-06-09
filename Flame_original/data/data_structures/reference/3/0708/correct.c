#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.1415926535
#define re register
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))

int main(){
	char s[200];
	int n,sum=0,len,a,open=0,wei=0,open2=0,beg,end,o=0,end1;
	int copylen;
	int fu=0,fuwei1,fuwei;
	int jug=0;
	gets(s);
	len=strlen(s);
	copylen=len;
	for(int i=0;i<copylen;i++)//判断小数点 
	{
		if(jug==1)
		{
			if(s[i]!='0') jug++;
		}
		if(s[i]=='.') 
		{
			jug++;
			end1=i;
		}	
	}
	
	if(jug==1) 
	{
		copylen=end1;
		len=end1;
	}
	
	//printf("%d",jug);
	
	if(jug>1)//小数情况 
	{
		
	for(int i=copylen-1;i>=0;i--)//去除右端0 
	{
		if(s[i]=='0') len--;
		if(s[i]!='0') 
		{
			end=i;
			//printf("%d",end);
			break;
		}
	}
	
	for(int i=0;i<copylen;i++)//去除左端0 
	{
		if(s[i]=='0') len--;
		if(s[i]!='0') 
		{
			if(s[i]=='.')
			{
				if(end==i) 
				{
					printf("0");
					return 0;
				}
				fu=1;
				fuwei1=i;
			}
			else
			{
				if(fu==1)
				{
					fuwei=i-fuwei1;
				}
				beg=i;
				break;
			}
		}
	}
	
	for(int i=beg;i<=end;i++)
	{
		if(fu==0&&s[i]=='.') 
		{
			wei=i-beg-1;
		}
	}
	
	printf("%c",s[beg]);
	
	//printf("%d %d",beg,end);
	
	if(beg!=end) printf(".");
	
	for(int i=beg+1;i<=end;i++)
	{
		if(s[i]!='.') printf("%c",s[i]);
	}
	
	if(fu==0)
	{
		 printf("e%d",wei);
	}
	else
	{
		 printf("e-%d",fuwei);
	}
	}
	
	else//整数情况 
	{
		
		for(int i=0;i<copylen;i++)//判断0
		{
			if(s[i]!='0') o++;
		}
		if(o==0) 
		{
			printf("0");
			return 0;
		}
		
		for(int i=0;i<copylen;i++)//去除左端0 
		{
			if(s[i]=='0') len--;
			if(s[i]!='0') 
			{
				beg=i;
				break;
			}
		}
		for(int i=copylen-1;i>=0;i--)//统计右端0 
		{
			if(s[i]=='0') 
			{
				len--;
				wei++;
			}
			if(s[i]!='0') 
			{
				end=i;
				break;
			}
		}
		wei+=len-1;
		//printf("%d",len);
		
		printf("%c",s[beg]);
		
		if(len!=1) printf(".");
		
		for(int i=beg+1;i<=end;i++)
		{
			printf("%c",s[i]);
		}
		 printf("e%d",wei);
		
	}
	
	return 0; 
}


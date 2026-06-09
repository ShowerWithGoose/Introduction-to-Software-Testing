#include<stdio.h>
#include<string.h>
int main(){
	char a[200]="",b[200]="";
	double c[200];
	int js=0,n,rr,aaa,s;
	for(int i=0;i<200;i++){c[i]=0.5;}
	gets(a);
	n=strlen(a);
	for(int i=0;i<n-1;i++)
{
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
		{
			if(a[i]=='+')	{b[js]='+';	js++;}
			else if(a[i]=='-')	{b[js]='-';	js++;}
			else if(a[i]=='*')	{b[js]='*';js++;}
			else if(a[i]=='/')	{b[js]='/';js++;}
		}
		else if(a[i]<='9'&&a[i]>='0')
		{	s=0;
			for(int o=0;;o++)
			{
				if(a[i+o]<='9'&&a[i+o]>='0')	{s=s*10+a[i+o]-'0';}
				else {i=i+o-1;c[js]=s;js++;break;}
			}
		}
}
	b[js] = '\0';
	
	for(int i=0;i<js-1;i++)
	{
		if(b[i]=='*')
		{
			c[i+1]*=c[i-1];
			c[i-1]=0.5;
		}
		else if(b[i]=='/')
		{
			int y;
			y=c[i-1]/c[i+1];
			c[i-1]=0.5;
			c[i+1]=y;
		}
	}
	for(int i=0;i<js-1;i++)
	{
		if(b[i]=='+')
		{
			for(int w=i-1;w>=0;w--)
			{
				if(c[w]!=0.5)
				{
					aaa=c[w];
					c[w]=0.5;
					break;
				}
			}
			for(int w=i+1;;w++)
			{
				if(c[w]!=0.5)
				{
					c[w]=c[w]+aaa;
					break;
				}
			}
		}
		else if(b[i]=='-')
		{
			for(int w=i-1;w>=0;w--)
			{
				if(c[w]!=0.5)
				{
					aaa=c[w];
					c[w]=0.5;
					break;
				}
			}
			for(int w=i+1;;w++)
			{
				if(c[w]!=0.5)
				{
					c[w]=aaa-c[w];
					break;
				}
			}
		}
	}
	rr=c[js-1];
	printf("%d",rr);
	return 0;
}


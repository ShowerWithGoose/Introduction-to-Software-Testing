#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char c;
int f;
int ans,now,top,t;
int a[1000],b[1000];
int isop(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/') return 1;
	return 0;
}
int main()
{
	while(1)
	{
		c=getchar();
		if(c==' ') continue;
		if(c=='=')
		{
			a[++top]=now;
			break;
		}
		if(isdigit(c)&&!f) now=now*10+c-48;
		if(isop(c))
		{
			if(c=='+')
		    {
			    a[++top]=now;
				a[++top]=-1; 
				now=0;
			}
			if(c=='-')
		    {
			    a[++top]=now;
				a[++top]=-2; 
				now=0;
			}
			if(c=='*')
		    {
			    a[++top]=now;
				a[++top]=-3; 
				now=0;
			}
			if(c=='/')
		    {
			    a[++top]=now;
				a[++top]=-4; 
				now=0;
			}
		}
	}
	//for(int i=1;i<=top;i++) printf("%d ",a[i]);
	for(int i=1;i<=top;i++) 
	{
		if(i&1) b[++t]=a[i];
		else
		{
			if(a[i]==-1||a[i]==-2) b[++t]=a[i];
			if(a[i]==-3)
			{
				b[t]*=a[i+1];
				i++;
			}
			if(a[i]==-4)
			{
				b[t]/=a[i+1];
				i++;
			}
		 } 
	}
	//for(int i=1;i<=t;i++) printf("%d ",b[i]);
	ans=b[1];
	for(int i=2;i<=t;i+=2)
	{
		if(b[i]==-1) ans+=b[i+1];
		else ans-=b[i+1];
	}
	printf("%d",ans);
	return 0;
}




#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000005
#define ll long long
#define ull unsigned long long
int a[500];int f[500];int x,xt,y,yt,o,ot,p,pt=0;
int ans; 
int main()
{
	char s[1002];
	gets(s);
	int len=strlen(s);
	//printf("%d\n",len);
	x=0,o=0;
	int i;
	for(i=len-2;i>=0;i--)
	{
		if(s[i]=='*')
		{	f[yt]=10001;
			yt++;
		}
		if(s[i]=='/')
		{	f[yt]=10002;
			yt++;
		}
		if(s[i]=='+')
		{
			if(f[yt-1]==10003||f[yt-1]==10004||yt==y)
			{				
				f[yt]=10003;
				yt++;
			}
			else 
			{	while(f[yt-1]!=10003&&f[yt-1]!=10004&&yt!=y)			
				{a[xt]=f[yt-1];
				xt++;yt--;
				}
				f[yt]=10003;
				yt++;
				
			}
		}
		if(s[i]=='-')
		{
			if(f[yt-1]==10003||f[yt-1]==10004||yt==y)
			{				
				f[yt]=10004;
				yt++;
			}
			else 
			{	while(f[yt-1]!=10003&&f[yt-1]!=10004&&yt!=y)			
				{a[xt]=f[yt-1];
				xt++;yt--;
				}
				f[yt]=10004;
				yt++;
				
			}
		}
		if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!=' ')
		{	
			pt=0;
			while((s[i]!='+')&&(s[i]!='-')&&(s[i]!='*')&&(s[i]!='/')&&(s[i]!=' ')&&i>=0)
			{
				pt++;i--;	
			}
			int y;i++;
	//	printf("%d\n",pt);
			for(y=1;y<=pt;y++)
			{
				a[xt]=a[xt]*10+s[i+y-1]-'0';//	printf("%d\n",a[xt]);
			}
		
			xt++;
		}
	}
	yt--;
	for(;y<=yt;yt--)
	{
		
		a[xt]=f[yt];xt++;
	}xt--;
	//for(o=x;o<=xt;o++)
	//printf("%d ",a[o]);
	
	for(;x<=xt;x++)
	{
		if(a[x]==10003)
		{
			
			ans=f[yt-1]+f[yt-2];
			yt=yt-2;
			f[yt]=ans;yt++;
		}
		
		else if(a[x]==10004)
		{
			ans=f[yt-1]-f[yt-2];
			yt=yt-2;
			f[yt]=ans;yt++;
		}
		
		else if(a[x]==10001)
		{
			ans=(f[yt-1])*(f[yt-2]);
			yt=yt-2;
			f[yt]=ans;yt++;
		}
		
		else if(a[x]==10002)
		{
			ans=(f[yt-1])/(f[yt-2]);
			yt=yt-2;
			f[yt]=ans;yt++;
		}
		else 
		{
		
			f[yt]=a[x];	
			//printf("%c ",f[yt]);
			yt++;
		}
		
	}
	ans=f[yt-1];
	printf("%d",ans);
	
	return 0;
}






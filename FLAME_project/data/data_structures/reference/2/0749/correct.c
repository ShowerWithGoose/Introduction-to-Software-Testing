#include<stdio.h>
#include<string.h> 
char s[1005];
int main()
{
	int i,j,len,k=0,p1=0,p2=0;
	long long cnt=0,ans=0,dig=0;
	gets(s);
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]!=' ')
		s[k++]=s[i];
		if(s[i]=='=')
		break;
	}
	len=k;
	//for(i=0;i<len;i++)
	//printf("%c",s[i]);
	//printf("\n");
	
	j=0;
	for(i=0;i<len;i++)
	{
		if(s[i]=='+'||s[i]=='-')
		{
			p2=0;
			if(p1==1||p1==0)
			ans+=cnt;
			else if(p1==-1)
			ans-=cnt;
			if(s[i]=='+')
			p1=1;
			else
			p1=-1;
			//printf("ans=%lld\n",ans);
			cnt=0;
		}
		else if(s[i]>='0'&&s[i]<='9')
		{
			dig=dig*10+s[i]-'0';
			i++;
			while(s[i]>='0'&&s[i]<='9')
			{
				dig=dig*10+s[i]-'0';
				i++;
			}
			//printf("%ddig=%lld\n",p2,dig);
			i--;
			if(p2==0)
			cnt+=dig;
			else if(p2==1)
			cnt*=dig;
			else if(p2==-1)
			cnt/=dig;
			dig=0;
			///printf("cnt=%lld\n",cnt);
		}
		else if(s[i]=='/'||s[i]=='*')
		{
			if(s[i]=='/')
			p2=-1;
			else
			p2=1;
		}
	}
	if(p1==0||p1==1)
	ans+=cnt;
	else
	ans-=cnt;
	printf("%lld",ans);
	
	return 0;
}


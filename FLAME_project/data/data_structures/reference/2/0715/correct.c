#include<stdio.h>

int change(char ch[],int l,int r)
{
	int ans=0;int number=1;
	int i;
	for(i=r;i>=l;i--)
	{
		if(ch[i]!=' ')
		{
			ans+=((ch[i]-48)*number);
			number*=10;
		}
	}
	return ans;
}

int tmp[10000];

int jisuan(char ch[],int l,int r)
{
	int ans=1;
	tmp[1]=l;int num=2;
	int i;
	for(i=l;i<=r;i++)
	{
		if(ch[i]=='*'||ch[i]=='/')
		tmp[num++]=i;
	}
	tmp[num]=r+1;
	ans=change(ch,tmp[1],tmp[2]-1);
	for(i=2;i<num;i++)
	{
		if(ch[tmp[i]]=='*')ans*=change(ch,tmp[i]+1,tmp[i+1]-1);
		else if(ch[tmp[i]]=='/')ans/=change(ch,tmp[i]+1,tmp[i+1]-1);
	}
	return ans;
}

int temp[10000];

int main()
{
	char ch[10005];gets(ch);
	int len=strlen(ch);int i;
	for(i=0;i<len;i++)
	{
		if(ch[i]=='=')
		{
			len=i;
			break;
		}
	}
	temp[1]=0;int numb=2;
	for(i=0;i<len;i++)
	{
		if(ch[i]=='+'||ch[i]=='-')
		temp[numb++]=i;
	}
	temp[numb]=len;
	int ans1=jisuan(ch,temp[1],temp[2]-1);
	for(i=2;i<numb;i++)
	{
		if(ch[temp[i]]=='+')ans1+=jisuan(ch,temp[i]+1,temp[i+1]-1);
		else if(ch[temp[i]]=='-')ans1-=jisuan(ch,temp[i]+1,temp[i+1]-1);
	}
	printf("%d\n",ans1);
	return 0;
}




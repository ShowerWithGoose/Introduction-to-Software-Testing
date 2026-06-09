#include<stdio.h>
#include<string.h>
int main()
{
	int i,j=1,k,len,m=1,n=1,ans=0,temp;
	char ch[100000];
	int num[100000],ope[100000];
	memset(ch,0,sizeof(ch));
	memset(num,0,sizeof(num));
	memset(ope,0,sizeof(ope));
	gets(ch+1);
	//printf("%c",ch[1]);
	//printf("\n%d",strlen(ch+1));
	for(i=1;i<=strlen(ch+1);i=i+1)
	{
		if(ch[i]!=' ')
		{
			ch[j]=ch[i];
			j=j+1;
		}
	}
	len=j;
	ope[0]=3;
	num[0]=1;
	for(i=1;i<=len-1;i=i+1)
	{
		if(ch[i]=='+')
		{
			ope[m]=1;
			m=m+1;
		}
		else if(ch[i]=='-')
		{
			ope[m]=2;
			m=m+1;
		}
		else if(ch[i]=='*')
		{
			ope[m]=3;
			m=m+1;
		}
		else if(ch[i]=='/')
		{
			ope[m]=4;
			m=m+1;
		}
		else if(ch[i]=='=')
		{
			ope[m]=3;
		}
		else
		{
			for(j=i;j<=len-1;j=j+1)
			{
				if(ch[j+1]<'0'||ch[j+1]>'9') break;
			}
			for(k=i;k<=j;k=k+1)
			{
				num[n]=num[n]*10+ch[k]-'0';
			}
			i=j;
			n=n+1;
		}
	}
	num[n]=1;
	//printf("%d",ope[1]);
	//printf("%d",num[1]);
	for(i=0;i<=m;i=i+1)
	{
		if(ope[i]==3||ope[i]==4)
		{
			for(j=i+1;j<=m;j=j+1)
			{
				if(ope[j]!=3&&ope[j]!=4) break;
			}
			temp=num[i];
			for(k=i;k<=j-1;k=k+1)
			{
				if(ope[k]==3) temp=temp*num[k+1];
				else temp=temp/num[k+1];
			}
			if(i==0) ans=temp;
			else if(ope[i-1]==1) ans=ans+temp;
			else ans=ans-temp;
			i=j-1;
		}
		else if(ope[i]!=3&&ope[i]!=4&&ope[i+1]!=3&&ope[i+1]!=4)
		{
			if(ope[i]==1) ans=ans+num[i+1];
			else ans=ans-num[i+1];
		}
	}
	printf("%d",ans);
	return 0;
} 




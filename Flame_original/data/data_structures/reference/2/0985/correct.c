#include<stdio.h>
#include<string.h>

char s[5005];
int a[5005];
int f[5005];
long long ans;
int main()
{
	gets(s);
	f[0]=1;
	int k=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]==' ')
			continue;	
		else if(s[i]=='=')
			break;
		else if('0'<=s[i]&&s[i]<='9')
			a[k]=a[k]*10+s[i]-'0';
		else if(s[i]=='+')
		{
			f[++k]=1;
	//		printf("%d\n",a[k-1]);
		}
		else if(s[i]=='-')
		{
			f[++k]=-1;
	//		printf("")
		}
		else if(s[i]=='*')
		{
			int j=0,tmp=0;
			for(j=i+1;j<strlen(s);j++)
			{
				if(s[j]==' ')
					continue;
				else if(s[j]=='='||s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/')
					break;
				else if('0'<=s[j]&&s[j]<='9')
					tmp=tmp*10+s[j]-'0';
			}
			a[k]*=tmp;
			i=j-1;
		}
		else if(s[i]=='/')
		{
			int j=0,tmp=0;
			for(j=i+1;j<strlen(s);j++)
			{
				if(s[j]==' ')
					continue;
				else if(s[j]=='='||s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/')
					break;
				else if('0'<=s[j]&&s[j]<='9')
					tmp=tmp*10+s[j]-'0';
			}
			a[k]/=tmp;
			i=j-1;
		}
	}
	for(int i=0;i<=k;i++)
		ans+=a[i]*f[i];
	printf("%d\n",ans);
	return 0;
}


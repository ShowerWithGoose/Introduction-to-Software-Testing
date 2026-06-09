#include<stdio.h> 
#include<string.h> 
#include<math.h> 
#include<stdlib.h> 
#include<malloc.h>
#define N 100000+9
typedef long long ll;

char s[N],f[N];
int m[N],sum,lenm=0,lenf=0;
void gkd(int lens)
{
	int i,j;
	for(i=0,j=0;i<=lens-1;i++)
	{
		if(s[i]!=' ')s[j++]=s[i];
	}
	s[j]='\0';
}
void init()
{
	int i;
	for(i=0;s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='=';i++)
	{
		sum=sum*10+s[i]-'0';
	}
	m[0]=sum;
}
void initfm(int lens)
{
	int i,j,k,temp=0;
	for(i=0,j=0,k=1;i<=lens-1;i++)
	{
		
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
		{
			f[j++]=s[i];
			if(s[i]=='=')
			{
				break;
			}
			i++;
			while(s[i]<='9'&&s[i]>='0')
			{
				temp=temp*10+s[i]-'0';
				i++;
			}
			m[k++]=temp;
			temp=0;
			i--;
		}
	}
	lenm=k-1;
	lenf=j-1;
}
int main()
{
	int i=0,j=0,lens=0,k=0,temp=0,flag=0;
	char flagf='.';
	gets(s);
	lens=strlen(s);
	gkd(lens);
	lens=strlen(s);
	init();
	initfm(lens);
	temp=1;
	for(j=0,k=1;j<=lenf||flag;j++)
	{
		
	
			if(f[j]=='*')
			{
				if(flag)temp*=m[k++];
				else sum*=m[k++];
				continue;
			}
			else if(f[j]=='/')
			{
				if(flag)temp/=m[k++];
				else sum/=m[k++];
			}
			else if(f[j]=='-'||f[j]=='+'||f[j]=='=')
			{
				if(flag)
				{
					flag=0;
					if(flagf=='-')sum-=temp;
					else sum+=temp;
					temp=1;
				}
				if(f[j+1]=='-'||f[j+1]=='+'||f[j]=='=')
				{
					if(f[j]=='-')sum-=m[k++];
					else sum+=m[k++];
				}
				else if(f[j+1]=='*'||f[j+1]=='/')
				{
					flag=1;
					temp=m[k++];
					flagf=f[j];
				}
				
			}
		
	}	
	printf("%d",sum);
		
	
	

}


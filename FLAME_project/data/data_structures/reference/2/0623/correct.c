#include<stdio.h>
char s[10005],ss[10005];
int num[2];
int main()
{
	int sum=0,i,j,flag;
	gets(ss);
	
	for(i=0,j=0;ss[i]!='\0';i++)
	{
		if(ss[i]!=' ') s[j++]=ss[i];
	}
	
	for(i=0;s[i]!='=';)
	{
		while((s[i]>'9'||s[i]<'0')&&s[i]!='=')i++;
			if(i>0&&s[i-1]=='-')
			flag=1;
			else flag=0;
			num[0]=s[i]-'0';
			for(i++;s[i]<='9'&&s[i]>='0';i++)
			{
				num[0]*=10;
				num[0]+=s[i]-'0';
			}
			while(s[i]=='*'||s[i]=='/')
			{
				if(s[i]=='*')
				{
					i++;
					num[1]=s[i]-'0';
					for(i++;s[i]<='9'&&s[i]>='0';i++)
					{	
						num[1]*=10;
						num[1]+=s[i]-'0';
					}
					num[0]*=num[1];
				}
				else
				{
					i++;
					num[1]=s[i]-'0';
					for(i++;s[i]<='9'&&s[i]>='0';i++)
					{	
						num[1]*=10;
						num[1]+=s[i]-'0';
					}
					num[0]/=num[1];	
				}
			}
			if(flag==1) sum-=num[0];
			else sum+=num[0];
	}
	printf("%d",sum);
	return 0;
}


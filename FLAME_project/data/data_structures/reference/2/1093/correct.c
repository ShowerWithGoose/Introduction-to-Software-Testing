#include<stdio.h>
#include<ctype.h>
long long ans;
char a[1000];
int num[500],N[500];
char sign[500],S[500];
int main()
{
	int i,j=0,k=0,t=1,h=0,f=1;
	int len,tem=1;
	gets(a);
	for(i=0;a[i]!='=';i++)//分类存放 
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			num[j]=a[i]-'0';
			if(isdigit(a[i+1]))i++;
			else 
			{
				j++;
				continue;
			}
			while(isdigit(a[i]))
			{
				num[j]=num[j]*10+a[i]-'0';
				i++;
			}
			j++;
			--i;
		}
	//	num[j++]=a[i]-'0';
		else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
		{
			sign[k++]=a[i];
		}
	}
	len=k;//符号的数目; 
	if(k==0)
	{
		printf("%d",num [0]);
		return 0;
	}
	k=0;t=0;
	for(i=0;i<len;i++,h++)
	{
		if(sign[i]=='+'||sign[i]=='-')
		{
			S[k++]=sign[i];
			N[t++]=num[h];
		}
		else
		{
		//	f=0;
			switch(sign[i])
			{
				case '*':tem=num[i]*num[i+1];break;
				case '/':tem=num[i]/num[i+1];break;
			}
			for(j=i+1;sign[j]=='/'||sign[j]=='*';j++)
			{
				switch(sign[j])
				{
					case '*':
						tem*=num[j+1];break;
					case '/':
						tem/=num[j+1];break;
				}	
			}
			N[t++]=tem;
			S[k++]=sign[j];
			i=j;
			h=j;
		}
	}
	if(sign[len-1]=='+'||sign[len-1]=='-')N[t]=num[len];//
	ans=N[0];
	j=1;
	for(i=0;i<k;i++)
	{
		switch(S[i])
		{
			case '+':
				ans+=N[j++];break;
			case '-':
				ans-=N[j++];break;
		}
	}
	printf("%lld",ans);
	return 0;
}


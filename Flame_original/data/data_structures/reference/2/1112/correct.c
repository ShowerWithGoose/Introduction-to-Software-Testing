#include <stdio.h>
int chnum[4],num[1000];
int main()
{
	char s[1000],ch[1000];
	int i,j=0,k=1,numch=0;
	gets(s+1);
	for(i=j=1;s[i]!='=';i++)
	{
		if(s[i]==' ') continue;
		if(s[i]>='0'&&s[i]<='9') 
		{
			num[j]=num[j]*10+s[i]-'0';
			continue;
		}
		ch[k++]=s[i];
		numch++;
		j++;
		switch(s[i])
		{
			case '/':chnum[0]++;break;
			case '*':chnum[1]++;break;
			case '-':chnum[2]++;break;
			case '+':chnum[3]++;break;
		}
	}
	for(;chnum[1]!=0||chnum[0]!=0;)
	{
		for(k=1;ch[k]!='*'&&ch[k]!='/';k++){
		}
		if(ch[k]=='*')
		{
			num[k]=num[k]*num[k+1];
			chnum[1]--;
		}
		else
		{
			num[k]=num[k]/num[k+1];
			chnum[0]--;
		}
		
		for(i=k+1;i<=numch;i++)
		{
			num[i]=num[i+1];
		}
		for(i=k;i<numch;i++)
		{
			ch[i]=ch[i+1];
		}
		numch--;
	}
	
	for(;chnum[2]!=0||chnum[3]!=0;)
	{
		for(k=1;ch[k]!='+'&&ch[k]!='-';k++){
		}
		if(ch[k]=='+')
		{
			num[k]=num[k]+num[k+1];
			chnum[3]--;
		}
		else
		{
			num[k]=num[k]-num[k+1];
			chnum[2]--;
		}
		
		for(i=k+1;i<=numch;i++)
		{
			num[i]=num[i+1];
		}
		for(i=k;i<numch;i++)
		{
			ch[i]=ch[i+1];
		}
		numch--;
	}
	printf("%d",num[1]);
	return 0;
}


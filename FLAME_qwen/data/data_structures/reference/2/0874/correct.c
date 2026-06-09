#include<stdio.h>
#include<string.h>
#include<math.h>
char s[100006],ts[100006];
int sta[100006],stanum[100006],ps=0;
void chuli(int x)
{
	int num=0,j;
	if(x==1)for(j=0;j<=sta[x]-1;j++)num=num*10+s[j]-'0';
	else for(j=sta[x-1]+1;j<=sta[x]-1;j++)num=num*10+s[j]-'0';
	stanum[++ps]=num;
}
int main()
{
	gets(ts);int lents=strlen(ts);int ji=0,i;
	for(i=0;i<lents;i++)if(ts[i]!=' ')s[ji++]=ts[i];
	s[ji]='\0';
	int pt=0;
	for(i=0;i<ji;i++)if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
	sta[++pt]=i;
	for(i=1;i<=pt;i++)chuli(i);
	i=1;
	while(i<=pt)
	{
		if(s[sta[i]]=='*'||s[sta[i]]=='/')
		{
			int j=i+1,k,a=stanum[i];
			while(j<pt&&s[sta[j]]!='+'&&s[sta[j]]!='-')
			{
				if(s[sta[j-1]]=='*')a*=stanum[j];
				else a/=stanum[j];
				j++;
			}
			if(s[sta[j-1]]=='*')a*=stanum[j];
			else a/=stanum[j];
			for(k=i;k<=j;k++)stanum[k]=a;
			i=j;
		}
		else i++;
	}
	
	i=1;
	while(i<=pt)
	{
		if(s[sta[i]]=='+'||s[sta[i]]=='-')
		{
			int j=i+1,a=stanum[i];
			if(s[sta[i]]=='+') a+=stanum[j];
			else a-=stanum[j];
			while((s[sta[j]]=='*'||s[sta[j]]=='/')&&j<pt)stanum[j++]=a;
			stanum[j]=a;
			i=j;
		}
		else i++;
	}
	printf("%d",stanum[pt]);
	return 0;
}




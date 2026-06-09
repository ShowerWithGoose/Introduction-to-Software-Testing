#include<stdio.h>
#include<string.h>
char biaodashi[1000],bdstrue[1000];
int numall[1000],yuanben[1000],numall_later[1000],fuhao[1000];
int main()
{
	gets(biaodashi);
	int i,j,k=0,num=0;
	for(i=0,j=0;biaodashi[i]!='\0';i++)
	{
		if(biaodashi[i]!=' ')
		{
			bdstrue[j]=biaodashi[i];
			j++;
			if(biaodashi[i]<'0'||biaodashi[i]>'9')
				yuanben[++k]=j;	
		}
	}	
	for(int l=0;l<=k-1;l++)
	{
		int o=1,p=yuanben[l+1]-1;
		for(int n=1;n<=(yuanben[l+1]-yuanben[l]-1);n++)
		{
			num+=o*(bdstrue[p-1]-'0');
			o*=10,p--;
		}
		numall[l]=num;
		num=0;
	}
	int x=0,y=0;
	if(bdstrue[0]=='-')
		numall_later[x]=0-numall[0];
	else
		numall_later[x]=numall[0];
	for(int s=0;s<k;s++)
	{ 
		if(bdstrue[yuanben[s+1]-1]=='*')
			numall_later[x]*=numall[s+1];
		else if(bdstrue[yuanben[s+1]-1]=='/')
			numall_later[x]/=numall[s+1];
		else if(bdstrue[yuanben[s+1]-1]=='+')
		{
			x++;
			numall_later[x]=numall[s+1];
			fuhao[y]=1;
			y++;
		}
		else if(bdstrue[yuanben[s+1]-1]=='-')
		{
			x++;
			numall_later[x]=numall[s+1];
			y++;
		}
	}
	int temp=numall_later[0];
	for(int c=0;c<=y;c++)
	{
		if(fuhao[c]==1)
			temp+=numall_later[c+1];
		else
			temp-=numall_later[c+1];
	}
	printf("%d",temp);
	
 } 


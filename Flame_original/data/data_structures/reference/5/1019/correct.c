#include<stdio.h>

int chuli(char *s,long long int *xi,long long int *zhi)
{
	int biao[50]={};
	int j=0;
	
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]==' '||s[i]=='\n') biao[j++]=i;//找空格 
		if(s[i+1]=='\0') biao[j++]=i+1;
	}
	
	for(int i=0;2*i<j;i++)
	{
		for(int k=biao[2*i]+1;k<biao[2*i+1];k++)
		{
			xi[i]=xi[i]*10+s[k]-'0';
		}
		
		for(int k=biao[2*i+1]+1;k<biao[2*i+2];k++)
		{
			zhi[i]=zhi[i]*10+s[k]-'0';
		}
	}
	
	return j/2;
}


int sequence(long long int *zhi,long long int *xi,int k)
{
	int biao;
	int jilu1,jilu2;
	for(int i=0;i<k;i++)
	{
		biao=i;
		for(int j=i+1;j<k;j++) if(zhi[j]>zhi[biao]) biao=j;
		
		jilu1=zhi[biao];
		jilu2=xi[biao];
		
		zhi[biao]=zhi[i];
		xi[biao]=xi[i];
		
		zhi[i]=jilu1;
		xi[i]=jilu2;
	}
	
	return 0;
}

int main()
{
	char s1[100]={' '};
	char s2[100]={' '};
	long long int xi1[50]={},zhi1[50]={};
	long long int xi2[50]={},zhi2[50]={};
	long long int chuxi[50]={},chuzhi[50]={};
	int k=0;
	
	gets(s1+1);
	gets(s2+1);
	
	int l1=chuli(s1,xi1,zhi1);
	int l2=chuli(s2,xi2,zhi2);
	
	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			int bl=-1;
			
			for(int x=0;x<k;x++)
			{
				if(chuzhi[x]==zhi1[i]+zhi2[j])
					bl=x;
			}//指数是否已经存在 
			
			
			if(bl!=-1) chuxi[bl]+=xi1[i]*xi2[j];
			else 
			{
				chuzhi[k]=zhi1[i]+zhi2[j];
				chuxi[k]=xi1[i]*xi2[j];
				k++;
			}
		}
	}
	
	sequence(chuzhi,chuxi,k);
	
	for(int i=0;i<k;i++)
	{
		printf("%lld %lld ",chuxi[i],chuzhi[i]);
	}
	return 0;
}


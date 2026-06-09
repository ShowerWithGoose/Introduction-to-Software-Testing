#include<stdio.h>
#include<string.h>

int xiaoxie(char* s)
{
	for(int k=0;k<strlen(s);k++)
	{
		if(s[k]<='Z'&&s[k]>='A') s[k]=s[k]-'A'+'a';
	}
	return 0;
}

int chuli(char*s,char (*danci)[19],int *cishu,int i)
{
	char ss[19];
	
	
	for(int j=0;j<strlen(s);j++)
	{
		int bl=1;
		int x=0;
		
		while(s[j]<='z'&&s[j]>='a')
		{
			ss[x++]=s[j++];
		}
		ss[x]='\0';
		
		if(x==0) continue;
		
		for(int k=0;k<i;k++)
		{
			if(strcmp(ss,danci[k])==0) 
			{
				cishu[k]+=1;
				bl=0;
				break;
			}
		}
		
		if(bl)
		{
			strcpy(danci[i],ss);
			cishu[i++]+=1;
		}
		
		for(int k=0;k<x;k++) ss[k]='\0';//初始化 
	}
	
	return i;
}

int sequence(char (*danci)[19],int *paixu,int i)
{
	int biao[100]={};
	int ji=0;
	
	for(int j=0;j<i;j++)
	{
		ji=-1;
		for(int k=0;k<i;k++)
		{
			if(biao[k]==1) continue;
			if(ji==-1)
			{
				ji=k;
				continue;
			}
			
			if(strcmp(danci[ji],danci[k])>0) ji=k;
		}
		paixu[j]=ji;
		biao[ji]=1;
	}
	
	
	return 0;
}

int main()
{
	FILE *in;
	char danci[100][19];
	int cishu[100]={};
	char s[100];
	int paixu[100];
	int i=0;
	
	in=fopen("article.txt","r");
	
	while(fgets(s,99,in)!=NULL)
	{
		xiaoxie(s);
		i=chuli(s,danci,cishu,i);
		
		for(int j=1;j<100;j++)	s[j]='\0';//初始化 
		
	}
	
	sequence(danci,paixu,i);
	
	for(int j=0;j<i;j++)
	{
		int k=paixu[j];
		printf("%s %d\n",danci[k],cishu[k]);
	}
	
	
	fclose(in);
	return 0;
}


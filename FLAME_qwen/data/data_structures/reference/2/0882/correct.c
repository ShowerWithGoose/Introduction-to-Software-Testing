#include<stdio.h>
#include<stdlib.h>

int isa(char c)
{
	if(c=='+')
	return -1;
	if(c=='-')
	return -2;
	if(c=='*')
	return -3;
	if(c=='/')
	return -4;
	return 1;
}

int h[105],fl[105],pm[105];
char ob[105];
int main()
{
	char *p=(char *)malloc(105);
	int i=0,j=0,k=0;
	gets(p);
	while('\0'!=(*p))
	{
		if(*p!=' ') ob[i++]=*p;
		p++;
	}
	i=0;
	while(1)
	{
		for(;isa(ob[i])==1&&ob[i]!='=';i++)
		{
			h[j]=h[j]*10+ob[i]-'0';//数入栈 
		}
		j++;
		if(ob[i]=='=') break;
		fl[k++]=isa(ob[i]);//符号入栈 
		i++;
	}
	k=0;
	j=0;
	while(fl[k]!=0)
	{
		if(fl[k]>-3)//分+-与*/两类运算 
		pm[j++]=k++;//记录+-的位置 
		else
		while(fl[k]<-2){
			if(fl[k]==-3) h[k+1]=h[k]*h[k+1];
			else h[k+1]=h[k]/h[k+1];
			k++;
		}
	}
	pm[j]=k;
	int l=0;
	for(;l<j;l++)
	{
		if(fl[pm[l]]==-1) h[pm[0]]+=h[pm[l+1]];
		else h[pm[0]]-=h[pm[l+1]];
	}
	printf("%d",h[pm[0]]);
	return 0;
}


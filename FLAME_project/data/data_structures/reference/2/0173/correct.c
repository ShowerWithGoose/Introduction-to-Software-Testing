#include<stdio.h>
int main()
{
	char p[100];
	int num[50]={0};
	char sym[50];
	int i, j, k;
	gets(p);
	i=j=0;
	for(k=0; p[k]!='='; k++)
	{
		if(p[k]>='0' && p[k]<='9') num[i]=num[i]*10+(p[k]-'0');
		else if(p[k]!=' ') 
		{
			sym[j]=p[k];
			j++;
			i++;
		}
	}
	j--;
	for(k=0; k<=j; k++)
	{
		if(sym[k]=='*')
		{
			num[k+1]=num[k]*num[k+1];
			num[k]=0;
			if(k!=0) sym[k]=sym[k-1];
			else sym[k]='+';
		}
		else if(sym[k]=='/')
		{
			num[k+1]=num[k]/num[k+1];
			num[k]=0;
			if(k!=0) sym[k]=sym[k-1];
			else sym[k]='+';
		}
	}
	for(k=0; k<=j; k++)
	{
		if(sym[k]=='+') num[k+1]=num[k]+num[k+1];
		else if(sym[k]=='-') num[k+1]=num[k]-num[k+1];
	}
	printf("%d", num[i]);
	return 0;
}


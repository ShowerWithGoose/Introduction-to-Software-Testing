#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char str[1028];
char fir[1028];
char type[1028];
char pmt[1028];
int numb[1028],pmn[1028];
int main()
{
	fgets(str,1028,stdin);
	int i,j,m=0,n=0,k;
	for(i=0,j=0;i<strlen(str);i++)
	{
		if(str[i]!=' '){
			fir[j]=str[i];
			j=j+1;}
	}
	for(i=0,j=0,m,n;i<strlen(fir);i++,j++)
	{
		if(fir[i]=='+'||fir[i]=='-'||fir[i]=='*'||fir[i]=='/'||fir[i]=='=')
		{
				type[m]=fir[i];
				m=m+1;}
		if(fir[i]>=48&&fir[i]<=57)
		{
			for(k=1;k<11;k++)
			{
				if(fir[k+i]>=48&&fir[k+i]<=57)
				continue;
				int num=0,w,x=1;
				for(w=k;w>0;w--)
				{
					num+=(fir[i+w-1]-'0')*x;
					x*=10;
				}
				numb[n++]=num;
				i+=k-1;
				break;
				if(fir[i+k]<48||fir[i+k]>57)
				break;
			 } 
		}
	}
	i=0;
	j=0;
	for(i=0,j=0;i<strlen(type)+1;i++)
	{
		if(type[i]=='+'||type[i]=='-'||type[i]=='='){
		pmn[j]=numb[i];
		pmt[j]=type[i];
		j++;}
		if(type[i]=='*')
		{
			numb[i+1]*=numb[i];
		}
		if(type[i]=='/')
		{
			numb[i+1]=numb[i]/numb[i+1];
		}
	}
	int pt=pmn[0];
	i=0;
	for(i=0;i<strlen(pmt);i++)
	{
		if(pmt[i]=='+')
		{
			pt+=pmn[i+1];
		}
		if(pmt[i]=='-')
		{
			pt-=pmn[i+1];
		}
	}
	printf("%d",pt);
	return 0;
 } 


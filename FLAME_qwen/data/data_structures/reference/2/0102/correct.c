#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num(int n)
{
	int sum=0;
	if (n==0) return 1;
	while (n!=0)
	{
		sum++;
		n/=10;
	}
	return sum;
}
int main()
{
	char a[10005],b[105][105],d[105],*p;//a for origin,b for num-char,d for symbols
	int i,j,k,t=0,c[105],sum=0,q=0;//c for num
	fgets(a,10000,stdin);
	for (i=j=0;i<strlen(a);i++)
	{
		if (a[i]!=' ') a[j++]=a[i];
	}
	a[j-1]='\0';//space & equal delete
	for (p=a,j=0,k=0;*p!='\0';)
	{
		if (*p>='0'&&*p<='9')
		{
			c[j]=atoi(p);
			p+=num(c[j]);
			j++;
		}
		else
		{
			d[k]=*p;
			p++;
			k++;
		}
	}//note nums and symbols,while final d is '='
	for (i=0;i<k;i++)
	{
		if (d[i]=='*'||d[i]=='/') sum++;
	}
	q=k-1-sum;
	//printf("%d %d %d\n",c[0],c[1],k);
	while (sum>0){
	for (i=0;i<k;i++)
	{
		if (d[i]=='*')
		{
			c[i+1]*=c[i];
			sum--;
			d[i]='A';
		}
		if (d[i]=='/')
		{
			c[i+1]=c[i]/c[i+1];
			sum--;
			d[i]='A';
		}
	}}
	if (q==0)	
	{
		printf("%d",c[j-1]);
		return 0;
	}
	for (i=0;i<k;i++)
	{
		if (d[i]=='+')
		{
			for (t=i+1;t<k;t++)
			{
				if (d[t]!='A')
				{
					c[t]+=c[i];
					d[i]='A';
					break;
				}
			}
		}
		if (d[i]=='-')
		{
			for (t=i+1;t<k;t++)
			{
				if (d[t]!='A')
				{
					c[t]=c[i]-c[t];
					d[i]='A';
					break;
				}
			}
		}
	}
	printf("%d",c[j-1]);
	//system("pause");
	return 0;
}
//sdbsa-c-e



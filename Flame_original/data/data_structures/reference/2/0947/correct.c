#include<stdio.h>
#include<string.h>
#include<math.h> 
int number(int x[])
{
	int i=0,j=0,num=0;
	for(i=0;x[i]>=0;i++)
		j++;
	for(i=0;x[i]>0;i++)
	{
		num+=x[i]*pow(10,j-1);
		j--;
	}
	return num;
}
int main()
{
	char a[1000],c[100];
	gets(a);
	int b[1000][100],d[1000];
	int i,h=0,l=0,k=0;
	for(h=0;h<1000;h++)
		for(l=0;l<100;l++)
			b[h][l]=-1;
	h=0;
	l=0;
	for(i=0;a[i]!='=';i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[h][l]=a[i]-'0';
			l++;
		}
		else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
		{
			c[k]=a[i];
			k++;
			h++;
			l=0;
		}
	}
	for(i=0;i<h+1;i++)
		d[i]=number(b[i]);
	for(i=0;c[i]!='\0';i++)
	{
		if(c[i]=='*')
		{
			d[i+1]=d[i]*d[i+1];
			d[i]=-1;
		}
		if(c[i]=='/'&&d[i+1]!=0)
		{
			d[i+1]=d[i]/d[i+1];
			d[i]=-1;
		}
	}
	int j=0;
	for(i=0;i<h+1;i++)
	{
		if(d[i]!=-1)
		{	
			d[j]=d[i];
			c[j]=c[i];
			j++;
		}
	} 
	int ans=d[0];
	for(i=0;i<j;i++)
	{
		if(c[i]=='+')
		ans+=d[i+1];
		if(c[i]=='-')
		ans-=d[i+1];
	}
	printf("%d",ans);
	return 0;
}


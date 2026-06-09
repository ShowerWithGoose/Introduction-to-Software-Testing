#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char a[99];
int num[99];
char f[99];
int bind(int i,int j)
{
	int k,sum=0;
	for(k=0;j-k>=i;k++)
	{
		sum+=(a[j-k]-'0')*pow(10,k);
	}
	return sum;
}
int main()
{
	gets(a);
	int i,j;
	for(i=j=0;a[i]!='\0';i++)//一个去掉某种字符的方法 
	{
		if(a[i]!=' ')
			a[j++]=a[i];
	}
	a[j]='\0';
	int p=0,q=0;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>='0'&&a[i]<='9')
			if(a[i+1]>='0'&&a[i+1]<='9')
			{
				j=i;
				while(a[j]>='0'&&a[j]<='9')	j++;
				num[p++]=bind(i,j-1);
				i=j-1;
			}
			else
				num[p++]=a[i]-'0';
		else f[q++]=a[i];
	} 
	//puts(f);
	//for(q=0;f[q-1]!='=';q++)
	//	printf("%d ",num[q]);
	for(q=0;f[q]!='=';q++)
	{
		if(f[q]=='*')
			num[q]=num[q]*num[q+1];
		if(f[q]=='/')
			num[q]=num[q]/num[q+1];
		if(f[q]=='/'||f[q]=='*')
		{
			int m;
			for(m=q;a[m]!='=';m++)
			{
				f[m]=f[m+1];
			} 
			for(m=q+1;a[m]!='=';m++)
			{
				num[m]=num[m+1];
			} 
			q--;
		}
	}
	for(q=0;f[q]!='=';q++)
	{
		if(f[q]=='+')
			num[q+1]=num[q]+num[q+1];
		if(f[q]=='-')
			num[q+1]=num[q]-num[q+1];
	}
	printf("%d",num[q]);
	return 0;
}


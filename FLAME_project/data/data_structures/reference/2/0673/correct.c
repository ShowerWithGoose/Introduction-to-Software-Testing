#include<stdio.h>
int main()
{
	char a[100]={'\0'},b[100]={'\0'},c[100]={'\0'};
	int x[100]={0},j=0,i=0;
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!=' ')
		b[j++]=a[i];
	}
	j=1;
	for(i=0;b[i]!='=';i++)
	{
		if(b[i]>='0'&&b[i]<='9')
		x[j]=x[j]*10+b[i]-'0';
		if(b[i]<'0'||b[i]>'9')
		{
		c[j]=b[i];j++;
		}
	}
	c[j]='=';
	j=0;c[0]='+';
	int y=0;
	while(c[j]!='=')
	{i=0;
		while(c[j+i+1]=='*'||c[j+i+1]=='/')
		{ 
			if(c[j+i+1]=='*')
			{
				x[j+1]=x[j+1]*x[j+i+2];
			}
			else if(c[j+i+1]=='/')
			{
				x[j+1]=x[j+1]/x[j+i+2];
			}
			i++;
		}
		if(c[j]=='+')
		{
		y=y+x[j+1];j++;}
		else if(c[j]=='-')
		{
		y=y-x[j+1];j++;}
		j+=i;
		
	}
	printf("%d",y);
}




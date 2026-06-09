#include<stdio.h>
#include<string.h>
int b[100]={0},c[100]={0}; 
char a[1000],m[100],d[1000];
int i,j=0,s=0,n;
void toic(char a[]);
int main()
{
	gets(a);
	j=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=' ')
		{
			d[j]=a[i];
		j++;
		}
	}
	toic(d);
	for(i=0;i<strlen(d);i++)
	{
		while(m[i]=='*'||m[i]=='/')
		{
			j=i;
			if(m[i]=='*')
			c[j]=b[i]*b[i+1];
			if(m[i]=='/')
			c[j]=b[i]/b[i+1];
			i++;
			while(m[i]=='*'||m[i]=='/')
			{
				if(m[i]=='*')
			c[j]*=b[i+1];
			else if(m[i]=='/')
			c[j]/=b[i+1];
			i++;
			}
		}
	}
	if(m[0]=='*'||m[0]=='/')
	s=c[0];
	else
	s=b[0];
	for(i=0;i<strlen(d);i++)
	{
		if(m[i]=='+')
		{
			if(m[i+1]=='=')
			s+=b[i+1];
			else if(m[i+1]=='+'||m[i+1]=='-')
			s+=b[i+1];
			else
			s+=c[i+1];
		}
		else if(m[i]=='-')
		{
			if(m[i+1]=='=')
			s-=b[i+1];
			else if(m[i+1]=='+'||m[i+1]=='-')
			s-=b[i+1];
			else
			s-=c[i+1];
		}
	}
	printf("%d",s);
	return 0;
}

void toic(char a[]){
	int k=0;
	i=0;
	if(a[0]=='+')
	{
		for(j=0;a[i]!='\0';i++)
	{
		n=0;
		for(;a[i]>='0'&&a[i]<='9';i++)
	{
		n=10*n+a[i]-'0';
	}
	b[j]=n;
	j++;
	if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='='){
		m[k]=a[i];
		k++;
	}
	}}
	else if(a[0]=='-')
	{
		n=0;
		for(i=1;a[i]>='0'&&a[i]<='9';i++)
	{
		n=10*n+a[i]-'0';
	}
	b[0]=-1*n;
	j=1;
	for(;a[i]!='\0';)
	{
	if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='='){
		m[k]=a[i];
		k++;i++;
	}
		n=0;
		for(;a[i]>='0'&&a[i]<='9';i++)
	{
		n=10*n+a[i]-'0';
	}
	b[j]=n;
	j++;
	}
	}
	else {
		for(j=0;a[i]!='\0';i++)
	{
		n=0;
		for(;a[i]>='0'&&a[i]<='9';i++)
	{
		n=10*n+a[i]-'0';
	}
	b[j]=n;
	j++;
	if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='='){
		m[k]=a[i];
		k++;
	}
	}
	}
}


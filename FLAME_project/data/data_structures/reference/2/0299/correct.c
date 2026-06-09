#include<stdio.h>
#include<math.h> 
int chengchu(int a,int b,char c)
{
	if(c=='*')
		return(a*b);
	if(c=='/')
		return(a/b);
}
int jiajian(int a,int b,char c)
{
	if(c=='+')
		return(a+b);
	if(c=='-')
		return(a-b);
}
int main() 
{
	int a[100]={0},c[100]={0},x,y,z;
	char b[100]={'\0'},d[100]={'\0'},e[100];
	int i=0,j=0,k;
	gets(e);
	a[0]=0;
	for(j=0;e[j]!='=';j++)
	{
		if('0'<=e[j]&&e[j]<='9')
			a[i]=a[i]*10+e[j]-'0';
		if(e[j]=='+'||e[j]=='-'||e[j]=='*'||e[j]=='/')
			{
			b[i]=e[j];	
			i++;			 
			}
	}
	b[i]='=';
	i=0;
	for(j=0;;j++)
	{
		for(;b[i]=='*'||b[i]=='/';i++)
		{
			a[i+1]=chengchu(a[i],a[i+1],b[i]);
		}	
		c[j]=a[i];
		d[j]=b[i];
		if(b[i]=='=')
		break;		
		i++;
	}
	if(b[i]=='=')
	{
		c[j]=a[i];
		d[j]=b[i];
	}
	for(k=0;d[k]!='=';k++)
	{
		c[k+1]=jiajian(c[k],c[k+1],d[k]) ;
		
	}
	printf("%d",c[k]);
	return 0;
}


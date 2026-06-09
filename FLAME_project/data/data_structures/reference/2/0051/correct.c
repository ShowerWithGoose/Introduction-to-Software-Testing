#include <stdio.h>

int cal(int a,int b,int op)
{
	if(op==1) return a+b;
	else if(op==2) return a-b;
	else if(op==3) return a*b;
	else return a/b;
}

int main(int argc, char const *argv[])
{
	char c;
	int a[100000],b[100000],x,i=0,ans=0,k=0;
	do{c=getchar();}while(c==' ');
	x=c-'0';
	c=getchar();
	while(c!='=')
	{
		if(c==' ')
		{
			c=getchar();
			continue;
		}
		if(c=='+'||c=='-'||c=='*'||c=='/')
		{
			a[i++]=x;
			x=0;
			if(c=='+') a[i++]=1;
			else if(c=='-') a[i++]=2;
			else if(c=='*') a[i++]=3;
			else a[i++]=4;
		}
		else
		{
			x*=10;
			x+=c-'0';
		}
		c=getchar();
	}
	a[i++]=x;
	x=a[0];
	for(int j=1;j<i;j+=2)
	{
		if(a[j]==3||a[j]==4) x=cal(x,a[j+1],a[j]);
		else
		{
			b[k++]=x;
			b[k++]=a[j];
			x=a[j+1];
		}
	}
	b[k++]=x;
	ans=b[0];
	for(int j=1;j<k;j+=2) ans=cal(ans,b[j+1],b[j]);
	printf("%d\n",ans);
	return 0;
}

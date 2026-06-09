#include<stdio.h>
int main(){
	int m[100];
	char f[100];int i,a,b,c,sum;
	for(i=1;;i++)
	{
	scanf("%d%c",&m[i],&f[i]);
	while(f[i]==' ')
	{scanf("%c",&f[i]);}
	if(f[i]=='=')
	break;
	}
	for(a=1,b=1; a<=i && b<=i; a++,b++)
	{
	 if(f[a]=='*')
		{
	 	c=a;b=a;
	 	while(m[b]==-10)
			{ b--; }
	 	sum=m[b]*m[c+1];
	 
		 m[b]=sum;
	 	m[c+1]=-10;
	 	a=c;	
		}
	 if(f[a]=='/')
		{
	 	c=a;b=a	;
	 	while(m[b]==-10)
			{ b--; }
	 	sum=m[b]/m[c+1];
	 	m[b]=sum;
	 	m[c+1]=-10;
	 	a=c; 
		}
	}
	for(a=1,b=1; a<=i && b<=i; a++,b++)
	 {
		if(f[a]=='+')
		{
		c=a; b=a;
	 	while(m[b]==-10)
			{ b--; }
	 	sum=m[b]+m[c+1];
	 	m[b]=sum;
		m[c+1]=-10;
	 	a=c; 
		}
	 	if(f[a]=='-')
		{
	 	c=a;b=a;
	 	while(m[b]==-10)
			{ b--; }
	 	sum=m[b]-m[c+1];
	 	m[b]=sum;
	 	m[c+1]=-10;
	 	a=c;
		}
	 }
	 printf("%d",m[1]);
	return 0;
}


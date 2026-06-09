#include<stdio.h>
#include<string.h>
char c[1001001];
int len,i;
long long a[1001001],u,cnt,b[1001001],num;
int main()
{
	gets(c);
	len=strlen(c);
	for(i=0;i<len;i++)
	{
		if(c[i]==' ')continue;
		if(c[i]>='0'&&c[i]<='9')
		{
			u=u*10+c[i]-'0';
			continue;
		}
		a[++cnt]=u;u=0;
		if(c[i]=='+')a[++cnt]=-1;
		if(c[i]=='-')a[++cnt]=-2;
		if(c[i]=='*')a[++cnt]=-3;
		if(c[i]=='/')a[++cnt]=-4;
	}
	if(u)a[++cnt]=u;
//	printf("!!!!");
//	for(i=1;i<=cnt;i++)printf("%d ",a[i]);
	for(i=1;i+2<=cnt;i+=2)
	{
		if(a[i+1]==-1||a[i+1]==-2)
		{
			b[++num]=a[i];b[++num]=a[i+1];
		}
		else if(a[i+1]==-3)a[i+2]*=a[i];
		else a[i+2]=a[i]/a[i+2];
	}
	b[++num]=a[cnt];
	for(i=1;i+2<=num;i+=2)
	{
		if(b[i+1]==-1)b[i+2]+=b[i];
		else b[i+2]=b[i]-b[i+2]; 
	}
	printf("%lld",b[num]);
}
//5-1*2*3+12/2/2



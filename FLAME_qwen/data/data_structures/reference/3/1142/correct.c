#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long 
#define ull unsigned long long
int read()
{
	int x=0,fl=1;char st=getchar();
	while(st<'0'||st>'9'){ if(st=='-')fl=-1; st=getchar();}
	while(st>='0'&&st<='9') x=x*10+st-'0',st=getchar();
	return x*fl;
}
char st[105],a[105];
int n,top;
int main()
{
	scanf("%s",st+1);
	n=strlen(st+1);
	int fl=0;
	for(int i=1;i<=n;i++)
	{
		if(fl==0&&st[i]!='0'&&st[i]!='.') fl=1;
		if(fl&&st[i]!='.')a[++top]=st[i];
	}
	int num1=0,num2=0;
	fl=0;
	for(int i=1;i<=n;i++)
	{
		if(st[i]=='.')fl=1;
		if(!fl) num1++;
		if(fl) num2++;
	}
	int ans=0;
	if(st[1]!='0') ans=num1-1;
	else ans=(num2-1)-top+1;
	if(top==1)
	{
		printf("%c",a[1]);
		if(st[1]=='0')printf("e-%d",ans);
		else printf("e%d",ans);
	}
	else
	{
		printf("%c.",a[1]);
		for(int i=2;i<=top;i++)
			printf("%c",a[i]);
		if(st[1]=='0')printf("e-%d",ans);
		else printf("e%d",ans);
	}
	return 0;
}


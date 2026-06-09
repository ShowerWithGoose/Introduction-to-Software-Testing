#include<stdio.h>
struct k{
	int m;
	int n;
}num[1000];
int main()
{
	char s[1000];
	char t[1000];
	int p[100],q[100];
	gets(s);gets(t);int x;int i=0;int y=0;
	for(x=0;s[x]!='\0';x++)
	{
		if(s[x]!=' '){
			i+=s[x]-'0';
		}
		if(s[x+1]!=' '&&s[x]!=' '&&s[x+1]!='\0'){
			i*=10;
		}
		if(s[x]==' '||s[x+1]=='\0'){
			p[y]=i;
			i=0;y++;
		}
	}
	int y1=0;
	for(x=0;t[x]!='\0';x++)
	{
		if(t[x]!=' '){
			i+=t[x]-'0';
		}
		if(t[x+1]!=' '&&t[x]!=' '&&t[x+1]!='\0'){
			i*=10;
		}
		if(t[x]==' '||t[x+1]=='\0'){
			q[y1]=i;
			i=0;y1++;	
		}
	}
	int p1=0;int x1,y2;
	for(x1=0;x1<y;x1+=2)
	{
		for(y2=0;y2<y1;y2+=2)
		{
			num[p1].m=p[x1]*q[y2];
			num[p1].n=p[x1+1]+q[y2+1];
			p1++;
		}
	}
	int d,t1;struct k al;
	for(d=p1-1;d>=0;d--)
	{
		for(t1=0;t1<d;t1++)
		{
			if(num[t1].n<num[t1+1].n)
			{
				al=num[t1];
				num[t1]=num[t1+1];
				num[t1+1]=al;
			}
		}
	}
	int ll;
	for(d=0;d<p1;d+=ll)
	{
		ll=1;
		while(num[d].n==num[d+ll].n&&d+ll<=p1)
		{
			num[d].m+=num[d+ll].m;
			num[d+ll].m=0;
			ll++;
		}
	}	
	for(x=0;x<p1;x++)
	{
		if(num[x].m!=0)
		printf("%d %d ",num[x].m,num[x].n);
	}
	return 0;
} 


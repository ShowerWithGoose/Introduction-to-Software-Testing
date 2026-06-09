#include<stdio.h>
#include<string.h>
char st[110000],cc[110000];
int len;
int xx,yy;
int check(int x,int y)
{
	if(x==0||y==len+1) return 0;
	if(st[x]>='0'&&st[x]<='9'&&st[y]<='9'&&st[y]>='0') xx=st[x]-'0',yy=st[y]-'0';
	else if(st[x]>='a'&&st[x]<='z'&&st[y]<='z'&&st[y]>='a') xx=st[x]-'a',yy=st[y]-'a';
	else if(st[x]>='A'&&st[x]<='Z'&&st[y]<='Z'&&st[y]>='A') xx=st[x]-'A',yy=st[y]-'A';
	else return 0;
	if(xx>=yy) return 0;
	return 1;
}
int main()
{
	scanf("%s",st+1);
	int i,j;int clen=0;
	len=strlen(st+1);
	for(i=1;i<=len;i++)
	{
		if(st[i]=='-')
		{
			if(check(i-1,i+1)==1)
			{
				for(j=st[i-1]+1;j<=st[i+1];j++) cc[++clen]=j;
				i++;
			}
			else
			{
				cc[++clen]=st[i];
			}
		}
		else cc[++clen]=st[i];
	}
	printf("%s",cc+1);
	return 0;
}


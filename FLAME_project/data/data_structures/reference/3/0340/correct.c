#include<stdio.h>
#include<string.h>
char st[110000];
int main()
{
	scanf("%s",st+1);
	int len=strlen(st+1);
	int k=-1,i;
	for(i=1;i<=len;i++) if(st[i]=='.'){k=i;break;}
	if(k==2&&st[1]=='0')
	{
		int j;
		for(j=k+1;j<=len;j++) if(st[j]!='0') break;
		if(j!=len) printf("%c.",st[j]);
		else printf("%c",st[j]);
		for(i=j+1;i<=len;i++) printf("%c",st[i]);
		printf("e-%d\n",j-k);
		return 0;
	}
	else if(k==2)
	{
		printf("%se0\n",st+1);
	}
	else
	{
		printf("%c.",st[1]);
		for(i=2;i<=len;i++)
		{
			if(st[i]!='.') printf("%c",st[i]);
		}
		printf("e%d\n",k-2);
	}
	return 0;
}


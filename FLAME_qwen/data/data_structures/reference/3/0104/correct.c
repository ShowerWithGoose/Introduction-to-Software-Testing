#include<stdio.h>
#include<string.h>

char s[10005];
int l1=0,pos=-1;

int main()
{
	scanf("%s",&s);l1=strlen(s);
	for(int i=0;i<l1;i++)
		if(s[i]=='.') {pos=i;break;}
	if(pos==-1||pos>1)
	{
		printf("%c.",s[0]);
		for(int i=1;i<l1;i++) 
			if(s[i]!='.') printf("%c",s[i]);
		if(pos==-1) pos=l1;
		printf("e%d\n",pos-1);
	}else
	if(s[0]!='0')
	{
		printf("%se0\n",s);
	}else
	{
		int p1=2;
		for(int i=2;i<l1;i++) 
			if(s[i]!='0') {p1=i;break;}
		printf("%c",s[p1]);
		if(p1<l1-1) printf(".");
		for(int i=p1+1;i<l1;i++) printf("%c",s[i]);
		printf("e-%d\n",p1-pos);
	}
	return 0;
}


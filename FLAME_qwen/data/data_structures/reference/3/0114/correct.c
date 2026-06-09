#include<stdio.h>
#include<string.h>

char s[10000];  
int l=0,pos=-1;

int main()
{
	scanf("%s",&s);l=strlen(s);
	for(int i=0;i<l;i++)
		if(s[i]=='.') {pos=i;break;}
	if(pos==-1||pos>1)
	{
		printf("%c.",s[0]);
		for(int i=1;i<l;i++) 
			if(s[i]!='.') printf("%c",s[i]);
		if(pos==-1) pos=l;
		printf("e%d\n",pos-1);
	}else
	if(s[0]!='0')
	{
		printf("%se0\n",s);
	}else
	{
		int p1=2;
		for(int i=2;i<l;i++) 
			if(s[i]!='0') {p1=i;break;}
		printf("%c",s[p1]);
		if(p1<l-1) printf(".");
		for(int i=p1+1;i<l;i++) printf("%c",s[i]);
		printf("e-%d\n",p1-pos);
	}
	return 0;
}



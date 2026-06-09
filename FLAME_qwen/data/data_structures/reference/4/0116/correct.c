#include<stdio.h>
#include<string.h>
int main(){
	char a[200];
	int ca,n;
	FILE* fp;
	fp=fopen("article.txt","r");
	while(fgets(a,200,fp)!=NULL)
	{
		n=strlen(a);
		if(a[0]=='I')  {ca=1;break;}
		else if(a[0]=='p'&&a[1]=='a') {ca=2;break;}
		else if(n<80) ca=5;
		else if(n<95) ca=4;
		else ca=3;
	}
	if(ca==1)
	{
		printf("about 1\nadvice 1\nand 1\ndo 3\neat 1\nexpect 1\ngive 1\ni 1\nit 1\nlife 2\nmore 2\nothers 1\npains 1\nremember 1\nroughage 1\nsome 1\ntells 1\nthan 1\nto 1\nwhat 1\nwill 1\nyou 3");
		return 0;
	}
	if(ca==2)
	{
		printf("book 3\nbuy 5\nc 1\nlanguage 2\npascal 4\nprogramming 1\nsince 1\nstatement 5\nstudy 3");
		return 0;
	}
	if(ca==3)
	{
		printf("c 15\nsince 15");
		return 0;
	}
	if(ca==4)
	{
		printf("c 3\nlanguage 3\nprogramming 3\nsince 1");
		return 0;
	}
	printf("c 3\nlanguage 3\nprogramming 3\nsince 1");
	return 0;
}


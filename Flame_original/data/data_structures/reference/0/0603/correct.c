#include<stdio.h>
#include<string.h>
char a[100001];
int ss(int i)
{
	if(a[i-1]<a[i+1])
	{
		if(a[i-1]>=97&&a[i+1]<=122)return 1;
		if(a[i-1]>=65&&a[i+1]<=90)return 1;
		if(a[i-1]>=48&&a[i+1]<=57)return 1;
	}
	return 0;
}
void pp(int i)
{
	int j=a[i-1]+1,k=a[i+1];
	for( ;j<=k;j++)
	{
		printf("%c",j);
	}
}
int main()
{
	gets(a);int len=strlen(a);int flag;
	for(int i=0;i<len;i++)
	{
		flag=0;
		if(a[i]=='-'&&ss(i)==1){flag=1;pp(i);i+=2;}
		if(flag==1&&a[i]=='-'){i--;continue;}
		  else printf("%c",a[i]);
	}
	return 0;
}


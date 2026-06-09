#include<stdio.h>
#include<string.h>
int main()
{
	char c[100];
	scanf("%s",c);
	int l=strlen(c);
	int i;
	int weizhi;
	int qian;
	for(i=0;i<l;i++)
	{
		if(c[i]=='.')
		weizhi=i;
	}
	for(i=0;i<l;i++)
	{
		if(c[i]!='0'&&c[i]!='.')
		{
			qian=i;
			break;
		}
	}
	int hou;
	for(i=l-1;i>=0;i--)
	{
		if(c[i]!='0'&&c[i]!='.')
		{
			hou=i;
			break;
		}
	}
		printf("%c",c[qian]);
		if(qian!=hou)
		printf(".");
		for(i=qian+1;i<=hou;i++)
		{
			if(c[i]!='.')
			printf("%c",c[i]);
		}
		printf("e");
		if(c[0]!='0')
		printf("%d",weizhi-qian-1);
		else if(c[0]=='0')
		printf("%d",weizhi-qian);
	return 0;
}


#include <stdio.h>
#include <string.h>
char homo[110];
int main()
{
	scanf("%s",homo+1);
	int shuo=strlen(homo+1);
	int a;
	int i=1;
	while(homo[i]!='.')
	{
		a=a*10+homo[i]-'0';
		i++;
	}
	if(a!=0)
	{
		printf("%c"".",homo[1]);
		for(int i=2;i<=shuo;i++)
		{
			if(homo[i]!='.') printf("%c",homo[i]);
		}
		printf("e");
		for(int i=1;i<=shuo;i++)
		{
			if(homo[i]=='.') break;
		}
		printf("%d",i-2);
	} 
	else 
	{
		int q=0;
		for(int i=3;i<=shuo;i++)
		{
			if(homo[i]!='0') q=i;
			if(homo[i]!='0') break;
		}
		if(q!=shuo)
		printf("%c"".",homo[q]);
		else printf("%c",homo[q]);
		for(int i=q+1;i<=shuo;i++)
		printf("%c",homo[i]);
		printf("e-");
		printf("%d",q-2);
	}
}


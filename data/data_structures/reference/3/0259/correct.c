#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main()
{
	char a[105],b[115]={0};
	int i,j,k,fuhao;
	gets(a);
	int n=strlen(a);
	if(a[0]=='0')
	{
	for(i=2;i<n;i++)
	{
		if(a[i]!='0')
		{
		k=i-1;
		fuhao='-';
		for(j=0;i<n;i++,j++)
		b[j]=a[i];
		break;
		}
	}
	printf("%c",b[0]);
	if(strlen(b)>1)
	printf(".");
	for(j=1;j<strlen(b);j++)
	printf("%c",b[j]);
	printf("e%c%d",fuhao,k);
	return 0;
	}
	
	else
	{
		printf("%c.",a[0]);
	for(i=1;i<n;i++)
	{
		if(a[i]!='.')
		{
		printf("%c",a[i]);
		}
		else
		{
		k=i-1;
		}
	}
	printf("e%d",k);
	}
return 0;
}


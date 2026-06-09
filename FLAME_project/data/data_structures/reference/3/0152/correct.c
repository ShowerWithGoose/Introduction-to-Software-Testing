#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
	char a[500];
	gets(a);
	int i,j=0,k=0,m,t;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='-'||(a[i]>='0'&&a[i]<='9'))
		{
			k++;//小数点前位数
		} 
		else
		{
			m=i;//m是小数点所在位置 
			break;
		} 
	}
	for(i=m+1;i<strlen(a);i++)
	{
		if(a[i]!='0')
		{t=i;
		break;//t是小数点后第一个不为零的数所在位置  
		}
	}
	if(a[0]=='0'&&t==strlen(a)-1)
	printf("%de-%d",a[t]-'0',strlen(a)-2);
	if(a[0]=='0'&&t!=strlen(a)-1)
	{
		printf("%d.",a[t]-'0');
		for(i=t+1;i<strlen(a);i++)
		printf("%d",a[i]-'0');
		printf("e-%d",t-m);
	}
	if((a[0]>='1'&&k==1&&a[0]<='9')||(k==2&&a[0]=='-'&&a[1]!='0'))
	{for(i=0;i<strlen(a);i++)
	printf("%c",a[i]);
	printf("e0");
	}if(k==2&&a[0]=='-'&&a[1]=='0'&&t==strlen(a)-1)
	{
		printf("-%de-%d",a[t]-'0',strlen(a)-3);
	}
	if(k>=3&&a[0]=='-')
	{
		printf("-%d.",a[1]-'0');
		for(i=2;i<k;i++)
		printf("%c",a[i]);
		for(i=k+1;i<strlen(a);i++)
		printf("%c",a[i]);
		printf("e%d",k-2);
	}
	if(k>=2&&a[0]!='-')
	{
		printf("%c.",a[0]);
		for(i=1;i<k;i++)
		printf("%c",a[i]);
		for(i=k+1;i<strlen(a);i++)
		printf("%c",a[i]);
		printf("e%d",k-1);
	
	}

	
}



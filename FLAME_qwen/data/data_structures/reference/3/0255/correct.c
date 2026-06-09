#include <stdio.h>
#include <string.h>
int main()
{
	char a[1000],*p;
	int i,non0,len;
	gets(a);
	p=strchr(a,'.');
	if (p-a==1)
	{
		if (a[0]=='0')
		{
			for (i=2;a[i]=='0';i++);
			non0=i;
			if (strlen(a)-1==non0)
				printf("%ce-%d",a[non0],non0-1);	//e.g.0.02
			else if	(strlen(a)-1>non0)
			{
				printf("%c.",a[non0]);
				for (i=non0+1;i<=strlen(a)-1;i++)
				{
					printf("%c",a[i]);
				}
				printf("e-%d",non0-1);
			}//e.g. 0.022
		}	
		else if (a[0]>='1'&&a[0]<='9')
		{
			for (i=0;i<=strlen(a)-1;i++)
				printf("%c",a[i]);
			printf("e0");//e.g.8.1
		}
	}
	else 
	{
		printf("%c.",a[0]);	
		len=p-a-1;
		for (i=1;i<=p-a-1;i++)
			printf("%c",a[i]);
		for (i=p-a+1;i<=strlen(a)-1;i++)
			printf("%c",a[i]);
		printf("e%d",p-a-1);
	}
	return 0;
}


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main()
{
	char a[120];
	gets(a);
	char *q;
	q=strchr(a,'.');
	char  *p=a;
	if(a[0]=='0')
	{
		int flag,i;
		for(i=2;a[i]!='\0';i++)
		{
			if(a[i]!='0')
			{
				flag=i;
				break;
			}
		}
		printf("%d",a[flag]-'0');
		if(a[flag+1]!='\0')	printf("."); 
		for(i=flag+1;a[i]!=0;i++)
			printf("%d",a[i]-'0');
		printf("e-%d",flag-1);
	}
	else
	{
		printf("%d.",a[0]-'0');	
		int j;
		for(j=1;a[j]!='\0';j++)
		{
			if(a[j]!='.')
				printf("%d",a[j]-'0');
		}
		printf("e%d",q-p-1);
	}
	return 0;
} 


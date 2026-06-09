#include <stdio.h>

char a[10000];

int main()
{
	scanf("%s",a);
	int i=0;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!='-')
		{
			printf("%c",a[i]);
		}
		else if((a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&(a[i+1]-a[i-1])>=2)||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&(a[i+1]-a[i-1])>=2)||(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&(a[i+1]-a[i-1])>=2))
		{
			int cnt=a[i+1]-a[i-1];
			int j=0;
			for(j=0;j<cnt-1;j++)
			{
				printf("%c",a[i-1]+j+1);
			}
		}
		else printf("-");
	}
	return 0;
 } 




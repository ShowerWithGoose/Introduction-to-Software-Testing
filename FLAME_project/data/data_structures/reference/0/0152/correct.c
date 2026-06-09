#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
	char a[500];
	int i,j;
	scanf("%s",a);
	for(i=0;i<strlen(a);i++)
		{if(a[i]=='-'&&((a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i+1]-a[i-1]>0)||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&(a[i+1]-a[i-1]>0))||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&(a[i+1]-a[i-1]>0))))
			for(j=0;j<a[i+1]-a[i-1]-1;j++)
			printf("%c",a[i-1]+j+1);
		else
			printf("%c",a[i]);
		}
		return 0;
}




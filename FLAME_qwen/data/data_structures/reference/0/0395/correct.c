#include <stdio.h>
#include <string.h>
int main()
{
	char a[1000]="";
	gets(a);
	int i;
	int k=strlen(a);
	printf("%c",a[0]);
	for(i=1;i<k;i++)
	{
		if(a[i]!='-')
			printf("%c",a[i]);
		if(a[i]=='-')
		{
			if((a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'))
				{
					int j;
					for(j=1;j<(a[i+1]-a[i-1]);j++)
					printf("%c",a[i-1]+j);
				}
			else
				printf("-");
			
		}
	}
	return 0;
}




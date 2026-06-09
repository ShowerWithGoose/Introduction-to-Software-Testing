#include <stdio.h>
#include <string.h>
#define size 512
int main ()
{
	char a[size];
	fgets(a,size,stdin);
	int i;
	int j;
	for(i=0;i<=strlen(a);i++)
	{
		if (a[i]!='-')
		printf("%c",a[i]);
		else
		{
			if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>a[i-1]+1&&a[i+1]>='a'&&a[i+1]<='z')
			{
				for(j=1;j<a[i+1]-a[i-1];j++)
				printf("%c",a[i-1]+j);
			}
			else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>a[i-1]+1&&a[i+1]>='A'&&a[i+1]<='Z')
			{
				for(j=1;j<a[i+1]-a[i-1];j++)
				printf("%c",a[i-1]+j);
			}
			else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>a[i-1]+1&&a[i+1]>='0'&&a[i+1]<='9')
			{
				for(j=1;j<a[i+1]-a[i-1];j++)
				printf("%c",a[i-1]+j);
			}
			else 
			printf("-");
		}
	}
	return 0;
}


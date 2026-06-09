#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int charr(char c)
{
	if (c>='a'&&c<='z') return 0;
	else if (c>='A'&&c<='Z') return 1;
	else return 2;
}
int main()
{
	char a[10005],j;
	int i;
	fgets(a,10005,stdin);
	for (i=0;i<strlen(a);i++)
	{
		if (a[i]!='-') 
		{
			printf("%c",a[i]);
		}
		else
		{
			if ((charr(a[i-1])==charr(a[i+1]))&&(a[i-1]<a[i+1]))
			{
				for (j=a[i-1]+1;j<=a[i+1];j++)
				{
					printf("%c",j);
				}
				i++;
			}
			else printf("-");
		}
	}
	return 0;
}



#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
char a[1000];
int main()
{
	gets(a);
	int s=strlen(a);
	int i,j;
	char t;
	printf("%c",a[0]);
	for(i=1;i<s-1;i++)
	{
		if(a[i]!='-')
			printf("%c",a[i]);
		if(a[i]=='-')
		{
			if((a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')||
			    (a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z')||
				(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'))
			{
				t=a[i-1]+1;
				while(t!=a[i+1])
				{
					printf("%c",t);
					t++;
				}
			}
			else
				printf("-");
		}
	}
	printf("%c",a[s-1]);
	return 0;
}



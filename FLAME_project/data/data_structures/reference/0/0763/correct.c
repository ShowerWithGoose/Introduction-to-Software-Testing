#include<stdio.h>
#include<string.h>
int main()
{
	int x,n; 
	char a[2]="-",b[10000];
	scanf("%s",b);
	for(x=0;b[x]!='\0';x++)
	{
		if(b[x]!=a[0])
		printf("%c",b[x]);
		else if(b[x]==a[0]&&b[x+1]!='\0')
		{
			if((((b[x-1]>=48&&b[x-1]<=57)&&(b[x+1]>=48&&b[x+1]<=57))||((b[x-1]>=97&&b[x-1]<=122)&&(b[x+1]>=97&&b[x+1]<=122))||((b[x-1]>=65&&b[x-1]<=90)&&(b[x+1]>=65)&&b[x+1]<=90))&&(b[x-1]<b[x+1]))
			for(n=b[x-1]+1;n<=b[x+1]-1;n++)
			printf("%c",n);
			else printf("-");
		}
	}
	return 0;
}


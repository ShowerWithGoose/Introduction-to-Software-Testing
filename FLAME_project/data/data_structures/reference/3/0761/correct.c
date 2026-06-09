#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char a[81];
	int i=0,j,k,p;
	while((a[i]=getchar())!='\n')
	i++;
	i--;
	for(j=0;j<=i;j++)
	{
		if(a[j]!='0'&&a[j]!='.')
		break;
	}
	for(k=0;k<=i;k++)
	{
		if(a[k]=='.')
		break;
	}
	printf("%c",a[j]);
	if(j!=i)
	printf(".");
	for(p=j+1;p<=i;p++)
	{
		if(a[p]!='.')printf("%c",a[p]);
	}
	if(a[0]!='0')
	printf("e%d",k-j-1);
	else
	printf("e%d",k-j);
}


#include <stdio.h>
#include <string.h>
int main()
{
	char a[99999];
	int i=0,k,x,j,z;
	scanf("%s",a);
	x=strlen(a);
	for(j=0;j<x;j++)
	{
	if((a[i]>=48)&&(a[i+1]==45)&&(a[i+2]<=57))
	{
		for(k=a[i];k<a[i+2];k++)
		{	z=k;
			printf("%c",z);
		}
	}
	else if((a[i]>=65)&&(a[i+1]==45)&&(a[i+2]<=90))
	{
		for(k=a[i];k<a[i+2];k++)
		{	z=k;
			printf("%c",z);
		}
	}
	else if((a[i]>=97)&&(a[i+1]==45)&&(a[i+2]<=122))
	{
		for(k=a[i];k<a[i+2];k++)
		{	z=k;
			printf("%c",z);
		}
	}
	else if(a[i]==45)
	if(((a[i-1]>=48)&&(a[i+1]<=57))||((a[i-1]>=65)&&(a[i+1]<=90))||((a[i-1]>=97)&&(a[i+1]<=122)))
	;
	else
	printf("-");
	else
	printf("%c",a[i]);
	
	i++;
    }
	
	return 0;
	
}


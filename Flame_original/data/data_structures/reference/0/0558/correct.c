#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{   char k;
int i,j;
	char a[200];
	char b[200];
	scanf("%s",a);
	for(i=0,j=0;i<=strlen(a);i++)
	{   
		if(a[i]=='-')
		{
			if((a[i-1]<=90&&a[i-1]>=65&&a[i+1]<=90&&a[i+1]>=65&&a[i+1]>a[i-1])||(a[i-1]<=122&&a[i-1]>=97&&a[i+1]<=122&&a[i+1]>=97&&a[i+1]>a[i-1])||(a[i-1]<=58&&a[i-1]>=47&&a[i+1]<=58&&a[i+1]>=47&&a[i+1]>a[i-1]))
			{
				for(k=a[i-1]+1;k<=a[i+1]-1;k++)
				{
					b[j]=k;
					j++;
				}
			}
			else{
			 b[j]=a[i];
			 j++;}
		}
		else {
		b[j]=a[i];
		j++;}
	}
	
	for(i=0;i<=strlen(b)-1;i++)
	{
		printf("%c",b[i]);
	}
	return 0;
}


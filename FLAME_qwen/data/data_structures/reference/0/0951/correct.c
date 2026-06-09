//1-1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
	char a[10000],b[10000];
	int i,j,k;
	gets(a);
	b[0]=a[0];
	for(i=j=1;a[i]!='\0';i++)
	{
		if(a[i]=='-' && a[i-1]<a[i+1] && a[i-1]>='0' && a[i-1]<='9' && a[i+1]>='0' && a[i+1]<='9')
		{
			for(j,k=1;b[j-1]<a[i+1]-1;j++,k++)
				b[j]=a[i-1]+k;
		}
		else if(a[i]=='-' && a[i-1]<a[i+1] && a[i-1]>='a' && a[i-1]<='z' && a[i+1]>='a' && a[i+1]<='z')
		{
			for(j,k=1;b[j-1]<a[i+1]-1;j++,k++)
				b[j]=a[i-1]+k;
		}
		else if(a[i]=='-' && a[i-1]<a[i+1] && a[i-1]>='A' && a[i-1]<='Z'&& a[i+1]>='A' && a[i+1]<='Z')
		{
			for(j,k=1;b[j-1]<a[i+1]-1;j++,k++)
				b[j]=a[i-1]+k;
		}
		else
			b[j++]=a[i]; 
	}
	puts(b);
	return 0;
}



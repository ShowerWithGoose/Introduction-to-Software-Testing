#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=1;
	char a[100],b[100];
	gets(a);
	b[0]=a[0];
	for(i=1;a[i]!='\0';i++)
	{
		if(a[i]=='-'&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')
		||(a[i-1]>='0')&&(a[i+1]<='9'))&&a[i-1]<a[i+1])
		{
			int len=a[i+1]-a[i-1]-1;
			int k;
			for(k=1;k<=len;k++)
			{
				b[j++]=a[i-1]+k;
			}
			continue;
		}
		b[j++]=a[i];
	}
	b[j]='\0';
	puts(b);
	return 0;
	
}



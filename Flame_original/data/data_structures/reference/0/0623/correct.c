#include<stdio.h>
char a[10005];
int main()
{
	int i;
	char k;
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		for(;a[i]!='-'&&a[i]!='\0';i++)printf("%c",a[i]);
		if(a[i]=='-'&&(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'))
		for(k=a[i-1]+1;k<a[i+1];k++)printf("%c",k);
		else if(a[i]=='-'&&(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'))
		for(k=a[i-1]+1;k<a[i+1];k++)printf("%c",k);
		else if(a[i]=='-'&&(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'))
		for(k=a[i-1]+1;k<a[i+1];k++)printf("%c",k);
		else printf("%c",a[i]);
	}
	return 0;
}


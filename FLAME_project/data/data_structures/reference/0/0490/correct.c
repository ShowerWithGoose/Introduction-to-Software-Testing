#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100],k;
	int i=0,j=0;
	gets(a);
	while(a[i]!='\0'){
		b[j++]=a[i];
	if(a[i+1]=='-'&&a[i]<a[i+2]&&(((a[i]>='0'&&a[i]<='9')&&(a[i+2]>='0'&&a[i+2]<='9'))||((a[i]>='a'&&a[i]<='z')&&(a[i+2]>='a'&&a[i+2]<='z'))||((a[i]>='A'&&a[i]<='Z')&&(a[i+2]>='A'&&a[i+2]<='Z'))))
{
		for(k=a[i]+1;k<a[i+2];k++)
		b[j++]=k;
		i=i+2;
	}
	else
	i++;
}
	b[j]='\0';
	puts(b);
	return 0;
}


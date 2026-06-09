#include<stdio.h>
#include<string.h>
int main(){
	char c[110]={'\0'};
	int i,pt,e,p,l;
	gets(c);
	l=strlen(c);
	for(i=0;i<l;i++)
		if(c[i]=='.')
		break;
	pt=i;
	for(i=0;i<l;i++)
		if(c[i]!='.'&&c[i]!='0')
		break;
	e=pt-i-1;
	if(e<0)
	e++;
	p=i;
	for(;i<l;i++){
		if(c[i]=='.')
		continue;
		if(i==p&&i<l-1)
		printf("%c.",c[i]);
		else
		printf("%c",c[i]);
	}
	printf("e%d",e);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int main(){
	char a[600];
	gets(a);
	char m;int i;
	int len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]=='-')
		{if(isupper(a[i-1])&&isupper(a[i+1])&&a[i+1]>a[i-1]){
			for(m=a[i-1]+1;m<a[i+1];m++)
			printf("%c",m);
		}
		else if(islower(a[i-1])&&islower(a[i+1])&&a[i+1]>a[i-1]){
			for(m=a[i-1]+1;m<a[i+1];m++)
			printf("%c",m);
		}
		else if(isdigit(a[i-1])&&isdigit(a[i+1])&&a[i+1]>a[i-1]){
			for(m=a[i-1]+1;m<a[i+1];m++)
			printf("%c",m);
		}
		else printf("%c",a[i]);
		}
		else printf("%c",a[i]);
	}
	return 0;
} 




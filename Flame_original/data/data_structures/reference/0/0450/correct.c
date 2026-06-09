#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int OK(char a,char b){
	if((islower(a)!=0&&islower(b)!=0||isupper(a)!=0&&isupper(b)!=0||isdigit(a)!=0&&isdigit(b)!=0)&&a<b) return 1;
	else return 0;
}

int main()
{
	char s[100];
	int i,j,l;
	char *p=NULL,*q=NULL,*t;
	scanf("%s",s);
	getchar();
	l=strlen(s);
	
	t=strchr(s,'-');
	if(t=NULL){
		puts(s);
		return 0;
	}
	
	for(p=s;(q=strchr(p,'-'))!=NULL&&*(q+1)!='\0';p=q+1){
		if(OK(*(q-1),*(q+1))){
			for(i=0;i<q-p;i++) putchar(*(p+i));
			for(j=1;j<(*(q+1)-*(q-1));j++){
				putchar(*(q-1)+j);
			}
		}
		else{
			for(i=0;i<q-p+1;i++) putchar(*(p+i));
		}	
	}
	for(i=0;i<l-(p-s);i++) putchar(*(p+i));
	
	return 0;
}




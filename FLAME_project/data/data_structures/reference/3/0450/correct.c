#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
	char s[100];
	int i,j,n,head=0,tail=0;
	int num[100]={0};
	gets(s);
	int l=strlen(s);
	char *p,*t,*q,*nz;
	
	t=s;
	nz=s;
	while(*nz=='0'||*nz=='.') nz++;
	p=strchr(s,'.');
	n=p-t-1;
	q=&s[l-1];
	while(*q=='0') q--;
	for(i=0;i<=q-t;i++){
		if(s[i]!='.'){
			num[tail++]=(int)(s[i]-'0');
		}
	}
	
	if(0==n&&s[0]=='0'){
		n=-(nz-p);
		for(j=0;j<tail;j++){
			if(num[j]!=0) break;
		}
		head=j;	
	}
	
	printf("%d",num[head++]);
	if(num[head]!=0) putchar('.');
	while(head!=tail){
		printf("%d",num[head++]);
	}
	printf("e%d",n);
	
	return 0;
}


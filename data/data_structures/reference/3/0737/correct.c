#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,t=0,h=0,aa=0,ba=0,record=0,com=0,mid=0,end=0;
	char al;
	char c[200],a[100]="0",b[100]="0";
	gets(c);
	for(h=0;c[h]!='.';h++){
		a[aa]=c[h];
		aa+=1;
	}
	a[aa]='\0'; 
	h+=1;
	for(h=h;c[h]!='\0';h++){
		b[ba]=c[h];
		ba+=1;
	}
	if(a[0]=='0'){
		al='-';
		for(t=0;b[t]=='0';t++);
		printf("%c",b[t]);
		if(b[t+1]!='\0')
		printf(".");
		i=t;
		for(t+=1;b[t]!='\0';t++){
			printf("%c",b[t]);
		}
	}
	else if(a[0]!='0'&&a[1]=='\0'){
		printf("%c.",a[0]);
		for(com=0;com<ba;com++)
		printf("%c",b[com]);
		printf("e0");
		return 0;
	}
	else {
		for(mid=0;a[mid]!='\0';mid++);
		printf("%c.",a[0]);
		for(end=1;a[end]!='\0';end++){
			printf("%c",a[end]);
		}
		for(end=0;b[end]!='\0';end++){
			printf("%c",b[end]);
		}
		printf("e");
		printf("%d",mid-1);
		return 0; 
	}
	
	printf("e");
	if(al=='-')
	printf("-");
	printf("%d",i+1);
 return 0;
}




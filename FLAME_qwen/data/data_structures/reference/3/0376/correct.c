#include<stdio.h>
#include<string.h>
char a[200];
char b[200];
int main()
{
	int i,j,e,f;
	gets(a);
	if(a[0]=='0'){
		i=2;
		while(a[i]=='0') i++;
		j=0;
		e = 1-i;
		for(;a[i]!='\0';i++) b[j++]=a[i];
		if(j==1) printf("%ce%d",b[0],e);
		else {
			printf("%c.",b[0]);
			for(i=1;b[i]!='\0';i++) putchar(b[i]);
			printf("e%d",e);
		}
	}
	else{
		e=f=j=0;
		for(i=0;a[i]!='\0';i++){
			if(a[i]=='.') {	f=1;continue;}
			if(f==0) e++;
			b[j++]=a[i];
		}
		printf("%c.",b[0]);
		for(i=1;b[i]!='\0';i++) putchar(b[i]);
		printf("e%d",e-1);
	}
}
 


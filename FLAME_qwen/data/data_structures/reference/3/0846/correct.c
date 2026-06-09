#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
int main(int argc, char *argv[]) {
	char c[200];
	int z,a,b,i,j,k,p,n;
	gets(c);
	
	for(i=0;c[i]!='.';i++);
	p=i;
	if(p>1){
		n=p-1;
		for(i=0;c[i]!='\0';i++){
			if(i==1)printf(".");
			if(c[i]!='.')printf("%c",c[i]);
		}
		printf("e%d",n);
	}
	else {
		if(c[0]>'0'){
			for(i=0;c[i]!='\0';i++){
			printf("%c",c[i]);
			}
			printf("e0");
		}
		else {
			for(i=2;c[i]=='0';i++);
			p=i;
			n=p-1;
			for(i=p;c[i]!='\0';i++){
				if(i==p+1) printf(".%c",c[i]);
			else printf("%c",c[i]);
			}
			printf("e-%d",n);
		}
	}
		return 0;
}



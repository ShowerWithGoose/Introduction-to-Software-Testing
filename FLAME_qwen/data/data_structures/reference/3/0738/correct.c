#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main() {
	char s[200];
	gets(s);
	int i;
	int len;
	int d1,d2,flag=0,sum=0;
	len=strlen(s);
	unsigned long long in=0;
	for(i=0; i<len; i++) {
		if(s[i]!='.'&&s[i]!='0'&&flag==0){
			d1=i;
			flag=1;
		}else if(s[i]=='.'){
			d2=i;
		}
		if(s[i]<='9'&&s[i]>'0'){
			sum++;
		}
	}
	printf("%c",s[d1]);
	if(sum>1){
		printf(".");
	}
	for(i=d1+1;i<len;i++){
		if(s[i]=='.'){
			
		}else{
			printf("%c",s[i]);
		}
	}
	if(d1<d2){
		printf("e%d",d2-d1-1);
	}else{
		printf("e%d",d2-d1);
	}
	
	return 0;
}


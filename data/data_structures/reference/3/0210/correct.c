#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int cnt=0;
	char *a = (char*)malloc(10000*sizeof(char));
	scanf("%[^\n]",a);
	if(*a!='0'){
		char *p = a;
		while(*p != '.'){
			p++; cnt++;// num of num before .
		}
		*p='\0';
		printf("%c.%s%se%d",*a,(a+1),(p+1),cnt-1);
	}else{
		a+=2;
		while(*a == '0'){
			a++; cnt++;
		}
		if(*(a+1)!='\0'){
			printf("%c.%se%d",*a,(a+1),-cnt-1);
		}else{
			printf("%ce%d",*a,-cnt-1);
		}
	} 
}


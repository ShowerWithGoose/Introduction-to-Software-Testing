#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char num[105]={0};
	int i=0,n,m;
    scanf("%s",num);
		while(num[i]!='.'&&num[i]!='\0'){
			i++;
		}
		n=i;
		i=0;
		while(num[i]=='0'||num[i]=='.'){
			i++;
		}
		printf("%c",num[i]);
		i++;
		m=i;
		if(num[i]=='\0') printf("e%d",n>=m?0:n-m+1);
		else{
			printf(".");
			while(num[i]!='\0'){
				if(num[i]!='.'){
					printf("%c",num[i]);
					i++;
				} 
				if(num[i]=='.') i++;
			}
			printf("e%d",n>=m?n-m:n-m+1);
		}
	return 0;
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int find(char c[],int len){
	int flag;
	int i=0;
	for(i=0;i<len;i++){
		if(c[i]=='.'){
			flag=1;
		}
	}
	if(flag==1)return 1;
	else return 0;
}
int main(){
	char c[105];
	gets(c);
	int n,m;
    int i;
	if(c[0]>'0'){
		if(c[1]=='.'){
			printf("%s",c);
			printf("e0");
		}
		if(c[1]!='.'){
			if(find(c,strlen(c))==1){
				for(i=2;i<strlen(c);i++){
					if(c[i]=='.'){
						m=i;
						break;
					}
				}
				printf("%c",c[0]);
				printf(".");
				for(i=1;i<m;i++){
					printf("%c",c[i]);
				}
				for(i=m+1;c[i]!='\0';i++){
					printf("%c",c[i]);
				}
				printf("e%d",m-1);
				
			}
			else{
			printf("%c",c[0]);
			printf(".");
			for(i=1;i<strlen(c);i++){
				printf("%c",c[i]);
			}
			printf("e%d",strlen(c)-1);
		}
		}
		
	} 
	if(c[0]=='0'){
		for(i=2;i<strlen(c);i++){
			if(c[i]!='0'){
				n=i;
				break;
			}
		}
		if(n==strlen(c)-1){
			printf("%c",c[n]);
			printf("e-%d",n-1);
		}
		else{
			printf("%c",c[n]);
			printf(".");
			for(i=n+1;c[i]!='\0';i++){
				printf("%c",c[i]);
			}
			printf("e-%d",n-1);
		}
	}
	return 0;
} 


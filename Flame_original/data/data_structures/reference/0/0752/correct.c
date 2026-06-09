#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxsize 10000
int main(){
	char str[maxsize];
	gets(str);
	char *temp=str;
	char *loc;
	while((loc=strchr(temp,'-'))!=NULL){
		if(isdigit(loc[-1])&&isdigit(loc[1])&&loc[1]>loc[-1]){
			loc[0]='\0';
			printf("%s",temp);
			for(int i=loc[-1]-'0'+1;i<=loc[1]-'0';i++){
				printf("%d",i);
			}
			temp=loc+2;
			continue;
		}
		if(islower(loc[-1])&&islower(loc[1])&&loc[1]>loc[-1]){
			loc[0]='\0';
			printf("%s",temp);
			for(int i=loc[-1]+1;i<=loc[1];i++){
				printf("%c",i);
			}
			temp=loc+2;
			continue;
		}
		if(isupper(loc[-1])&&isupper(loc[1])&&loc[1]>loc[-1]){
			loc[0]='\0';
			printf("%s",temp);
			for(int i=loc[-1]+1;i<=loc[1];i++){
				printf("%c",i);
			}
			temp=loc+2;
			continue;
		}
		*loc='\0';
		printf("%s-",temp);
		temp=loc+1;
	}
	puts(temp);
	return 0;
}


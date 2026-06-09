#include <stdio.h>
#include <string.h>
char a[105];
int main(){
	int count=0;
	int i=0;
	gets(a);
	while(a[i]!='.'&&a[i]){
		count++;i++;
	}
	if(a[0]!='-'){
		if(count==1&&a[0]!='0'){
			printf("%se0",a);
		}
		else if(count>1){
			printf("%c.",a[0]);
			for(int j=1;j<count;j++)
				printf("%c",a[j]);
			for(int j=count+1;j<strlen(a);j++)
				printf("%c",a[j]);
			printf("e%d",count-1);
		}
		else{
			int k=0;count=0;
			while(a[k]=='0'||a[k]=='.'){
				count++;
				k++;
			}
			if(count>1){
				printf("%c",a[count]);
				if(strlen(a)-count>1){
					printf(".");
					for(int j=count+1;j<strlen(a);j++)
						printf("%c",a[j]);
				}
				printf("e-%d",count-1);
			}
			else
				printf("0");
		}
	}
	else{
		if(count==2&&a[1]!='0'){
			printf("%se0",a);
		}
		else if(count>2){
			printf("-%c.",a[1]);
			for(int j=2;j<count;j++)
				printf("%c",a[j]);
			for(int j=count+1;j<strlen(a);j++)
				printf("%c",a[j]);
			printf("e%d",count-1);
		}
		else{
			int k=1;count=0;
			while(a[k]=='0'||a[k]=='.'){
				count++;
				k++;
			}
			if(count>1){
				printf("-%c",a[count+1]);
				if(strlen(a)-count>2){
					printf(".");
					for(int j=count+2;j<strlen(a);j++)
						printf("%c",a[j]);
				}
				printf("e-%d",count-1);
			}
		}
	}
	
	return 0;
} 


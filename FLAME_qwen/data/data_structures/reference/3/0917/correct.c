#include<stdio.h>
#include<string.h>
int main(){
	int i,j,k=0;
	char str[200];
	scanf("%s",str);
	if(str[0]=='0'&&str[1]=='.'){
		for(i=2;str[i]=='0';i++){
			k++;
		}	
		printf("%c",str[i]);
		if(str[i+1]=='\0'){
			printf("e-%d",k+1);
		}
		else{
			printf(".");
			for(j=i+1;j<strlen(str);j++){
				printf("%c",str[j]);
			}
			printf("e-%d",k+1);
		}
	}//没有整数部分
	else if(str[0]!='0'&&str[1]!='.'){
		printf("%c.",str[0]);
		for(i=1;i<strlen(str);i++){
			if(str[i]!='.')
				printf("%c",str[i]);
			else
				k=i;
		}
		printf("e%d",k-1);
	} //整数部分大于一位数
	else{
		for(i=0;i<strlen(str);i++){
			printf("%c",str[i]);
		} 
		printf("e0");
	} 
	return 0;
}




#include<stdio.h>
#include<string.h>

int main(){
	char str[110];
	gets(str);
	int loc=strchr(str,'.')-str;
	if(loc>1){
		printf("%c.",str[0]);
		for(int i=1;str[i]!='\0';i++){
			if(str[i]=='.') continue;
			printf("%c",str[i]);
		}
		printf("e%d",loc-1);
	}
	else if(str[0]=='0'){
		int j;
		for(j=2;str[j]=='0';j++);
		printf("%c",str[j]);
		if(str[j+1]!='\0') printf(".");
		for(int i=j+1;str[i]!='\0';i++)
			printf("%c",str[i]);
		printf("e%d",-(j-1));
	}
	else{
		printf("%se0",str); 
	}
	return 0;
} 


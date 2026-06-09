#include<stdio.h>
#include<string.h>
int main(){
	char num[100];
	int place,tot=1;
	gets(num);
	for(int i=0;i<strlen(num);i++){
		if(num[i]=='.'){
			place=i;
			break;
		}
	}
	if(num[0]!='0'){
		printf("%c.",num[0]);
		for(int i=1;i<strlen(num);i++){
			if(num[i]!='.')
			printf("%c",num[i]);
		}
		printf("e%d",place-1);
	}
	else{
		for(int i=place+1;i<strlen(num);i++){
			if(num[i]=='0')
			tot++;
			if(num[i]>'0')
			break;
		}
		if(tot==strlen(num)-2)
		printf("%ce-%d",num[tot+1],tot);
		else{
			printf("%c.",num[tot+1]);
			for(int i=tot+2;i<strlen(num);i++)
			printf("%c",num[i]);
			printf("e-%d",tot);
		
		}
	}
	return 0;
} 


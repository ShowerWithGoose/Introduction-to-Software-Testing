#include<stdio.h>
#include<string.h>
int main(){
	char string[105];
	scanf("%s",string);
	int len;
	len=strlen(string);
	int i=0,j;
	int cnt=0;//0.09--- 9e-2  0.091 ----  9.1e-2
	if(string[0]=='0'){
	while(string[i]=='0'||string[i]=='.'){
				i++;cnt++;
		}
		cnt--;
		printf("%c",string[i]);
		if(string[i+1]!='\0'){
			printf(".");
			i++;
			while(string[i]!='\0') {
			printf("%c",string[i]);
			i++;}
		}
		printf("e"); printf("-");printf("%d",cnt);
	}
	if(string[0]=='-'&&string[1]=='0'){
	while(string[i]=='0'||string[i]=='.'||string[i]=='-'){
				i++;cnt++;
		}
		cnt-=2;
		printf("-");
		printf("%c",string[i]);
		if(string[i+1]!='\0'){
			printf(".");
			while(string[i]!='\0') {
			printf("%c",string[i]);
			i++;}
		}
		printf("e"); printf("-");printf("%d",cnt);
	}
	if(string[0]!='0'&&string[0]!='-'){
	if(string[1]=='.'){
		for(i=0;i<len;i++)
		printf("%c",string[i]);
		printf("e0");
		}
	else {
		printf("%c",string[0]);
		printf(".");j=0;
		while(string[j]!='.'){
			j++;
			cnt++;
		}
		for(i=1;i<len;i++){
			if(string[i]!='.') printf("%c",string[i]);
			}
			printf("e");
			printf("%d",cnt-1);
		}
	}
	if(string[0]=='-'&&string[1]!='0'){
	if(string[2]=='.'){
		for(i=0;i<len;i++)
		printf("%c",string[i]);//-3.56  -3.56e0
		printf("e0");
		}
	else {
		printf("%c",string[0]);
		printf("%c",string[1]);//-33.56 -3.356e1
		printf(".");j=0;
		while(string[j]!='.'){
			j++;
			cnt++;
		}
		for(i=2;i<len;i++){
			if(string[i]!='.') printf("%c",string[i]);
			}
			printf("e");
			printf("%d",cnt-2);
		}
	}
	return 0;
}




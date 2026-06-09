#include<stdio.h>
#include<string.h>
#define MAX 999
int judge(char,char);
void print(char,char);
char num[MAX];
int main ()
{
	gets(num);
	int i;
	for(i=0;i<strlen(num);i++){
		if(num[i]=='-'){
			if(judge(num[i-1],num[i+1])){
				print(num[i-1],num[i+1]);
			}
			else printf("%c",num[i]);
		}
		else printf("%c",num[i]);
	}
	return 0;
}

int judge(char a,char b){
	if(b-a>1){
		if(a>='a'&&a<='z'&&b>='a'&&b<='z')
			return 1;
		if(a>='A'&&a<='Z'&&b>='A'&&b<='Z')
			return 1;
		if(a>='0'&&a<='9'&&b>='0'&&b<='9')
			return 1;
		else return 0;
	}
	else return 0;
}

void print(char a,char b){
	int j,k;
	j=b-a-1;
	a++;
	for(k=0;k<j;k++){
		printf("%c",a++);
	}
}


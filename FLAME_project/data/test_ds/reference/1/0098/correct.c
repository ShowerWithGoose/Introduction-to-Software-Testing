#include<stdio.h>
#include<string.h>

void kuozhan(char c1,char c2);
int check(char a,char b); 
int main(){
	char s[1005];
	gets(s);
	int i,n=strlen(s);
	for(i=0;i<n-1;i++){
		if(s[i+1]!='-'){
			printf("%c",s[i]);
		}
		else{
			kuozhan(s[i],s[i+2]);//扩展函数中输出不带‘-’后面的
			i++; 
		}
	}
	printf("%c",s[n-1]);
	return 0;
}
void kuozhan(char c1,char c2){
	int i;
	if(c2<=c1){
		printf("%c-",c1);
		return;
	}
	if(check(c1,c2)){
		for(i=c1;i<c2;i++){
			printf("%c",i);
		}
	}
	else{
		printf("%c-",c1);
	}
	return;
}
int check(char a,char b){
	int s=0;
	if(a>='a'&&a<='z'&&b>='a'&&b<='z') s=1;
	else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z') s=1;
	else if(a>='0'&&a<='9'&&b>='0'&&b<='9') s=1;
	return s;
}



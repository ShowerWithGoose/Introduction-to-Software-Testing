#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void string(char a,char b){
	int i=0,j=1;
	i=(int )(b-a);
	while(j<i){
		printf("%c",a+j);
		j++;
	}
	return;
}
int judge(char a,char b){
	int i=0;
	if(('0'<=a)&&(a<b)&&(b<='9')) i=1;
	else if(('a'<=a)&&(a<b)&&(b<='z')) i=1;
	else if(('A'<=a)&&(a<b)&&(b<='Z')) i=1;
	return i;
}
int main(){
	char s[500];
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++){
		if(s[i]!='-')
		 printf("%c",s[i]);
		else if(s[i]=='-'){
			if(judge(s[i-1],s[i+1])){
				string(s[i-1],s[i+1]);
			}
			else
			 printf("-");
			 
		}
	}
	return 0;
}


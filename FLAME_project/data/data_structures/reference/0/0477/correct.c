#include<stdio.h>
#include<string.h>
#include<math.h>
int judge(char c){
	if(c>='0'&&c<='9') return 1;
	else if(c>='a'&&c<='z') return 2;
	else if(c>='A'&&c<='Z') return 3;
}
int main(){
 char s[10000];
 gets(s);
 int flag1 = 0 , flag2 = 0;
 int i = 1;
 while(s[i]!='\0'){
 	if(flag1 == 0){
 		if(s[i] == '-'){
 			flag1 = 1;
		 }
		 else {
		 printf("%c",s[i-1]);
		 }
	 }
	 else if(flag1==1){
	 	flag1 = 0;
	 	if(judge(s[i])==judge(s[i-2])&&s[i]>s[i-2]){
			while(s[i]>s[i-2]){
		 		printf("%c",s[i-2]);
		 		s[i-2]++;	
		 	}
		}
		 else{
			printf("%c-",s[i-2]);
			}
		 }
		 i++;
	 }
	 printf("%c",s[i-1]);
	 
 }	



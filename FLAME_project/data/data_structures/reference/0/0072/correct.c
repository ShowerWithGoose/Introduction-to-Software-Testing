#include <stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char s[1000];
	char s1;
	int i=0; 
	gets(s);
	for(i=0;i<strlen(s);i++){
	if(s[i]=='-'){
	{
		if(s[i+1]<='z'&&s[i-1]>='a'&&s[i+1]>s[i-1]){
			s[i]=='\0';	
			for(s1=s[i-1]+1;s1<s[i+1];s1++){
				printf("%c",s1);
			}
		}
		
		else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){
			s[i]=='\0';
			for(s1=s[i-1]+1;s1<s[i+1];s1++){
				printf("%c",s1);
			}
		}
		
		else if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){
		s[i]=='\0';
			for(s1=s[i-1]+1;s1<s[i+1];s1++){
				printf("%c",s1);
			}
		}
		else{
			printf("%c",s[i]);
		}
			
	}}
	else{
		printf("%c",s[i]);
	}
	
}} 


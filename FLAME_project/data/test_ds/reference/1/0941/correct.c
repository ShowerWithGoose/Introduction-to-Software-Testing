#include<stdio.h>
#include<string.h>//#include<stdlib.h>
int main(){
	char s[100];
	gets(s);
	int i,j = strlen(s)-1,k;
	for(i=0;i<=j;i++){
		if(s[i]>='a'&&s[i]<='z'&&s[i+1] == '-'&&s[i+2]>='a'&&s[i+2]<='z'&&s[i+2]>s[i]){
					for(k=0;s[i]+k<s[i+2];k++){
						printf("%c",s[i]+k);
					}
					i++;			
		}
		else if(s[i]>='A'&&s[i]<='Z'&&s[i+1] == '-'&&s[i+2]>='A'&&s[i+2]<='Z'&&s[i+2]>s[i]){
					for(k=0;s[i]+k<s[i+2];k++){
						printf("%c",s[i]+k);
					}
					i++;			
		}
		else if(s[i]>='0'&&s[i]<='9'&&s[i+1] == '-'&&s[i+2]>='0'&&s[i+2]<='9'&&s[i+2]>s[i]){
					for(k=0;s[i]+k<s[i+2];k++){
						printf("%c",s[i]+k);
					}
					i++;			
		}				
		else{
			printf("%c",s[i]);
			//printf("%d",i);
		}
	}
return 0;
}



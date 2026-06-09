#include<stdio.h>
int main(){
	char s[50];
	gets(s);
	int i,j,a,b;
	for(i=0;s[i]!='\0';i++){
		if(s[i]!='-'){
			printf("%c",s[i]);				
			}
		else {
			if(s[i-1]<s[i+1]){
				if((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z')){
					for(a=1,b=s[i+1]-s[i-1];a<b;a++){
						printf("%c",s[i-1]+a);
					}
					
				}
				else if((s[i-1]>='A'&&s[i-1]<='Z')&&(s[i+1]>='A'&&s[i+1]<='Z')){
					for(a=1,b=s[i+1]-s[i-1];a<b;a++){
						printf("%c",s[i-1]+a);
					}
					
				}
				else if((s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]>='0'&&s[i+1]<='9')){
					for(a=1,b=s[i+1]-s[i-1];a<b;a++){
						printf("%c",s[i-1]+a);
				}
			
			}
				else printf("%c",s[i]);
		}
		}
	}
}


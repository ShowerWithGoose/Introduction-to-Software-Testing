#include<stdio.h>
void kuozhan(char x,char y){
	for(int i=1;i<y-x;i++){
		printf("%c",x+i);
	}
}
int main()
{
	char s[100];
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++){
		if(s[i]=='-'&&s[i+2]!='-'){
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]<='z'&&s[i+1]>s[i-1]){
				kuozhan(s[i-1],s[i+1]);
			}
			else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]<='Z'&&s[i+1]>s[i-1]){
				kuozhan(s[i-1],s[i+1]);
			}
			else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]<='9'&&s[i+1]>s[i-1]){
				kuozhan(s[i-1],s[i+1]);
			}
			else
			printf("%c",s[i]);
		}
		else if(s[i]=='-'&&s[i+2]=='-'){
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]<='z'&&s[i+1]>s[i-1]){
				if(s[i+3]<='z'&&s[i+3]>s[i+1]){
					kuozhan(s[i-1],s[i+3]);
					i=i+2;
				}
				else{
					kuozhan(s[i-1],s[i+1]);
				}
			}
			else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]<='Z'&&s[i+1]>s[i-1]){
				if(s[i+3]<='Z'&&s[i+3]>s[i+1]){
					kuozhan(s[i-1],s[i+3]);
					i=i+2;
				}
				else
				kuozhan(s[i-1],s[i+1]);
			}
			else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]<='9'&&s[i+1]>s[i-1]){
				if(s[i+3]<='9'&&s[i+3]>s[i+1]){
					kuozhan(s[i-1],s[i+3]);
					i=i+2;
				}
				else
				kuozhan(s[i-1],s[i+1]);
			}
		}
		else
		printf("%c",s[i]);
	}
	return 0;
}


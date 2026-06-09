#include<stdio.h>
#include<string.h>
char s[1000];
int main(){
	gets(s);
	int k=strlen(s);
	for(int i=0;i<k;i++){
		if(s[i]!='-')printf("%c",s[i]);
		else {//ÊÇ- 
			if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A'&&s[i+1]>s[i-1]){
				for(int j=s[i-1]-'A';j<s[i+1]-'A'-1;j++){
					printf("%c",'A'+j+1);
				}
			}
			else if(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0'&&s[i+1]>s[i-1]){
					for(int j=s[i-1]-'0';j<s[i+1]-'0'-1;j++){
					printf("%c",'0'+j+1);
				}
			}
			else if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a'&&s[i+1]>s[i-1]){
				for(int j=s[i-1]-'a';j<s[i+1]-'a'-1;j++){
					printf("%c",'a'+j+1);
				}
			}
			else printf("-");
		}
	}
	return 0;
}




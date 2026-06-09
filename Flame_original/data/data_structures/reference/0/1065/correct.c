#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	int i,j;
	gets(s);
	
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='-'){
			if((s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])||(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])||(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])){
				for(j=1;j<=s[i+1]-s[i-1];j++){
					printf("%c",s[i-1]+j);
				}
				i+=1;
			}
			else
				printf("%c",s[i]);
		}
	else 
		printf("%c",s[i]);
	}
	return 0;
}


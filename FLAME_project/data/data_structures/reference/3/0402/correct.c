#include <stdio.h>
#include <string.h>
int main(){
	int i=2,k; 
	char s[105];
	gets(s);
	if(s[1]=='\0'){
		printf("%ce0",s[0]);
		return 0;
	}
	if(s[0]=='0'){
		while(s[i]=='0') i++;
		printf("%c",s[i]);
		i++;
		k=i;
		if(s[i]=='\0') printf("e-%d",k-2);
		else{
			printf(".");
			while(s[i]!='\0'){
				printf("%c",s[i]);
				i++;
			}
			printf("e-%d",k-2);
		}
	}
	else{
		if(s[1]=='.'){
			for(k=0;s[k]!='\0';k++) printf("%c",s[k]);
			printf("e0");
		}
		else{
			int cnt=0;
			for(k=0;s[k]!='.';k++) cnt=k;
			printf("%c",s[0]);
			printf(".");
			for(k=1;s[k]!='\0';k++){
				if(s[k]=='.'){
					continue;
				}
				printf("%c",s[k]);
			}
			printf("e%d",cnt);
		}
	}
	return 0;
}




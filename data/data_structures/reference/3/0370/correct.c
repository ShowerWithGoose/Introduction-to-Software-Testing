#include<stdio.h>
int main(){
	char s[100]={};
	int i,cnt;
	gets(s);
	if(s[0]=='0'){
		cnt=1;i=2;
		while(s[i]=='0'){
			cnt++;
			i++;
		}
		if(s[i+1]=='\0'){
			printf("%ce-%d",s[i],cnt);
		}
		else{
			printf("%c.",s[i]);
			i++;
			for(;s[i];i++){
				printf("%c",s[i]);
			}
			printf("e-%d",cnt);
		}
	}
	else{
		i=0;cnt=-1;
		while(s[i]!='.'){
			cnt++;
			i++;
		}
		printf("%c.",s[0]);
		for(i=1;s[i];i++){
			if(s[i]!='.') printf("%c",s[i]);
		}
		printf("e%d",cnt);
	}
	
	
}


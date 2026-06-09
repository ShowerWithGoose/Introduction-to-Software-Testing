#include<stdio.h>
#include<string.h>

int main(){
	char s[100000];
	gets(s);
	int locate,ans=0;
	int i;
	for(i=0;s[i]!='.'&&i<strlen(s);i++);
	if(i==strlen(s)){
		for(i=0;i<strlen(s);i++){
			printf("%c",s[i]);
		}
	}
	else if(s[0]!='0'){
	for(locate=0;s[locate]!='.';locate++);
		ans=locate-1;
		for(i = locate;s[1]!='.';i--){
			s[i]=s[i]^s[i-1];
			s[i-1]=s[i]^s[i-1];
			s[i]=s[i]^s[i-1];		
		}
		for(i=0;i<strlen(s);i++){
			printf("%c",s[i]);
		}
		
		printf("e%d",ans);
	}
	else{
		for(locate=0;s[locate]=='0'||s[locate]=='.';locate++);
		for( i = locate;i<strlen(s);i++){
			if(s[i]!='.')printf("%c",s[i]);
			if(i==locate&&locate!=strlen(s)-1)printf(".");
		}
		printf("e-%d",locate-1);
	}
	return 0;
}


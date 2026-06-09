#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char ch[200];
	gets(ch);
	int i,cnt1=0,cnt2=0;
	if(ch[0]=='0'){
		for(i=2;ch[i]=='0';i++){
			cnt1++;
		}
		if(i+1==strlen(ch)){
			printf("%ce-%d",ch[i],i-1);
		}else{
			printf("%c.",ch[i]);
			for(i=i+1;ch[i]!='\0'&&ch[i]!='\n';i++){
				printf("%c",ch[i]);
			}
			printf("e-%d",cnt1+1);
		}
		
	}else{
		printf("%c",ch[0]);
		if(ch[1]=='\0'||ch[i]=='\n') printf("e0");
		else if(ch[1]=='.'){
			printf("%se0",ch+1);
		}
		else{
			printf(".");
			for(i=1;ch[i]!='\0'&&ch[i]!='\n';i++){
				printf(ch[i]=='.'?"":"%c",ch[i]);
				if(ch[i]=='.') cnt2=1;
				if(cnt2==0) cnt1++;
			}
			printf("e%d",cnt1);
		}
		
	}
	return 0;
}



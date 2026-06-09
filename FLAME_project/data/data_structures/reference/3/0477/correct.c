#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>

int main(){
	char s[105];
	int dot = 0;
	int i = 0;
	int all = 0;
	int flag = 0;
	gets(s); 
	while(s[i]!='\0'){
		if(s[i]=='.') dot = i;
		i++;
	}
	all = i;
	int count = 2;
	if(dot==1){
		if(s[0]=='0'){
		while(s[count++]=='0');	
		if(all==count )
		printf("%c",s[count-1]);
		else printf("%c.",s[count-1]);
		for(i = count;i<all;i++){
				printf("%c",s[i]);
		}
		printf("e-%d",count-2);
		}
		else{
			for(i = 0;i<all;i++){
				printf("%c",s[i]);
			}
			printf("e0");
		}
	}
	else if(dot>1){
		printf("%c.",s[0]);
		for(i = 1;i<all;i++){
			if(i!=dot) 
			printf("%c",s[i]);
		}
		printf("e%d",dot-1);
		
	}
}


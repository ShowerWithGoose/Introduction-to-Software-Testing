#include <stdio.h>
#include <string.h>
int main(){
	char s[200];
	gets(s);
	int len= strlen(s);
	int i;
	int point=0;
	int negpoint=0;
	for(i=0;i<len;i++){
		if(s[i]=='.'){
			point=i;
		}
		else if(s[i]!='0'&&s[0]=='0'){
			negpoint=i;
			break;
		}
	}
	if(s[0]!='0'){
		printf("%c.",s[0]);
		for(i=1;i<point;i++){
			printf("%c",s[i]);
		}
		for(i=point+1;i<len;i++){
			printf("%c",s[i]);	
		}
		printf("e%d",point-1);
	}
	else{
		if(negpoint<len-1){
			printf("%c.",s[negpoint]);
			for(i=negpoint+1;i<len;i++){
				printf("%c",s[i]);
			}
		}
		else{
			printf("%c",s[negpoint]);
		}
		printf("e-%d",negpoint-point);
	}
}




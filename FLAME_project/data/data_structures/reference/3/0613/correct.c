#include<stdio.h>
#include<string.h>
char num[105],ans[105];
int main(){
	gets(num);
	int len = strlen(num);
	if(num[0] == '-'){
		for(int l = 1;l<len;l++){
			ans[l-1] = num[l];
		}
		printf("-");
		len--;
	}
	else{
		for(int l=0;l<len;l++){
			ans[l] = num[l];
		}
	}//处理负数 
	int p1 = 0,p2 = 0;
	int l = 0;
	while(l<len){
		if(ans[l] == '.'){
			p1 = l;
			break;
		}
		l++;
	}
	l = 0;
	while(l<len){
	if(ans[l]!='0'&&ans[l]!='.'){
		p2 = l;
		break;
		}
		l++;
	}
	//printf("p1=%d\np2=%d\n",p1,p2);
	int d = 0;
	if(p1<p2){
		d = p1-p2;
		printf("%c",ans[p2]);
		if(p2 != len-1) printf(".");
		for(int l = p2+1;l<len;l++){
			printf("%c",ans[l]);
		}
		printf("e%d",d);
	}
	else{
		d = p1  - p2 - 1;
		printf("%c.",ans[p2]);
		for(int l = p2 + 1;l < len;l++){
			if(l!=p1)printf("%c",ans[l]);
		}
		printf("e%d",d);
	}
	 
	return 0;
} 


#include<stdio.h>
#include<string.h>
#define M 10000
char s[M];
int main(){
	int flag=0,i;
	gets(s);
	for(i=0;i<strlen(s)&&s[i]!='.';i++){
		if(s[i]>'0') flag=1;//i记录了小数点的位置 
	}//判断是否为纯小数，若是，flag为0
	if(flag==0){
		int zeroc=1,k,point=0;
		for(k=i+1;k<strlen(s)&&s[k]=='0';k++){
			zeroc++;
		}
		for(int j=k+1;j<strlen(s);j++){
			point=1;
			break;
		}
		if(point) printf("%c.",s[k]);
		else printf("%c",s[k]);
		for(int j=k+1;j<strlen(s);j++){
			printf("%c",s[j]);
		}
		printf("e-%d",zeroc);
	}//纯小数处理
	else{
		int power=-1,k;
		for(k=i-1;k>=0;k--){
			power++;
		} 
		printf("%c.",s[++k]);
		for(int j=k+1;j<strlen(s);j++){
			if(s[j]!='.')printf("%c",s[j]);
		}
		printf("e%d",power);
	} 
	return 0;
}


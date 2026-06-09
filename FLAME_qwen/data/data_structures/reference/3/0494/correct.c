#include<stdio.h>
#include<string.h>
#define NUM 1
#define LOW 2
#define CAP 3
char num[1005];
int times,f;
int i,j;
int main(){
	scanf("%s",num);
	int len=strlen(num);
	for(i=0;i<len;i++){
		if(num[i]>'0'&&num[i]<='9')f=1;
		if(num[i]=='.'){
			if(f==1){
				times=i-1;
			}else{
				for(j=i+1;j<len;j++){
					if(num[j]=='0')times--;
					else break;
				}
				times--;
			}
			break;
		}
	}
	if(f){
		printf("%c.",num[0]);
		for(int i=1;i<len;i++){
			if(num[i]=='.')continue;
			printf("%c",num[i]);
		}
	}else{
		if(j<len-1){
			printf("%c.",num[j]);
			j++;
		}
		for(i=j;i<len;i++){
			printf("%c",num[i]);
		}
	}
	printf("e%d\n",times);
	return 0;
}



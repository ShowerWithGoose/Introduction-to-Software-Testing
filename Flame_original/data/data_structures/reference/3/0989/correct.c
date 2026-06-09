#include<stdio.h>
#include<ctype.h>//字符类型判断
#include<string.h>//字符串处理
#include<stdlib.h>//qsort,rand,bsearch,
int main(){
	char ch[1005];
	int i,len;
	scanf("%s",ch);
	len=strlen(ch);
	for(i=0;i<len;i++){
		if(ch[i]=='.'){
			break;
		}
	}
	if(i==1){
		if(ch[0]!='0'){
			printf("%se0",ch);
		}else{
			int zhishu=0,j;
			for(j=i+1;j<len;j++){
				if(ch[j]=='0'){
					zhishu++;
				}else{
					break; 
				}
			}
			printf("%c",ch[j]);
			if(ch[j+1]!=NULL){
				printf(".");
			}
			for(j++;j<len;j++){
				printf("%c",ch[j]);
			}
			printf("e-%d",zhishu+1);
		}
	}else{
		printf("%c.",ch[0]);
		int k;
		for(k=1;k<len;k++){
			if(k==i){
				continue;
			}else{
				printf("%c",ch[k]);
			}	
		}
		printf("e%d",i-1);
	}
	return 0;
}


#include<stdio.h>
#include<string.h>
char ori[1024],num[1024],ans[1024];
int i,j,flag,nota,firnum,expo;
int main(){
	gets(ori);
	flag=0;
	for(i=0,j=0;i<strlen(ori);i++){
		if(ori[i]=='.'){
			nota=i;
			continue;
		}
		if(ori[i]-'0'>=1&&!flag){
			flag=1;
			firnum=i;
		}
		if(flag){
			num[j++]=ori[i];
		}
	}
	expo=nota<firnum?nota-firnum:nota-firnum-1;
	
	for(i=0,j=0;i<strlen(num);i++){
		ans[j++]=num[i];
		if(!i&&(strlen(num)!=1))ans[j++]='.';
	}
	printf("%se%d",ans,expo);
	return 0;
}




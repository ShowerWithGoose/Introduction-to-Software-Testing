#include<stdio.h>
#include<string.h>
char num[1024],ans[1024],ans[1024];
int i,ansCount,flag,count,eCount,expo;
int main(){
	gets(num);
	flag=0;
	for(i=0,ansCount=0;i<strlen(num);i++){
		if(num[i]=='.'){
			count=i;
			continue;
		}
		if(num[i]-'0'>=1&&!flag){
			flag=1;
			eCount=i;
		}
		if(flag){
			ans[ansCount++]=num[i];
		}
	}
	expo=count<eCount?count-eCount:count-eCount-1;
	
	for(i=0,ansCount=0;i<strlen(ans);i++){
		ans[ansCount++]=ans[i];
		if(!i&&(strlen(ans)!=1))ans[ansCount++]='.';
	}
	printf("%se%d",ans,expo);
	return 0;
}




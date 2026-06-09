#include<stdio.h>
#include<string.h>
int position[1000]={0};
int len;
char s[1000];
int main() {
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]=='-')
			position[i]=1;   //记录-的位置
	}
	for(int i=0;i<len;i++){
		if(position[i]==0){
			printf("%c",s[i]); //已经输出到了s【i-1】
		}
		else if(position[i]==1){ //说明有-存在，接下来比较是否满足条件
			if((s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])||(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])||(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])){//如果满足条件
				int m =s[i+1]-s[i-1]-1; //只需在-的位置输出m次中间的字母
				for(int k=1;k<=m;k++){
					printf("%c",s[i-1]+k);
				}
			}
			else{//如果不满足条件原样输出
				printf("%c",s[i]);
			}
		}
	}
}


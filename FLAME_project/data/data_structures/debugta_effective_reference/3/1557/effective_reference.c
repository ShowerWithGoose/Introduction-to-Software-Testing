#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int main() {
	char readnum[105];
	gets(readnum);
	int len=strlen(readnum),save_j,j,k;
	for(save_j=0;save_j<len;save_j++){
		if(readnum[save_j]=='.') break;
	}
	if(save_j==len){
		for(j=0;j<len;j++) printf("%c",readnum[j]);
		printf("e0");
	}
	else if(save_j>=2&&save_j!=len){
		for(k=len-1;k>0;k--){
			if(readnum[k]!='0') break;
		}
		printf("%c.",readnum[0]);
		for(j=1;j<save_j;j++) printf("%c",readnum[j]);
		for(j=save_j+1;j<=k;j++) printf("%c",readnum[j]);
		printf("e%d",save_j-1);
	}
	else{
		if(readnum[0]!='0'){
			for(k=len-1;k>0;k--){
				if(readnum[k]!='0') break;
			}
			for(j=0;j<=k;j++) printf("%c",readnum[j]);
			printf("e0");
		}
		else{
			for(j=2;j<len;j++){
				if(readnum[j]!='0') break;
			}
			for(k=len-1;k>0;k--){
				if(readnum[k]!='0') break;
			}
			int p=j;
			if(j==k){
				printf("%ce-%d",readnum[j],p-save_j);
			}
			else{
				printf("%c.",readnum[j]);
				for(j=p+1;j<=k;j++) printf("%c",readnum[j]);
				printf("e-%d",p-save_j);
			}
		}
	}
	return 0;
}



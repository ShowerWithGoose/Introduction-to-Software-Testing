#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int main() {
	char s[105];
	gets(s);
	int len=strlen(s),i,j,k;
	for(i=0;i<len;i++){
		if(s[i]=='.') break;
	}
	if(i==len){
		for(j=0;j<len;j++) printf("%c",s[j]);
		printf("e0");
	}
	else if(i>=2&&i!=len){
		for(k=len-1;k>0;k--){
			if(s[k]!='0') break;
		}
		printf("%c.",s[0]);
		for(j=1;j<i;j++) printf("%c",s[j]);
		for(j=i+1;j<=k;j++) printf("%c",s[j]);
		printf("e%d",i-1);
	}
	else{
		if(s[0]!='0'){
			for(k=len-1;k>0;k--){
				if(s[k]!='0') break;
			}
			for(j=0;j<=k;j++) printf("%c",s[j]);
			printf("e0");
		}
		else{
			for(j=2;j<len;j++){
				if(s[j]!='0') break;
			}
			for(k=len-1;k>0;k--){
				if(s[k]!='0') break;
			}
			int p=j;
			if(j==k){
				printf("%ce-%d",s[j],p-i);
			}
			else{
				printf("%c.",s[j]);
				for(j=p+1;j<=k;j++) printf("%c",s[j]);
				printf("e-%d",p-i);
			}
		}
	}
	return 0;
}



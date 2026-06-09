//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define eps 1e-6

int main(){
	char s[105];
	gets(s);
	int l=strlen(s);
	if(s[0]=='0'){
		int i,j,sign=-1;
		for(i=2;i<l;i++) if(s[i]!='0') break;
		if(i!=l-1) {
			printf("%c.",s[i]);
			for(j=1;s[i+j]!='\0';j++) printf("%c",s[i+j]);
			printf("e-%d",i-1);
		}else{
			printf("%ce-%d",s[i],i-1);
		}
	}else{
		int i,j,l=strlen(s);
		for(i=1;i<l;i++) if(s[i]=='.') break;
		printf("%c.",s[0]);
		for(j=1;j<i;j++) printf("%c",s[j]);
		for(j=i+1;j<l;j++) printf("%c",s[j]);
		printf("e%d",i-1);
	}
	

	return 0;
}




#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define M 100000
void yes0(char *s,int ls,int dot){
	int i,after_e=0;
	for(i=dot+1;s[i]=='0';i++){
		after_e--;
	}
	int j;
	for(j=i;j<ls;j++){
		if(j==i+1)  printf(".");
		printf("%c",s[j]);
	}
	printf("e%d",after_e-1);
}
void no0(char *s,int ls,int dot){
	int after_e=dot-1;
	int j;
	printf("%c.",s[0]);
	for(j=1;j<ls;j++){
		if(s[j]=='.')  continue;
		printf("%c",s[j]);
	}
	printf("e%d",after_e);
}
int main(){
	char s[M];
	gets(s);
	int ls;
	ls=strlen(s);
	int i;
	int dot,after_e,should0=0;
	for(i=0;i<ls;i++){
		
		if('.'==s[i]){
			dot=i;
			break;
		}
		if(s[i]!='0')  should0=1;
	}
	if(should0==1)  no0(s,ls,dot);
	else if(should0==0)yes0(s,ls,dot);
	
	
	return 0;
}


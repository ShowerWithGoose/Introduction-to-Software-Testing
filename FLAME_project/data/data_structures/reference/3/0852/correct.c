#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX(a,b) ((a)?(b)? (a): (b))
#define MIN(a,b) ((a)?(b)? (a): (b))
#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long

int main(){
	char s[6666],S[6666]={'\0'};
	gets(s);
	int i,j,l=strlen(s);
	int firstcount=0;
	for(i=0,j=0;i<l;i++){
		if(s[i]!='.'){
			S[j++]=s[i];
		}
	}
	for(i=0;i<l;i++){
		if(s[i]!='.'){
			firstcount++;
		}
		else {
			break;
		}
	}
	if(firstcount>0&&S[0]!='0'){
		for(i=0;i<l-1;i++){
			if(i==1){
				printf(".%c",S[i]);
				continue;
			}
			else printf("%c",S[i]);
		}
		printf("e%d",firstcount-1);
	}
	else if(S[0]=='0'){
		int k=1;
		for(i=1;i<l-1;i++){
			if(S[i]=='0'){
				k++;
			}
			else if(S[i]!='0'){
				printf("%c",S[i]);
				break;
			}
		}
		if(i!=l-2){
			printf(".");
		}
		for(i=i+1;i<l-1;i++){
			printf("%c",S[i]);
		}
		printf("e-%d",k);
	}
}


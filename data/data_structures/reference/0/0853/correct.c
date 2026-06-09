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
#include <stdio.h>
int main(){
	char s[100];
	gets(s);
	int i,t,j;
	t=strlen(s);
	printf("%c",s[0]);
	for(i=1;i<t;i++){
		if(s[i]=='-'){
			if(s[i-1]>='a'&&s[i+1]>'a'&&s[i+1]<='z') {
				for(j=1;j<s[i+1]-s[i-1];j++){
					printf("%c",s[i-1]+j*('b'-'a'));
				}
			}
			else if(s[i-1]>='0'&&s[i+1]>'0'&&s[i+1]<='9'){
				for(j=1;j<s[i+1]-s[i-1];j++){
					printf("%c",s[i-1]+j*('b'-'a'));}
			}
			
			else if(s[i-1]<'Z'&&s[i-1]>='A'&&s[i+1]>'A'&&s[i+1]<='Z'){
					for(j=1;j<s[i+1]-s[i-1];j++){
					printf("%c",s[i-1]+j*('b'-'a'));}
			}
			else printf("%c",s[i]);
		}
			else {
				printf("%c",s[i]);
			} 
		}
	}


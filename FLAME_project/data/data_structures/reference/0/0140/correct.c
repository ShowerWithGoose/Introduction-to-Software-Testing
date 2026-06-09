#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define ll long long
#define N 100005 
char stk[N],s[N];
int top=0; 
int main(){
	scanf("%s",s);
	int i=0,j=0;
	for(i=0;i<strlen(s);i++){
		if(s[i]!='-')stk[top++]=s[i];
		else{
			if(islower(stk[top-1])&&islower(s[i+1])&&s[i+1]-stk[top-1]>=1){
				char x=stk[--top];
				for(j=x;j<=s[i+1];j++){
					stk[top++]=j;
				}
				i++;
			}
			else if(isupper(stk[top-1])&&isupper(s[i+1])&&s[i+1]-stk[top-1]>=1){
				char x=stk[--top];
				for(j=x;j<=s[i+1];j++){
					stk[top++]=j;
				}
				i++; 
			}
			else if(isdigit(stk[top-1])&&isdigit(s[i+1])&&s[i+1]-stk[top-1]>=1){
				char x=stk[--top];
				for(j=x;j<=s[i+1];j++){
					stk[top++]=j;
				}
				i++; 
			}
			else stk[top++]=s[i];
		}
		//printf("%s\n",stk);
	}
	printf("%s",stk);
	return 0;
} 




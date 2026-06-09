#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define ll long long
#define N 100005 
char s[N];
int main(){
	gets(s);
	int i=0,j=0,x=0,cnt=0,flag=0;
	for(i=0;i<strlen(s);i++){
		if(s[i]=='.'){
			x=i;break;
		}
	}

	if(x==0)x=strlen(s);
	if(x==1){
		if(s[0]=='0'){
			for(i=x+1;i<strlen(s);i++){
				if(s[i]=='0'){
					char t=s[i];
					s[i]='.';
					s[i-1]=t;
				}
				else break;
			}
			printf("%c",s[i]);
			if(i!=strlen(s)-1)printf(".");
			for(j=i+1;j<strlen(s);j++)printf("%c",s[j]);
			printf("e%d",x-i);
		}
		else if(s[0]!='0'){
			printf("%se0\n",s);return 0;
		} 
	}
	else {
		 int delta=x-1;
		 int t=strlen(s)-1;
		 while(s[t]=='0'||s[t]=='.')t--;
		 printf("%c",s[0]);
		 if(t!=1)printf(".");
		 for(i=1;i<=t;i++)if(s[i]!='.')printf("%c",s[i]);
		 printf("e%d",delta);
	}
	return 0;
} 


#include<stdio.h>
#include<math.h>
#include<string.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)

int main(){
	int i,j;
	char s[1000];
	scanf("%s",s);
	if(s[0]=='0'){
		for(i=0;s[i]=='0'||s[i]=='.';i++);
		if(!s[i+1]){
			printf("%ce-%d",s[i],i-1);
		}
		else{
			j=i;
			printf("%c.",s[i++]);
			while(s[i])printf("%c",s[i++]);
			printf("e-%d",j-1);
		}
	}
	else {
		j=0;
		for(i=1;s[i];i++)if(s[i]!='.'&&s[i]!='0')j=1;
		for(i=0;s[i]!='.';i++);
		printf("%c",s[0]);
		if(j)printf(".");
		for(j=1;s[j];j++)if(s[j]!='.')printf("%c",s[j]);
		printf("e%d",i-1);
	}
	return 0;
} 


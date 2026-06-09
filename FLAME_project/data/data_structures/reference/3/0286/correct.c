#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define M 100
int main(){
	char s[M],res[M];
	int len,i=-1,j,before=0,k=-1,flag=0;
	scanf("%s",s);
	len=strlen(s);
	if(s[1]=='.'){
		if(s[0]=='0'){
			before=1;
			for(j=2;j<len;j++){
				if(flag==0){
					if(s[j]=='0') before++;
					else if(s[j]!='0') {
						printf("%c",s[j]);
						if(j<len-1) printf(".");
						flag=1;
					}
				} 
				else printf("%c",s[j]);
			}
			printf("e-%d",before);
		}
		else{
			printf("%se0",s);
			return 0;
		}
	}
	else{
		while(s[++i]!='.');
		before=i-1;
		i=1;
		printf("%c.",s[0]); 
		while(i<len){
			if(s[i]!='.') printf("%c",s[i]);
			i++;
		}
		printf("e%d",before);
	}
	
} 


#include<stdio.h>
#include<string.h>
int main(){
	char s[105];
	int i=0,j=0,k=0,l=0,cnt=0,m=0;
	gets(s);
	l=strlen(s);
	if(l==1&&s[i]=='0'){
		printf("0");
		return 0;	
	}
    else{
    if(s[0]=='0')
	k=1;
	else 
	k=0;
	if(k==1){
		for(i=0;i<l;i++){
			if(s[i]=='0')
			cnt--;
			if(s[i]!='.'&&s[i]!='0')
			break;
		}
		for(i=0;i<l;i++){
			if(s[i]=='0')
			j++;
			if(s[i]!='0'&&s[i]!='.')
			break;
		}
		for(i=j+1;i<l;i++){
			printf("%c",s[i]);
			if(i==j+1&&s[i+1]!='\0')
			printf(".");
		}
	}
	else{
	for(i=0;i<l;i++){
		if(s[i]=='.')
		j=1;
	}
	if(j!=1){
	for(i=l-1;i>=0;i--){
	if(s[i]=='0')
		m++;
	else
		break;
		}
	for(i=0;i<l-m;i++){
		printf("%c",s[i]);
		if(i==0&&s[i+2]!='\0')
		printf(".");
	}
	cnt=l-1;
	}
	else{
		for(i=0;i<l;i++){
		if(s[i]!='.'){
			cnt++;
		}
		if(s[i]=='.'||s[i]=='\0')
		break;
		}
		for(i=0;i<l;i++){
		if(s[i]!='.'){
		printf("%c",s[i]);	
		}
		if(i==0)
		printf(".");
	}
	cnt--;
	}
		
		}
	printf("e%d",cnt);	
	}
	return 0;
} 



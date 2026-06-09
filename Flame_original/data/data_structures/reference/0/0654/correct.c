#include<stdio.h>
#include<string.h>
int i,j,k,t,n;
int main(){
	char str[1000100];
	gets(str);
	for(i=0;i<strlen(str);i++){
		if(str[i]!='-'){
		printf("%c",str[i]);
}       
		else if(str[i+1]>='0'&&str[i+1]<='9'&&str[i-1]>='0'&&str[i-1]<='9'&&str[i-1]<str[i+1]) {
			k=str[i+1]-str[i-1];
			for(j=1;j<k;j++)
			printf("%c",j+str[i-1]);//注意是否需要减'0' 
		}
		else if(str[i+1]>='a'&&str[i+1]<='z'&&str[i-1]>='a'&&str[i-1]<='z'&&str[i-1]<str[i+1]) {
			k=str[i+1]-str[i-1];
			for(j=1;j<k;j++)
			printf("%c",j+str[i-1]);//注意是否需要减'0' 
		}
		else if(str[i+1]>='A'&&str[i+1]<='Z'&&str[i-1]>='A'&&str[i-1]<='Z'&&str[i-1]<str[i+1]) {
			k=str[i+1]-str[i-1];
			for(j=1;j<k;j++)
			printf("%c",j+str[i-1]);//注意是否需要减'0' 
		}
		else printf("-");
	}
}




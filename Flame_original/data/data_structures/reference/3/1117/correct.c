#include<stdio.h>
int main(){
	char s[100];
	gets(s);
	int i;
	if(s[0]=='0'){
		for(i=0;s[i]!='\0';i++){
			if(s[i]>'0'&&s[i]<='9') break;
		}
		if(s[i+1]!='\0') printf("%c.",s[i]);
		else printf("%c",s[i]);
		int j; 
	    for(j=i+1;s[j]!='\0';j++){
	    	printf("%c",s[j]);
		}
		printf("e-%d",i-1);
	}
	else{
		int k;
		printf("%c.",s[0]);
		for(i=1;s[i]!='\0';i++){
			if(s[i]!='.') printf("%c",s[i]);
			if(s[i]=='.') k=i;
		}
		printf("e%d",k-1);
	}
	return 0;
}


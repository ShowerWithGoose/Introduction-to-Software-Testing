#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char s[105];int i,j;
	gets(s);
	if(s[0]=='0') {
	    for(i=2;i<=100;i++){
		    if(s[i]=='0') ;
		    else break;
	    }
	    printf("%c",s[i]);
	    if(i+1<strlen(s)) printf(".");
	    for(j=i+1;j<=strlen(s)-1;j++){
	    	printf("%c",s[j]);
		}
		printf("e");
		printf("-");
		printf("%d",i-1);
	}
	else {
		for(i=1;i<=100;i++){
			if(s[i]!='.') ;
			else break;
		}
		printf("%c",s[0]);
		printf(".");
		for(j=1;j<i;j++) printf("%c",s[j]);
		for(j=i+1;j<=strlen(s)-1;j++) printf("%c",s[j]);
		printf("e");
		printf("%d",i-1);
	}
	return 0;
}



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char s[105];

	int len=strlen(s),i;
	int k=1;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='.') {
			break;
		}
	}
	if(i>1){
		printf("%c.",s[0]);
		for(k=1;k<i;k++){
			printf("%c",s[k]);
		}
		for(k=i+1;s[k]!='\0';k++){
			printf("%c",s[k]);
		}
		printf("e%d",i-1);
	}
	else if(s[0]=='0'){
		int j=2;
		while(s[j]=='0'){
			j++;
		} 
		printf("%c",s[j]);
		if(s[j+1]!='\0') printf(".");
		for( k=j+1;s[k]!='\0';k++){
			printf("%c",s[k]);
		}
		printf("e-%d",j-1);
	}
	else printf("%se0",s);
	return 0; 
}



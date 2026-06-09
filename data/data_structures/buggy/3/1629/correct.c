#include <stdio.h>
#include <string.h>
int main(){
	char str[105];
	gets(str);
	int n=strlen(str);
	int j=0,k=0;
	for(int i=0;i<n;i++){
	if(str[i]=='.'){
		j=i;
	}
	}
	if(j==1){
	   if(str[0]=='0'){
	    while(str[2+k]=='0'){
			k++;
		}
	printf("%c",str[2+k]);
	if(k!=0){printf(".");}
	for(int i=3+k;i<n;i++){
		printf("%c",str[i]);
	}printf("e-%d",k+1);
	   }
	else printf("%se0",str);   		
	}
	else {
		printf("%c",str[0]);
		printf(".");
		for(int i=1;i<n;i++){
			if(str[i]!='.')
	      printf("%c",str[i]);
	}printf("e%d",j-1);
		
	}
	
	return 0;
}


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char str[105];
int main()
{
	gets(str);
	int len=strlen(str),k=0;
	for(int i=0;i<len;i++){
		if(str[i]=='.'){
			k=i;
			break;
		}
	}	
	int j=0;
	if(k==1){
		if(str[0]!='0'){
			for(int i=0;i<len;i++) printf("%c",str[i]);
			printf("e0");
		}
		
		
		else {
			for(int i=2;i<len;i++){
				if(str[i]>'0'){
					j=i;
					break;
				}
			}
			if(j==(len-1)){
			printf("%c",str[j]);
			for(int i=j+1;i<len;i++){
				printf("%c",str[i]);
			}
			printf("e-%d",j-1);
			}
			else{
				printf("%c.",str[j]);
			for(int i=j+1;i<len;i++){
				printf("%c",str[i]);
			}
			printf("e-%d",j-1);
			}
		}
	}
	else {
		printf("%c.",str[0]);
		for(int i=1;i<len;i++){
			if(str[i]!='.') printf("%c",str[i]);
		}
		printf("e%d",k-1);
	}

	return 0;	
}




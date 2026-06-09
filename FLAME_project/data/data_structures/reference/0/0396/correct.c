#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXSIZE 10000

int main(){
	char *c;
	c=(char*)malloc(MAXSIZE*sizeof(char));
	scanf("%s",c);
	int i,j,len=strlen(c);
	for(i=0;i<len;i++){
		if(c[i]!='-')
			printf("%c",c[i]);
		else{
			if(c[i-1]>=65&&c[i+1]<=90&&c[i-1]<c[i+1])
				for(j=c[i-1]+1;j<c[i+1];j++){
					printf("%c",j);
				}
			else if(c[i-1]>=97&&c[i+1]<=122&&c[i-1]<c[i+1])
				for(j=c[i-1]+1;j<c[i+1];j++){
					printf("%c",j);
				}
			else if(c[i-1]>='0'&&c[i+1]<='9'&&c[i-1]<c[i+1])
				for(j=c[i-1]+1;j<c[i+1];j++){
					printf("%c",j);
				}
			else
				printf("%c",c[i]);
		}
	}
	free(c);
	return 0;
} 




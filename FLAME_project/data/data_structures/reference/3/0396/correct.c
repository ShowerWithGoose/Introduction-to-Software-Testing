#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 10000

int main(){
	char *c;
	c=(char *)malloc(MAXSIZE*sizeof(char));
	scanf("%s",c);
	int i,j,len=strlen(c);
	if(c[0]!='0'&&c[1]=='.'){
		printf("%se0",c);
	}
	else if(c[0]=='0'){
		for(i=2;i<len;i++){
			if(c[i]!='0')
				break;
		}
		if(i+1==len)
			printf("%ce-%d",c[i],i-1);
		else{
			printf("%c.",c[i]);
			j=i+1;
			for(;j<len;j++)
				printf("%c",c[j]);
			printf("e-%d",i-1);
		}
	}
	else{
		for(i=0;i<len;i++){
			if(c[i]=='.')
				break;
		}
		printf("%c.",c[0]);
		for(j=1;j<len;j++){
			if(j!=i)
				printf("%c",c[j]);
		}
		printf("e%d",i-1);
	}
	free(c);
	return 0;
}


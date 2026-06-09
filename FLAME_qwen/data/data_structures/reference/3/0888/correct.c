#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
int main(){
	char c[105];
	int up=0,down=0,state=0,count=0,i;
	gets(c);
	for(i=0;i<strlen(c);i++){
		if(c[i]!='.')
			if(state==0)
				up++;
			else
				down++;
		else
			state=1;
	}
	if(up>1){
		printf("%c.",c[0]);
		for(i=1;i<strlen(c);i++){
			if(c[i]!='.')
				printf("%c",c[i]);
		}
		printf("e%d",up-1);
	}
	else{
		if(c[0]!='0')
			printf("%se0",c);
		else{
			i=1;
			while(c[1+i]=='0'){
				i++;
			}
			if(down!=i)
				printf("%c.%se-%d",c[1+i],c+2+i,i);
			else
				printf("%ce-%d",c[1+i],i);
		}
	}
	return 0;
}





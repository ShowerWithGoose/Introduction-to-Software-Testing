#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char s[1000],*dot,*zero;
	int eNum=0,zlong=0;
	
	scanf("%s",s);
	dot=strchr(s,'.');
	if(dot==NULL){
		zero=s+strlen(s)-1;
		while(*zero=='0'){
			zero--;
			eNum++;
		}
		zlong=strlen(zero);
		if(zero-s==0){
			printf("%ce%d",*s,zlong-1);
		}
		else{
			*(zero+1)='\0';
			printf("%c.%se%d",*s,s+1,zlong-1);
		}		
	}
	else if(*(dot-1)=='0'&&dot-s==1){  //0.xxx
		zero=dot+1;
		while(*zero=='0'){
			zero++;
			eNum--;
		}
		
		printf("%c",*zero);
		if(*(zero+1)!='\0') printf(".");
		printf("%se%d",zero+1,eNum-1);
	}
	else if(dot-s==1){
		printf("%se0",s);
	}
	else{
		eNum=dot-s-1;
		*dot='\0';
		printf("%c.%s%se%d",*s,s+1,dot+1,eNum);
	}
	
	return 0;
}


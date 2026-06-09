#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
char s[110];
int main()
{
	int i;
	gets(s);
	int lens=strlen(s);
	int a=strchr(s,'.')-s;
	for(i=0;i<lens;i++){
		if(s[i]!='0'&&s[i]!='.') break;
	}
	if(i==lens-1) printf("%c",s[lens-1]);
	else{
		int flag=0;
	    for(;i<lens;i++){
	    	if(isdigit(s[i]))printf("%c",s[i]);
	    	if(!flag){
	    		flag=1;
	    		printf(".");
			}
		}
	} 
	for(i=0;i<lens;i++){
		if(s[i]!='0'&&s[i]!='.') break;
	}
	printf("e");
	if(a==1&&s[0]=='0'){
		printf("-%d",i-1);
	}
	else{
		printf("%d",a-1);
	}



    return 0;
}



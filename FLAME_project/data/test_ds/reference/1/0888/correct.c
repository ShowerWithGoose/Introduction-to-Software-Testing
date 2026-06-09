#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
int main(){
	int i;
	char j;
	char c[1000];
	scanf("%s",c);
	for(i=0;c[i+2]!=0;i++){
		if(c[i+1]=='-'){
			if(((islower(c[i])&&islower(c[i+2]))||(isupper(c[i])&&isupper(c[i+2]))||(isdigit(c[i])&&isdigit(c[i+2])))&&c[i]<c[i+2]){
				for(j=c[i];j<c[i+2];j++){
					printf("%c",j);
				}
				i++;
			}
			else
				printf("%c",c[i]);
		}
		else{
			printf("%c",c[i]);
		}
	}
	printf("%c",c[i]);
	printf("%c",c[i+1]);
	return 0;
}





#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
char bef[1000],aft[1000];


void expand(char bef[]){
	int i,j,k;
	int len = strlen(bef);
	for(i=0,k=0;i<len;i++,k++){
		//printf("%c",bef[i]);
		aft[k]=bef[i];
		if(bef[i]=='-'){
			if(((bef[i-1]-'a'>=0)&&bef[i-1]-'z'<=0&&(bef[i+1]-'a'>=0)&&(bef[i+1]-'z'<=0))||((bef[i-1]-'0'>=0)&&bef[i-1]-'9'<=0&&(bef[i+1]-'0'>=0)&&(bef[i+1]-'9'<=0))||((bef[i-1]-'A'>=0)&&bef[i-1]-'Z'<=0&&(bef[i+1]-'A'>=0)&&(bef[i+1]-'Z'<=0))){
				for(j=1;bef[i-1]+j<bef[i+1];j++,k++){
					aft[k]=bef[i-1]+j;
				}
				k--;
			}
		}
	}
}


int main()
{
	scanf("%s",bef);
	expand(bef);
	puts(aft);
	
 	return 0;
 }




#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>
int main(){
	char a[1000];
	gets(a);
	char *b=NULL;
	char *c=NULL;
	int i;
	int k_1,k_2;
	b=strchr(a,'-');
	if(b==NULL){
	puts(a);}
	else{
		for(b=a;(c=strchr(b,'-'))!=NULL&&(c+1)!=NULL ; ){
			if((*(c-1)>='0'&& *(c-1)<='9' && *(c+1)-*(c-1)>0 &&*(c+1)<='9') || (*(c-1)>='a'&& *(c-1)<='z' && *(c+1)-*(c-1)>0 &&*(c+1)<='z')||(*(c-1)>='A'&& *(c-1)<='Z' && *(c+1)-*(c-1)>0 &&*(c+1)<='Z')){
				for(k_1=0;k_1<c-b;k_1++){
				
				printf("%c",*(b+k_1));}
				for(k_1=1;k_1<=*(c+1)-*(c-1);k_1++){
				
				printf("%c",k_1+*(c-1));}
			}
			else
			{
				for(k_1=0;k_1<c-b+2;k_1++){
					printf("%c",*(b+k_1));}
				
			}
			b=c+2;	
			}
		k_2=strlen(a)-(b-a);
		for(k_1=0;k_1<k_2;k_1++){
			printf("%c",*(b+k_1));}
	}	

	return 0;		
	}





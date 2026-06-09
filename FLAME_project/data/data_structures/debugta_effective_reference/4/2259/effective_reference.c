#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define LL long long
#define ULL unsigned long long 

struct mix{
	char ch[50];
	int num;
};
char ch0[100];
char words[50];
int cmp(const void* a,const void* b){
	struct mix* a0=(struct mix*)a;
	struct mix* b0=(struct mix*)b;
	if(strcmp(a0->ch,b0->ch)>0){
		return 1;
	}
	else {
		return -1;
	}
}
int main() {
	FILE* in;
	in=fopen("article.txt","r");
     int i,i0,nummix=0,num;
     struct mix a[500];
     while(fgets(ch0,99,in)!=NULL){
     	for(i=0;i<=strlen(ch0)-1;i++){
     		if(isupper(ch0[i])){
     			ch0[i]=ch0[i]+'a'-'A';
			 }
		 }
     	for(i=0;i<=strlen(ch0)-1;i++){
     		if(isalpha(ch0[i])){
     			i0=0;
     			while(isalpha(ch0[i])){
     				words[i0++]=ch0[i++];
				 }
				 words[i0]='\0';
				 strcpy(a[nummix].ch,words);
				 a[nummix].num=1;
				 nummix++;
				 
			 }
		 }
	 }
	 qsort(a,nummix,sizeof(a[0]),cmp);
	 for(i=0;i<=nummix-2;i++){
	 	num=1;
	 	printf("%s ",a[i].ch);
	 	if(strcmp(a[i].ch,a[i+1].ch)==0){
	 		while(strcmp(a[i].ch,a[i+1].ch)==0){
	 			i++;
	 			num++;
			 }
			
		 }
		 printf("%d\n",num);
	 }
	 if(strcmp(a[nummix-2].ch,a[nummix-1].ch)!=0){
	 	printf("%s 1",a[i].ch);
	 }
	return 0;
}





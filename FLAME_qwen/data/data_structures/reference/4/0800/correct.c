#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct danci{
	char zifu[50];
	int cishu;
}s[10000];

int cmp(const void *a,const void *b){
	struct danci *p;
	struct danci *q;
	p=((struct danci *)a);
	q=((struct danci *)b);
 return strcmp((p->zifu),(q->zifu));
	
} 
int iszimu(char c){
	int a=c-'a';
	int A=c-'A';
	if(a<=26&&a>=0) return 1;
	else if(A<=26&&A>=0) return 1;
	else return 0 ;
}

char ci[50];
int main(){
	int i=0;
	int j=0;
FILE *in;
in=fopen("article.txt","r")	;
	char c;
	char qian;
	while((c=fgetc(in))!=EOF){
	int is= iszimu(c);
	if(is==1){
		if(c<='Z'&&c>='A') c=c-'A'+'a';
		else if(c<='z'&&c>='a')  c=c;
		ci[i++]=c;
	}
	else if((iszimu(qian)==1)&&(iszimu(c)==0)) {
	        ci[i]='\0';
	        i=0;
			strcpy(s[j++].zifu,ci);
		int k=0;
		for(k=0;k<strlen(ci);k++) ci[k]='\0';		
       }
	 qian=c;
	}
	
qsort(s,j,sizeof(s[0]),cmp);
int f=0;
for(i=0;i<j;i++){
 if(strcmp(s[i].zifu,s[i+1].zifu)==0)  (s[i+1].cishu)=(s[i].cishu)+1;
 else printf("%s %d\n",s[i].zifu,s[i].cishu+1); 
	
}	
	return 0 ;
} 


#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define M 200
struct cipintongji{
	char word[200];
	int n;
};
typedef struct cipintongji ci;
ci w[1000];
int comp(const void*a,const void*b){
	struct cipintongji *c=(struct cipintongji*)a;
	struct cipintongji *d=(struct cipintongji*)b;
	return strcmp(c->word ,d->word );
}
int i,j,k,f=0;
char s[M],r[M];
char ch;
int main(){
	FILE *in=fopen("article.txt","r");
	i=0;
	while((ch=fgetc(in))!=EOF){
		s[i++]=ch;
	}
	s[i]='\0';
	int ls=strlen(s);
	for(i=0;i<ls;i++){
	if(isalpha(s[i])){
		s[i]=tolower(s[i]);
	}
  }
    for(i=0;i<ls;i++){
    if(isalpha(s[i])){
    	for(j=i;j<ls;j++){
    		if(!isalpha(s[j]))
    		break;
		}
	for(k=0;k<j-i;k++){
		w[f].word[k]=s[i+k];
	}
	
	f++;
	i=j;	    		
	}
	else
	continue;
}
    qsort(w,f,sizeof(w[0]),comp);
    for(i=0;i<f;i++){
    	w[i].n =1;
	}
	for(i=0;i<f;i++){
		if(strcmp(w[i].word ,w[i+1].word )==0){
			w[i+1].n +=w[i].n ;
			w[i].n =0;
		}
	}
	qsort(w,f,sizeof(w[0]),comp);
	for(i=0;i<f;i++){
		if(w[i].n ==0){
			continue;
		}
		else
		{
			printf("%s %d\n",w[i].word ,w[i].n );
		}
	}
	return 0;
}
	
	
	
	
	


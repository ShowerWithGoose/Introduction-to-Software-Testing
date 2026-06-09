#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct word{
	int time;
	char words[10];
};
	struct word ff[100];
int cmp(const void *a,const void *b){
	struct word *c=(struct word *)a;
	struct word *d=(struct word *)b;
	return strcmp(c->words,d->words);
}
char s[100];
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	int j=0,i=0,k=0;
	while(fgets(s,100,in)!=NULL){
		i=0;
	     while(s[i]!='\0'){
	     	if(s[i]<='Z'&&s[i]>='A'){
	     		s[i]=s[i]-'A'+'a';
			 }
			 if(s[i]>='a'&&s[i]<='z'){
			 	ff[j].words[k]=s[i];
			 	k++;
			 }
			 else{
			 	ff[j].words[k]='\0';
			 	ff[j].time=1;
			 	j++;
			 	k=0;
			 	
			 }
			 i++;
		 }
	
		
	}
	
	int sum=j;
	qsort(ff,sum,sizeof(struct word),cmp);
	for(j=0;j<sum;j++){
		if(ff[j].time!=0&&strcmp(ff[j].words,ff[j+1].words)==0){
			ff[j+1].time+=ff[j].time;
			ff[j].time=0;
		}
		
	}
	for(j=0;j<sum;j++){
		if(ff[j].time!=0&&ff[j].words[0]!='\0'){
		printf("%s %d\n",ff[j].words,ff[j].time);
		}
		
	}
    return 0;
	
} 


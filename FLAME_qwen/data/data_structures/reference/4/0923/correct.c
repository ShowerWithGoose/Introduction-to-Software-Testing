#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct book{
	char s[1005];
	int n;
}p[1005];

int com(const void*a,const void*b){
	struct book* c=(struct book*)a;
	struct book* d=(struct book*)b;
	return strcmp(c->s,d->s);
}

int main(){
	FILE* fp=fopen("article.txt","r");
	char word[1005];
	char c;
	int i=0,j=0,k=0;
	while((c=fgetc(fp))!=EOF){
		word[i]=c;
		i++;
	}
	i=0;
	for(i=0;i<strlen(word);i++){
		if(!isalpha(word[i])){
			j++;
			k=0;
		}else if(isalpha(word[i])){
			p[j].s[k++]=tolower(word[i]);
		}
	}
	qsort(p,j,sizeof(p[0]),com);
	for(i=0;i<j;i++){
		if(strlen(p[i].s)) p[i].n=1;
	}
	i=0;
	for(i=0;i<j;i++){
		if(!strcmp(p[i].s,p[i+1].s)){
			p[i+1].n+=p[i].n;
			p[i].n=0;
		}
	}
	for(i=0;i<j;i++){
		if(p[i].n!=0){
			printf("%s %d\n",p[i].s,p[i].n);
		}
	}
	return 0;
}

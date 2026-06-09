#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXLETTER 50
#define MAXSUM 500
struct data{
	char word[MAXLETTER];
	int num;
}list[MAXSUM];

int cmp(const void*p,const void*q){
	struct data* a=(struct data *)p;
	struct data* b=(struct data *)q;
	if(strcmp(a->word,b->word)==0) return 0;
	else if(strcmp(a->word,b->word)>0) return 1;
	else return -1;
}

void Same_Count(int n){
	int i,j,k;
	int r;
	for(i=0;i<n;){
		for(j=1;i+j<n;j++){
			if(strcmp(list[i].word,list[i+j].word)==0){
				list[i].num++;
				list[i+j].num=-1;
			}
			else break;
		}
		i=i+j;
	}
}

int main(){
	int i,j,index=0;
	int n=0,y=0;
//	char str[MAXSUM][MAXLETTER];
	char c;
	freopen("article.txt","r",stdin);
	while((c=getchar())!=EOF){
		if(isalpha(c)){
			index=1;
			list[n].num=1;
			if(islower(c)) list[n].word[y++]=c;
			else list[n].word[y++]=tolower(c);
		}
		else if(index==1){
			n++;
			y=0;
			index=0;
		}
	}
/*	for(i=0;i<n;i++)
		printf("**%s\n",list[i].word);
/*		k=0;
		for(j=0;j<strlen(str[i]);j++){
			if(islower(str[i][j])){
				list[i].word[k++]=str[i][j];
			}
			else if(isupper(str[i][j])){
				list[i].word[k++]=tolower(str[i][j]);
			}*/
//		sscanf(str[i],"%*[\"]%[A-Za-z]",list[i].word);
		
		
//printf("&& %s\n",list[i].word);
	qsort(list,n,sizeof(struct data),cmp);
	Same_Count(n);
	for(i=0;i<n;i++){
		if(list[i].num!=-1){
			printf("%s %d",list[i].word,list[i].num);
			if(i!=n-1) putchar('\n');
		}
	}
}

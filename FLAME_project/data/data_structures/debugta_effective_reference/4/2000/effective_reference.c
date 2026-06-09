#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct lnode{
	char word[200];
	int count;
}w[10000];
int search(struct lnode w[],char s[][200],int n){
	int i;
	for(i=0;i<10000;i++)
		if(strcmp(w[i].word,s[n])==0) 
			return i;
	return -1;
}
int cmp(const void *a,const void *b){
	struct lnode *aa=(struct lnode *)a;
	struct lnode *bb=(struct lnode *)b;
	return strcmp(aa->word,bb->word);
}
char s[1000];
int i,j,k,cnt;
char all_word[1000][200],tmp[1000],ch;
void Getarticle(FILE *fp1){
	ch=fgetc(fp1);
	int i=0;
	while(ch!=EOF){
		s[i]=ch;
		i++;
		ch=fgetc(fp1);
	}
	for(i=0;i<strlen(s);i++){
		if(isalpha(s[i])) s[i]=tolower(s[i]);
	}
}
void Getword(FILE *fp1,char all_word[1000][200]){
	for(i=0;i<strlen(s);i++){
		if(isalpha(s[i])){
			for(j=i;j<strlen(s);j++){
				if(!isalpha(s[j])) break;
			}
			memset(tmp,0,sizeof(tmp));
			for(k=0;k<j-i;k++) tmp[k]=s[i+k];
			strcpy(all_word[cnt],tmp);
			cnt++;
			i=j;
		}
		else continue;
	}
}
int main(){
	FILE *fp1=fopen("article.txt","r");
	Getarticle(fp1);
	Getword(fp1,all_word);
	int k=0,cnt=0;
	while(k<cnt){
		if(search(w,all_word,k)==-1){
			strcpy(w[cnt].word,all_word[k]);
			w[cnt].count=1;
			cnt++;
		}
		else{
			w[search(w,all_word,k)].count++;
		}
		k++;
	}
	qsort(w,k,sizeof(w[0]),cmp);
	for(i=0;i<k;i++) 
		if(w[i].count!=0)
			printf("%s %d\n",w[i].word,w[i].count);
	return 0;
}



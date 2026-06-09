#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
#define N 10000
struct node{
	char word[N];
	int cnt;
}p[N];
int cmp(const void* a,const void *b)
{
	struct node*c=(struct node*)a;
	struct node*d=(struct node*)b;
	return strcmp(c->word,d->word);
}
int main(){
	char str[N];
	FILE *fp=fopen("article.txt","r");
	int i=0,k=0,num=0;
	char ch;
	ch=fgetc(fp);
	while(ch!=EOF){
		str[i++]=ch;
		ch=fgetc(fp);
	}
	for(i=0;i<strlen(str);i++){
		if(isalpha(str[i]))
			p[num].word[k++]=tolower(str[i]);
		else if(!isalpha(str[i])){
			num++;
			k=0;
		}
	}
	qsort(p,num,sizeof(p[0]),cmp);
	for(i=0;i<num;i++){
		if(strlen(p[i].word)!=0)
			p[i].cnt=1;
	}
	for(i=0;i<num;i++){
		if(strcmp(p[i].word,p[i+1].word)==0){
			p[i+1].cnt+=p[i].cnt;
			p[i].cnt=0;
		}
	}
	for(i=0;i<num;i++){
		if(p[i].cnt!=0)
			printf("%s %d\n",p[i].word,p[i].cnt);
	}
	return 0;
}


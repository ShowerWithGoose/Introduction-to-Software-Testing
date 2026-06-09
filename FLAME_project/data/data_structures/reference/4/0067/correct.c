#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define pf printf
#define sc scanf
#define N 10005
#define MAX 1024

struct list{
	char word[50];
	int count;
}tf[MAX];

int cmp(const void *a,const void *b){
	struct list *c = (struct list*)a;
	struct list *d = (struct list*)b;
	return strcmp(c->word,d->word);
}

int main()
{
	FILE *fi = NULL;
	fi = fopen("article.txt","r");
	
	char c,str[N];
	int cnt = 0; 
	while((c = fgetc(fi)) != EOF){
		str[cnt++] = c;
	}
	int cnt1 = 0,cnt2 = 0;
	for(int i = 0;i < cnt;i++){
		if(!isalpha(str[i])) cnt1++,cnt2 = 0;
		else tf[cnt1].word[cnt2++] = tolower(str[i]),tf[cnt1].count = 1;
	}
	qsort(tf,cnt1,sizeof(tf[0]),cmp);
	for(int i = 0;i < cnt1;i++){
		if(!strcmp(tf[i].word,tf[i + 1].word)){
			tf[i + 1].count += tf[i].count;
			tf[i].count = 0;
		}
	}
	for(int i = 0;i < cnt1;i++){
		if(tf[i].count != 0)	pf("%s %d\n",tf[i].word,tf[i].count);
	}
	return 0;
}



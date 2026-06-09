#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
	char s[2000];
	int num;
}p[3000];

typedef struct node *Nodeptr; 

int cmp(const void* a,const void* b){
	Nodeptr c=(Nodeptr)a;
	Nodeptr d=(Nodeptr)b;
	return strcmp(c->s,d->s);
}

int main(){
	char ch,c[10000];
	FILE *article;
	article=fopen("article.txt","r");
	int k=0,cnt=0,i;
	while((ch=fgetc(article))!=EOF){
		c[cnt]=ch;
		cnt++;
	}
	cnt=0;
	for(i=0;i<strlen(c);i++){
		if(!isalpha(c[i])){
			cnt++;
			k=0;
		}
		else if(isalpha(c[i]))
		p[cnt].s[k++]=tolower(c[i]);
	}
	
	qsort(p,cnt,sizeof(p[0]),cmp);
	
	for(i=0;i<cnt;i++){
		if(strlen(p[i].s))
		p[i].num=1;
	}
	for(i=0;i<cnt;i++){
		if(strcmp(p[i].s,p[i+1].s)==0){
			p[i+1].num+=p[i].num;
			p[i].num=0;
		}
	}
	for(i=0;i<cnt;i++){
		if(p[i].num!=0)
		printf("%s %d\n",p[i].s,p[i].num);
	}
	
	return 0;
	
}






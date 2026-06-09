#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct book{
	char word[10];
	int cnt;
	int flag;
}words[100];

int cmp(const void*a,const void *b)
{
	struct book*x=(struct book*)a;
	struct book*y=(struct book*)b;
	return(strcmp(x->word,y->word));
}
int main()
{
	for(int i=0;i<100;i++){
		words[i].cnt=1;
		words[i].flag=1;
	}
		
	FILE *fin=fopen("article.txt","r");
	char c;
	int i=0,j=0;
	while((c=fgetc(fin))!=EOF){
		c=tolower(c);
		if(isalpha(c)){
			words[i].word[j++]=c;
		}
		else if((j>0)&&(isalpha(words[i].word[j-1]))){
			words[i++].word[j]='\0';
			j=0;
		}
	}
	//总共有i个单词
	//排序输出
	qsort(words,i,sizeof(struct book),cmp);
	for(int n=0;n<i;n++){
		for(int j=1;(n+j)<i;j++){
			if(strcmp(words[n+j].word,words[n].word)==0){
				words[n].cnt++;
				words[n+j].flag=0;
			}
		}
	}
	for(int n=0;n<i;n++){
		if(words[n].flag){
			printf("%s %d\n",words[n].word,words[n].cnt);
		}
	}
}


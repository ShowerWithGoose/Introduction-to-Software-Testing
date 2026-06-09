#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 1024
/*且使用最简单的数组储存每一个单词*/
struct word_num{
	char *word;
	int num;
};

struct wordList{
	struct word_num vocab[1000];
	int totalnum;
}vocabList;

int isAlpha(char a)
{
	return (a>='a'&&a<='z')||(a>='A'&&a<='Z');
}

int toLow(char a)
{
	if(a>='A'&&a<='Z') return a+'a'-'A';
	return a;
}

void insert(char *w,int len){
	/*如果已经有过就改变数量，如果没有就加在最后*/
	/*如果原本有过就返回0，原本没有则返回1*/
	/*先处理非字母与大小写*/
	/*省去了strcpy，但是内存会泄露，大量数据时不可取*/
	/*只要有字母，就算单词*/
 	int i,j,k;
 	char tmp;
	for(i=j=0;i<len&&j<len;i=j){
		while(i<len&&!isAlpha(w[i])) i++,j++;
		while(j<len&&isAlpha(w[j])){
			w[j]=toLow(w[j]);
			j++;
		}
		if(i>=len) return;//这一个换行是空字符但有num的来源。到最后i>len，但只跳出了while没有跳出for，继续执行插入，最后的空num是行数 
		tmp=w[j];
		w[j]='\0';
		for(k=0;k<vocabList.totalnum;k++){
			if(strcmp(w+i,vocabList.vocab[k].word)==0){
				vocabList.vocab[k].num++;
				break;
			}
		}
		if(k==vocabList.totalnum){
			vocabList.totalnum++;
			vocabList.vocab[k].num++;
			vocabList.vocab[k].word=(char*)malloc(sizeof(char)*20);
			strcpy(vocabList.vocab[k].word,w+i);
		}
		w[j]=tmp;
	}	
}

int cmp(const void *_a,const void *_b)
{
	struct word_num* a=(struct word_num*)_a;
	struct word_num* b=(struct word_num*)_b;
	return strcmp(a->word,b->word);
}

int main()
{
	FILE* in=fopen("article.txt","r");
	char tmp_read[MAXSIZE]; 
	while(fgets(tmp_read,MAXSIZE,in)!=NULL){
		insert(tmp_read,strlen(tmp_read));
	}
	
	/*for(int i=0;i<vocabList.totalnum;i++){
		printf("%s %d\n",vocabList.vocab[i].word,vocabList.vocab[i].num);
	}
	printf("\n\n");*/
	
	qsort(vocabList.vocab,vocabList.totalnum,sizeof(struct word_num),cmp);
	for(int i=0;i<vocabList.totalnum;i++){
		printf("%s %d\n",vocabList.vocab[i].word,vocabList.vocab[i].num);
	}
	fclose(in);
	return 0;
} 


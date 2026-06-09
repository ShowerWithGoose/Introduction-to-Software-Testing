#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXWORD 1024
#define MAXSIZE 1024
struct danci {
	char word[MAXWORD];
	int count;
};
int getWord(FILE *bfp,char *w);
int searchWord(struct danci list[],char *w);
int insertWord(struct danci list[],int pos,char *w);
int N=0;//全局变量，空表
int main() {
	struct danci wordlist[MAXSIZE];//单词表
	int i;
	char filename[MAXWORD],word[MAXWORD];
	FILE *fp=fopen("article.txt","r");
	while(getWord(fp,word)!=EOF)
		if(searchWord(wordlist,word)==-1) {
			fprintf(stderr,"full\n");
			return -1;
		}
	for(i=0; i<N; i++)
		printf("%s %d\n",wordlist[i].word,wordlist[i].count);
	return 0;
}
//从文件中读入一个单词（仅由字母组成的串），并转换成小写字母
int getWord(FILE *fp,char *w) {
	int c;
	while(!isalpha(c=fgetc(fp)))//这个函数如果是字母的话就为真
		if(c==EOF)return c;
		else continue;
	do {
		*w++=tolower(c);
	} while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}
//在表中相应位置插入一个单词，同时置次数为1
int insertWord(struct danci list[],int pos,char *w) {
	int i;
	if(N==MAXSIZE)return -1;
	for(i=N-1; i>=pos; i--) { //也可以直接用结构整体复制
		strcpy(list[i+1].word,list[i].word);
		list[i+1].count=list[i].count;
	}
	strcpy(list[pos].word,w);
	list[pos].count=1;
	N++;
	return 1;
}
//在表中查找一单词，若找到，则次数+1；否则即将该单词插入到有序表中相应位置，同时次数置1
int searchWord(struct danci list[],char *w) {
	int low=0,high=N-1,mid=0;
	while(low<=high) {
		mid=(low+high)/2;
		if(strcmp(w,list[mid].word)<0)
			high=mid-1;
		else if(strcmp(w,list[mid].word)>0)
			low=mid+1;
		else {
			list[mid].count++;
			return 0;
		}
	}
	return insertWord(list,low,w);
}


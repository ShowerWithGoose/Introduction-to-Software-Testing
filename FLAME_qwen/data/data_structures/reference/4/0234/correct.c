#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORD 32

struct node {
	char word[MAXWORD];
	int count;
	struct node *link;
} ; //单词表结构

//单词表头指针，使用全局变量
struct node *Wordlist = NULL;
//int getWord(FILE *bfp,char *w);
int searchWord(char *w);
int insertWord(struct node *p, char *w);

/*int getWord(FILE *bfp,char *w) {
	char word[MAXWORD]="";
	fscanf(bfp,"%s",word);
	//单词头尾可能有字符
	for(int i=0; word[i]!='\0'; i++) {
		word[i]=tolower(word[i]);
		if(0==isalpha(word[i])) {
			int len=strlen(word);
			for(int j=i; j<len; j++) {
				word[j]=word[j+1];//word[len-1]=='\0'
			}
			word[len-1]='\0'; //len-1是结尾字符
		}
	}
	strcpy(w,word);
	return 0;
}
*/
int main() {
	char word[MAXWORD]="";
	FILE *bfp;
	struct node *p;

	if((bfp = fopen("article.txt", "r")) == NULL) {
		printf("file can't open!\n");
		return -1;
	}
//从文件中读入一个单词
	/*while( fscanf(bfp,"%s",word) != EOF) {
		//单词头尾可能有字符
		printf("%s\n",word);
		for(int i=0; word[i]!='\0'; i++) {
			word[i]=tolower(word[i]);
			if(0==isalpha(word[i])) {
				int len=strlen(word);
				for(int j=i; j<len; j++) {
					word[j]=word[j+1];//word[len-1]=='\0'
				}
				word[len-1]='\0'; //len-1是结尾字符
			}
		}
		printf("%s\n",word);
	}
	*/
	char c;
	int i;
	while((c=fgetc(bfp))!=EOF)
	{
		if(isalpha(c))
		{
			word[0]=tolower(c);
			i=1;
			while((isalpha(c=fgetc(bfp)))!=0)
			{
				c=tolower(c);
				word[i++]=c;
			}
			//printf("%s\n",word);
		}
	
	//在单词表中查找插入单词
		if(searchWord(word) == -1) {
			fprintf(stderr, "Memory is full!\n");
			return -1;
		}
		
		for(i=0;i<MAXWORD;i++)
		{
			word[i]='\0';
		}
	}
//遍历输出单词表
	//printf("wordlist %s %d\n", Wordlist->word, Wordlist->count);
	for(p=Wordlist->link; p != NULL; p=p->link)
		printf("%s %d\n", p->word, p->count);
	return 0;
}

/*在链表中p结点后插入包含给定单词的结点，同时置次数为1*/
int insertWord(struct node *p, char *w) {
	struct node *q;
	q = (struct node *)malloc(sizeof(struct node));
	if (q == NULL) return -1; //没有内存空间
	strcpy(q->word, w);
	q->count = 1;
	q->link = NULL;
	if (Wordlist == NULL) //空链表
		Wordlist = q;
	else if (p == NULL) { //插入到头结点前
		q->link = Wordlist;
		Wordlist = q;
	} else {
		q->link = p->link;
		p->link = q;
	}
	return 0;
}

/*在链表中查找一单词，若找到，则次数加1；否则将该
单词插入到有序表中相应位置，同时次数置1*/
int searchWord(char *w) {
//q为p的前序结点指针
	struct node *p, *q = NULL;
	for(p=Wordlist; p!=NULL; q=p, p=p->link) {
		if (strcmp(w, p->word) < 0)
			break;
		else if (strcmp(w, p->word) == 0) {
			p->count++;
			return 0;
		}
	}
	return insertWord(q, w);
}


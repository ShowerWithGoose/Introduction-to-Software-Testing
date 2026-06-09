#include <stdio.h>//所谓单词是字母构成的字符串,与两边字符无关
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD 50
typedef struct wordstatic{
	char word[MAXWORD];
	int times;
	struct wordstatic *link;
}wordstatic;
void onlylowercase(char word[])
{
	for (int i=0;i<(int)strlen(word);i++)
		word[i]=tolower(word[i]);
}
int main()
{
	char word[MAXWORD],c;
	wordstatic *list=NULL,*p,*q,*r;
	FILE *op;
	if((op=fopen("article.txt","r"))==NULL)
		printf("Can't open article.txt");
	while (~fscanf(op,"%c",&c)){
		int i=0;
		if (!isalpha(c))
			continue;
		while (isalpha(c)){
			word[i++]=c;
			fscanf(op,"%c",&c);
		}
		word[i]='\0';
		onlylowercase(word);//只保留字母并转为小写
//		if (word[0]=='\0')
//			continue;
		q=malloc(sizeof(wordstatic));
		q->link=NULL;
		q->times=1;
		if (list==NULL){
			list=q;//end指向最后一个结构体(link指向NULL)
			q->times=0;//下面判断这单词就是表里最前单词就加回1	
		}
		strcpy(q->word,word);
		if (strcmp(list->word,q->word)>0){//这词比表里最前单词还前
			q->link=list;
			list=q;
		}
		else if (!strcmp(list->word,q->word))//这词就是表里最前单词
			list->times++;
		else{
			p=list;
			r=list->link;
			while (r!=NULL){//从头至尾找这词之前有无出现过,并按顺序放置
				if (strcmp(r->word,q->word)>=0){
					if (!strcmp(r->word,q->word))//这单词在表里有
						r->times++;
					else{//这单词在表里没有
						q->link=r;
						p->link=q;
					}
					break;
				}
				p=r;
				r=r->link;
			}
			if ((r==NULL) && (strcmp(p->word,q->word)<0))//是表中最后一个
				p->link=q;
		}
	}
	q=list;
	while (q!=NULL){//打印词频统计
		printf("%s %d\n",q->word,q->times);
		q=q->link;
	}
	fclose(op);
	return 0;
}




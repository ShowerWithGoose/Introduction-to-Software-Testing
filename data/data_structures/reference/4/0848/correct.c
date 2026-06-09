#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD  32
struct node {
    char word[MAXWORD];
    int count;
    struct node *link;
} ; //单词表结构
struct node *Wordlist = NULL; //单词表头指针
int getWord(FILE *bfp,char *w);
int insertWord( struct node *p, char *w);
int searchWord(char *w);
int getWord(FILE *bfp,char *w){
	char ch;
	int i=0;
	while((ch=fgetc(bfp))!=EOF){
		if(ch>='a'&&ch<='z'){
			w[i++]=ch;
		}
		else if(ch>='A'&&ch<='Z'){
			w[i++]=ch+'a'-'A';
		}
		else{
			if(i>0){
			w[i]='\0';
			return 1;
			}
		}
	}
	return EOF;
}
/*int getWord(FILE *bfp,char *w)
{
    int i=0;
    char c;
    while((c=fgetc(bfp))!=EOF){
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
        	if(c>='A'&&c<='Z') c=c-'A'+'a';
            w[i++]=c;
        }
        else{
            if(i>0){
            	w[i]='\0';
            	return 1;
			}
        }
    }
    return EOF;
}*/
/*在链表中p结点后插入包含给定单词的结点，同时置次数为1*/
int insertWord(struct node  *p, char *w)
{
      struct node  *q;
      q = (struct node * )malloc(sizeof(struct node));
      if(q == NULL) return -1; //没有内存空间
      strcpy(q->word, w);
      q->count = 1;
      q->link = NULL;              
      if(Wordlist == NULL) //空链表
           Wordlist = q;
      else if (p == NULL){ //插入到头结点前9
           q->link = Wordlist;
           Wordlist = q;
       }
       else {
           q->link = p->link;
           p->link = q;
       }
      return 0;
}
/*在链表中查找一单词，若找到，则次数加1；否则将该单词插入到有序表中相应位置，同时次数置1*/
int searchWord(char *w)
{
struct  node *p, *q=NULL; //q为p的前序结点指针
for(p=Wordlist; p != NULL; q=p,p=p->link){
    if(strcmp(w, p->word) < 0) break;
    else if(strcmp(w, p->word) == 0){
         p->count++;
         return 0 ;
    }
}
return insertWord(q, w);
}
int main()
{
    char word[MAXWORD];
    FILE *bfp;
    struct node *p;
    int n=0;
     bfp = fopen("article.txt", "r");
     while( getWord(bfp,word) != EOF){ //从文件中读入一个单词

        searchWord(word);//在单词表中查找插入单词
        }
    for(p=Wordlist; p != NULL; p=p->link) //遍历输出单词表
        printf("%s %d\n", p->word, p->count);
    return 0;
}



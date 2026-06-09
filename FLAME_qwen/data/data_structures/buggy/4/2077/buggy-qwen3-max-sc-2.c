#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD  3200
struct node {
    char word[MAXWORD];
    int count;
    struct node *link;
} ; //单词表结构
struct node *Wordlist = NULL; //单词表头指针
int getWord(FILE *bfp,char *w);//从文件中读入单词 
int searchWord(char *w);//查找单词 ，找到单词数加一，未找到单词插入单词表 
int insertWord( struct node *p, char *w);//在P后插入单词 
int main()
{
    char filename[32], word[MAXWORD];
    FILE *bfp;
    struct node *p;
    if((bfp = fopen("article.txt", "r")) == NULL){ //打开一个文件
        fprintf(stderr, "%s  can’t open!\n",filename); // @@ [filename is uninitialized; should use "article.txt" in the error message or initialize filename]
        return -1;
     }
     while( getWord(bfp,word) != EOF) //从文件中读入一个单词
        if(searchWord(word) == -1) { //在单词表中查找插入单词
            fprintf(stderr, "Memory is full!\n");
            return -1;
        }
    for(p=Wordlist; p != NULL; p=p->link){ //遍历输出单词表
        printf("%s %d\n", p->word, p->count);
        /*if(p->link!=NULL){
            printf("\n");
        }*/
    }
    return 0;
} 
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
      else if (p == NULL){ //插入到头结点前
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
    if(strcmp(w, p->word) < 0) 
        break;
    else if(strcmp(w, p->word) == 0){
         p->count++;
         return 0 ;
    }
}
return insertWord(q, w);
}
/*在文件中读入单词给*w*/ 
int getWord(FILE *bfp,char *w){
    char c; 
    while((c=fgetc(bfp))!=EOF){
        if(c>='A'&&c<='Z'){
            c=tolower(c);
        }
        if(c>='a'&&c<='z'){
            *w=c;
            w++;
        }
        if((c==' '||c=='\n'||c=='\t')&&*(w-1)>='a'&&*(w-1)<='z'){
            *w='\0';
            return 0;
        }
    }
} // @@ [Missing handling of EOF when a word is being read at end-of-file; function may not null-terminate the word or return properly, leading to undefined behavior. Also, using char for fgetc() return value causes EOF comparison issues because char may be unsigned.]
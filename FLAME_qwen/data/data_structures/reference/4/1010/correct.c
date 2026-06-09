#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAXWORD  32
struct node {
    char word[MAXWORD];
    int count;
    struct node *link;
} ; //单词表结构
struct node *Wordlist = NULL; //单词表头指针
int getWord(FILE *fp,char *w);
int isNull(char c);
int searchWord(char *w);
int insertWord( struct node *p, char *w);
int main()
{
 FILE* fp=fopen("article.txt","r");
    char word[MAXWORD];
    struct node *p;
     while( getWord(fp,word) != NULL) //从文件中读入一个单词
        if(searchWord(word) == -1) { //在单词表中查找插入单词
            fprintf(stderr, "Memory is full!\n");
            return -1;
        }
        
    for(p=Wordlist; p != NULL; p=p->link) {//遍历输出单词表
        printf("%s %d\n", p->word, p->count);} 
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
int getWord(FILE *fp,char *str)
{
char c;
int counter = 0;
while((c = fgetc(fp)) != EOF){
if( isNull(c) && (counter <= 0)){
continue;
}
else if(isNull(c) && (counter > 0)){
//?个单词读取完毕
break;
}
if(c>='a' && c<='z'){
str[counter++] = c;}
else if(c>='A' && c<='Z'){
	str[counter++]='a'+c-'A';
}
}
str[counter] = '\0';
//成功返回SUCCESS 否则返回FAIL
if(counter > 0)
return 1;
else
return 0;
}
int isNull(char c)
{
return !(((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')));
}


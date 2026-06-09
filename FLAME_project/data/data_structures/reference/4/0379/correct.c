#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

struct node {
char word[32];
int count;
struct node *link;
} ; //单词表结构
struct node *Wordlist = NULL; //单词表头

int getWord(FILE *in,char *w);
int searchWord(char *w);
int insertWord( struct node *p, char *w);

int main(){
char  word[32];
FILE *in;
struct node *p;

in = fopen("article.txt", "r");
while( getWord(in,word) != EOF) //从文件中读入一个单词
if(searchWord(word) == -1) { //在单词表中查找插入单词
fprintf(stderr, "Memory is full!\n");
return -1;
}
for(p=Wordlist; p != NULL; p=p->link) //遍历输出单词表
printf("%s %d\n", p->word, p->count);
return 0;
}

int searchWord(char *w){
struct node *p, *q=NULL; //q为p的前序结点指针
for(p=Wordlist; p != NULL; q=p,p=p->link){
if(strcmp(w, p->word) < 0) 
break;
else if(strcmp(w, p->word) == 0){
p->count++;
return 0 ;
} }
return insertWord(q, w);
}

int insertWord(struct node *p, char *w){
struct node *q; q = (struct node * )malloc(sizeof(struct node));
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

int getWord(FILE *fp, char *w){
int c;
while(!isalpha(c=fgetc(fp))) 
if(c == EOF) return c; 
else continue;
do {
*w++ = tolower(c);
} while(isalpha(c=fgetc(fp))); 
*w='\0';
return 1;
} 




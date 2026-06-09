#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>

# define N 100

struct node
{
    char word[N];
    int cnt;
    struct node *next;
};//某个单词和它的出现次数
typedef struct node Node;
typedef struct node *Link;

int get(FILE *in, char word[]);
void insert(Link p, char *w);
void locate(char *w);
Link list=NULL; //头指针
int main()
{
    FILE *in;
    in = fopen("article.txt","r");
    
    char word[N];
    while(get(in,word)!=EOF) {locate(word);}

    Link p;
    for(p=list;p!=NULL;p=p->next)
    {
        printf("%s %d\n", p->word, p->cnt);
    }
    return 0;
}

int get(FILE *in, char word[])//从文件中读入一个单词，并转换成小写
{
    int i=0;
    char c;

    while((c=fgetc(in))!=EOF)//注意！优先级！
    {
        if(isalpha(c)) {word[i++]=tolower(c);}
        else if(i>0) {word[i]='\0'; return 0;}
    }
    return EOF;
}

void insert(Link p, char *w)//在节点p后面插入包含给定新单词的节点,同时让单词次数为1
{
    Link q; q=malloc(sizeof(Node));
    strcpy(q->word,w); q->cnt++; q->next=NULL;
    if(list==NULL) list=q;//空链表
    else if(p==NULL)//插入到头节点前
    {
        q->next=list; list=q;
    }
    else
    {
        q->next=p->next; p->next=q;
    }
    return;
}

void locate(char *w)//在链表中放置包含给定单词的节点
{
    Link p,q; q=NULL;//q为p的前一个节点
    for(p=list;p!=NULL;q=p,p=p->next)
    {
        if(strcmp(p->word,w)==0) {p->cnt++; return;}
        else if(strcmp(p->word,w)>0) break;
    }
    insert(q,w);
}







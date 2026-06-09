#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define ull unsigned long long
#define MAXWORD 20

struct node
{
    char word[MAXWORD];
    int cnt;
    struct node*next;
};
typedef struct node* Nodeptr;
   Nodeptr head=NULL,p;

int get(FILE*in,char *w);
int search(char *w);
int insert(Nodeptr p,char *w);

int main()
{
	FILE*in;
      char word[MAXWORD];
    in=fopen("article.txt","r");
    while(get(in, word)!=EOF) //如果函数最后不返回EOF就结束不了了
    {
       search(word);
    }

    for(p=head;p!=NULL;p=p->next)
    {
        printf("%s %d\n",p->word,p->cnt);
    }

    return 0;

}

int get(FILE*in,char word[])
{
     char c=fgetc(in);
     int i=0;
    while(c!=EOF)
    {
       
        if(((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z')))
        {
            word[i++]=tolower(c);
        }
        else if(i!=0)
        {
            word[i]='\0';
            return 0;
        }
        c=fgetc(in);
    }

    return EOF;
}


int search(char*w)
{
    Nodeptr pos=NULL , move;//如果不打pos=NULL?
    for(move=head;move!=NULL;pos=move,move=move->next)
    {
        if(strcmp(w,move->word)<0)break;
        else if(strcmp(w,move->word)==0){
        move->cnt++;
        return 0;}
    }
    return insert(pos,w);

}

int insert(Nodeptr pos,char*w)
{
    Nodeptr stor;
    stor=(Nodeptr)malloc(sizeof(struct node));
    strcpy(stor->word,w);
    stor->cnt=1;
    stor->next=NULL;//如果没有呢

    if(head==NULL) head=stor;
    else if(pos==NULL) 
    {
        stor->next=head;
        head=stor;
    }
    else{
        stor->next=pos->next;
        pos->next=stor;
    }
    return 0;

}


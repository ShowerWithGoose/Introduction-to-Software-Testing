#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 1025
typedef struct a{
    char word[N];
    int cnt;
    struct a *link;
}Node;
Node *list,*p,*q;
Node *Sort(Node *list,char s[])
{
    Node *p=list; // @@ [list is a dummy head node with uninitialized word, comparing it causes undefined behavior; should start from list->link]
    if(list->link==NULL)return NULL;//如果是第一次
    while(p!=NULL)
    {
        if(strcmp(p->word,s)==0)return p;
        p=p->link;
    }
    return NULL;
}
void Insert(Node *list,char s[])
{
    Node *p=list->link,*q,*pl;
    if(list->link==NULL)//如果是第一次
    {
        q=(Node *)malloc(sizeof(Node));
        strcpy(q->word,s);
        q->cnt=1;
        list->link=q;
        q->link=NULL;
     }
    else
    {
    if(strcmp(p->word,s)==1)//判断头节点是否比s大 // @@ [strcmp returns >0, not necessarily 1; should use >0]
     {
     q=(Node*)malloc(sizeof(Node));
     strcpy(q->word,s);
     q->link=list->link;
     list->link=q;
     q->cnt=1;
     return;
    }
    p=p->link;
    pl=list->link;//方便插入
       while(p!=NULL&&strcmp(p->word,s)==-1) // @@ [strcmp returns <0, not necessarily -1; should use <0]
        {
            p=p->link;pl=pl->link;
        }
        q=(Node*)malloc(sizeof(Node));
        q->cnt=1;
        strcpy(q->word,s);
    if(p==NULL)//在结尾插入
    {
        q->link=NULL;
        pl->link=q;
    }
    else
    {
        q->link=p;
        pl->link=q;
    }
}
}
void Output(Node* list)
{
    Node *p=list->link;
    while(p!=NULL)
    {
        printf("%s %d\n",p->word,p->cnt);
        p=p->link;
    }
}
int main ()
{
    FILE *fp=fopen("article.txt","r");
    list=(Node*)malloc(sizeof(Node));
    list->link=NULL;
    char c=fgetc(fp); // @@ [fgetc returns int, storing in char may truncate EOF and cause incorrect loop termination; should be int c]
    ///不断读入单词
    while(c!=EOF)
    {
        int i=0;
        char s[N];
        while(!isalpha(c)&&c!=EOF)c=fgetc(fp);
        while(isalpha(c))
        {
            c=(isupper(c))?tolower(c):c;
            s[i++]=c;
            c=fgetc(fp);
        }
        s[i]='\0';//获得单词s
        if(i!=0)
        {p=Sort(list,s); //printf("%s",list->word);
        if(p==NULL)
        {Insert(list,s);}//新单词加入
        else
        p->cnt++;
         }
    }
    Output(list);
    fclose(fp);
    return 0;
}
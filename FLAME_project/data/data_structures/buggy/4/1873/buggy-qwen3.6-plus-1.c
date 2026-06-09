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
    Node *p=list->link; // @@ The original code started with p=list, but list is a dummy head node. It should start with list->link to check actual words. Also, the condition if(list->link==NULL) return NULL is correct for empty list, but the traversal logic needs to start from the first real node.
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
    if(strcmp(s, p->word) < 0) // @@ The original code used strcmp(p->word,s)==1 which is incorrect. strcmp returns <0 if first arg is less than second. We want to insert if s is lexicographically smaller than the first element (p). So we check if s < p->word.
     {
     q=(Node*)malloc(sizeof(Node));
     strcpy(q->word,s);
     q->link=list->link;
     list->link=q;
     q->cnt=1;
     return;
    }
    pl = list->link; // @@ pl should track the node before p. Initially p is list->link. If we enter the loop, pl needs to be updated. However, the logic below advances p and pl. Let's look at the loop condition.
    p = p->link; // @@ We already checked the first node (list->link) above. Now we move to the next node to find the insertion point.
       while(p!=NULL && strcmp(s, p->word) > 0) // @@ We want to find the position where s <= p->word. So we continue while s > p->word. The original code used strcmp(p->word,s)==-1 which is equivalent to s > p->word, but relying on specific return values like -1 is bad practice, though logically similar. However, the pointer advancement was flawed in the original code because pl wasn't initialized correctly relative to the new p.
        {
            pl = p; // @@ pl must follow p. In the original code, pl was initialized to list->link and then advanced. Here, since p started at list->link->link, pl should start at list->link. Inside the loop, pl becomes the old p, then p becomes p->link.
            p=p->link;
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
    char c=fgetc(fp);
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
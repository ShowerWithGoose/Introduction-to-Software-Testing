#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node{
    char *word;
    int n;
    struct node* next;
}node;

typedef struct linklist{
    node *head;
    int size;
}linklist;

node *initnode(char *s,int n){
    node *p=(node *)malloc(sizeof(node ));
    p->next=NULL;
    p->word=s;
    p->n=n;
    return p;
}


linklist *init(){
    linklist* l=(linklist *)malloc(sizeof(linklist));
    l->head=initnode(0,0);
    l->size=0;
    return l;
}

void add(linklist *l,char *s){
    node *p=l->head;
    while(p->next!=NULL && strcmp(s, p->next->word)>0){
        p=p->next;
    }
    if (p->next==NULL) {
        node *new=initnode(s, 1);
        p->next=new;
        return;
    }
    if(strcmp(s, p->next->word)==0){
        p->next->n++;
        return;
    }
    node *new=initnode(s, 1);
    new->next=p->next;
    p->next=new;
    return;
}

void output(linklist *l){
    node *p=l->head->next;
    while(p!=NULL){
        printf("%s %d\n",p->word,p->n);
        p=p->next;
    }
    return;
}

void divid(linklist *l,char* s){
    int i=0;
    char *word=malloc(sizeof(char )*100);
    int j=0;
    while(s[i]!='\0'){
        if(isalpha(s[i]))word[j++]=tolower(s[i]);
        else{
            word[j]='\0';
            if(j!=0){
                add(l,word);
                word=malloc(sizeof(char )*100);
                j=0;
            }
        }
        i++;
    }
}

int main(){
    FILE *fp;
    fp=fopen("article.txt", "r");
    linklist *l=init();
    char s[1001];
    while(fgets(s, 1000, fp)){
        divid(l,s);
    }
    output(l);
    return 0;
}


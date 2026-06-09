#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char word[100];
    int count;
    struct node* link;
} ;

typedef struct node* Nodeptr;
typedef struct node Node;

Nodeptr list=NULL;
int searchword(char *w);
int insertword(Nodeptr p,char *w);

int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    Nodeptr p;
    char temp;
    int i=0;
    char word[100];
    while((temp=fgetc(in))!=EOF){
        if(!isalpha(temp)) {
            if(i!=0){
                word[i]='\0';
                i=0;
                searchword(word);
                memset(word,0,sizeof(word));
            }
            continue;
        }
        word[i++]=tolower(temp);        
    }
    for(p=list;p!=NULL;p=p->link){
        printf("%s %d\n",p->word,p->count);
    }
    return 0;
}


int insertword(Nodeptr p,char *w){
    Nodeptr q;
    q=(Nodeptr)malloc(sizeof(Node));
    strcpy(q->word,w);
    q->count=1;
    q->link=NULL;
    if(list==NULL){
        list=q;
    }else if(p==NULL){
        q->link=list;
        list=q;
    }else {
        q->link=p->link;
        p->link=q;
    }
    return 0;
}

int searchword(char *w){
    Nodeptr p=NULL;
    Nodeptr q=NULL;
    for(p=list;p!=NULL;q=p,p=p->link){
        if(strcmp(w,p->word)<0){
            break;
        }else if(strcmp(w,p->word)==0){
            p->count++;
            return 0;
        }
    }
    return insertword(q,w);
}


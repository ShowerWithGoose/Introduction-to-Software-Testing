#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define  MAXWORD 32
struct node{
char word[MAXWORD];
int count;
struct node *link;
};
struct node *list=NULL;
int getword(FILE *fp,char word[]);
int searchword(char *p);
int insertword(struct node *p,char s[]);
int main()
{
    FILE *fp;
    fp=fopen("article.txt","r");
    char s[MAXWORD];
    struct node *p,*q,*p0,*q0,*r;
    p=list;
    while(getword(fp,s)!=EOF){
        if(list==NULL){
            q=(struct node*)malloc(sizeof (struct node));
            q->count=1;
            strcpy(q->word,s);
            q->link=NULL;
            list=p=q;
        }
        else{
            int flag=0;
            for(p0=list;p0!=NULL;q0=p0,p0=p0->link){
                if(strcmp(p0->word,s)==0){
                    p0->count++;
                    flag++;
                    break;
                }
                else if(strcmp(p0->word,s)>0){
                    r=(struct node*)malloc(sizeof (struct node));
                    r->count=1;
                    strcpy(r->word,s);
                    r->link=NULL;
                    if(p0==list){
                        r->link=list;
                        list=r;
                    }
                    else{
                        r->link=q0->link;
                        q0->link=r;
                    }
                    flag++;
                    break;
                }
            }
            if(flag==0){
                q=(struct node*)malloc(sizeof (struct node));
                q->count=1;
                strcpy(q->word,s);
                q->link=NULL;
                p->link=q;
                p=q;
            }
        }
    }
    for(p=list;p!=NULL;p=p->link){
        printf("%s %d\n",p->word,p->count);
    }
    return 0;
}
int getword(FILE *fp,char word[])
{
    char a;
    int i=0;
    while((a=fgetc(fp))!=EOF){
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')){
            word[i]=tolower(a);
            i++;
        }
        else if(i>0){
            word[i]='\0';
            return 0;
        }
    }
    return EOF;
}


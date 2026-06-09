#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL  long long
#define ULL  unsigned long long

typedef struct Node
{
    int a;
    int e;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

int main(void)
{
    LinkList L1=(LinkList)malloc(sizeof(Node));
    LinkList L2=(LinkList)malloc(sizeof(Node));
    int a,e,i=0;
    char s[1000];
    LinkList p=L1,q=L2,r,t,cur;
    gets(s);
    while(s[i]!='\0'){
        a=atoi(&s[i]);
        while(s[i]!=' ')i++;i++;
        e=atoi(&s[i]);
        while(s[i]!=' '&&s[i]!='\0')i++;
        p->a=a;p->e=e;
        if(s[i]!='\0'){
            i++;
            r=(LinkList)malloc(sizeof(Node));
            p->next=r;
            p=p->next;
        }else{
            p->next=NULL;
        }
    }
    i=0;
    gets(s);
    while(s[i]!='\0'){
        a=atoi(&s[i]);
        while(s[i]!=' ')i++;i++;
        e=atoi(&s[i]);
        while(s[i]!=' '&&s[i]!='\0')i++;
        q->a=a;q->e=e;
        if(s[i]!='\0'){
            i++;
            r=(LinkList)malloc(sizeof(Node));
            q->next=r;
            q=q->next;
        }else{
            q->next=NULL;
        }
    }
    p=L1;q=L2;
    LinkList L3=(LinkList)malloc(sizeof(Node));
    r=L3;
    while(q!=NULL){
        r->a=p->a*q->a;
        r->e=p->e+q->e;
        q=q->next;
        if(q!=NULL){
            t=(LinkList)malloc(sizeof(Node));
            r->next=t;
            r=t;
        }else{
            r->next=NULL;
        }
    }
    r->next=NULL;
    p=p->next;
    while(p!=NULL){
        q=L2;
        while(q!=NULL){
            r=L3;
            while(r&&r->next&&p->e+q->e < r->e&&p->e+q->e < r->next->e){
                r=r->next;
            }
            if(r->next&&p->e+q->e > r->next->e){
                t=(LinkList)malloc(sizeof(Node));
                t->next=r->next;
                r->next=t;
                t->a=p->a*q->a;
                t->e=p->e+q->e;
            }else if(r->next&&p->e+q->e == r->next->e){
                r->next->a+=p->a*q->a;
            }else{
                t=(LinkList)malloc(sizeof(Node));
                r->next=t;
                t->a=p->a*q->a;
                t->e=p->e+q->e;
                t->next=NULL;
            }
            q=q->next;
        }
        p=p->next;
    }
    r=L3;
    while(r!=NULL){
        printf("%d %d ",r->a,r->e);
        r=r->next;
    }
    return 0;
}

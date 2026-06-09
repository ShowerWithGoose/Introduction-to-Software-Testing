#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define pi acos(-1)
#define eps 1e-8
struct node{
    int coef;
    int exp;
    struct node *next;
};
typedef struct node *Pnode;
typedef struct node Node;
typedef struct a{
    int coef;
    int exp;
}pnode,as;
int cmp(const void *a, const void *b);
int main() {
    Pnode p1=NULL,p2=NULL,q1,q2;
    Pnode head1=NULL,head2=NULL;
    Pnode p=NULL,list=NULL,q=NULL;
    int len1=0,len2=0;
    char c;
    int tcoe,texp;
//以下为输入部分
    do {
        scanf("%d%d%c",&tcoe,&texp,&c);
        q1=(Pnode) malloc(sizeof(Node));
        q1->coef=tcoe;
        q1->exp=texp;
        q1->next=NULL;
        if(head1==NULL)
            head1=p1=q1;
        else
            p1->next=q1;
        p1=q1;
        len1++;
    }while(c!='\n');
    do
    {
        scanf("%d%d%c",&tcoe,&texp,&c);
        q2=(Pnode) malloc(sizeof(Node));
        q2->coef=tcoe;
        q2->exp=texp;
        q2->next=NULL;
        if(head2==NULL)
            head2=p2=q2;
        else
            p2->next=q2;
        p2=q2;
        len2++;
    }while(c!='\n');
//以下为计算部分
    int count=len1*len2;
    for (int i=0;i<count;i++){
        q=(Pnode)malloc(sizeof(Node));
        q->next=NULL;
        if(list==NULL)
            list=p=q;
        else
            p->next=q;
        p=q;
    }
//    p1=head1;q1=p1->next;
//    p2=head2;q2=p2->next;
    p=list;
    for(p1=head1;p1!=NULL;q1=p1,p1=p1->next){
        for(p2=head2;p2!=NULL;q2=p2,p2=p2->next){
            p->coef=p1->coef * p2->coef;
            p->exp=p1->exp + p2->exp;
            p=p->next;
        }
    }
    //以下为转化到结构体中，以便排序合成；
    p=list;
    pnode in[count];
    for (int i = 0; i < count; ++i) {
        in[i].coef=p->coef;
        in[i].exp=p->exp;
        p=p->next;
    }

    qsort(in,count,sizeof(as),cmp);
//以下为把指数相同的两项合并
    for (int i = 0; i < count-1; ++i) {
        if(in[i].exp==in[i+1].exp){
            in[i].coef+=in[i+1].coef;
            for (int j = i+2; j < count; ++j) {
                in[j-1].exp=in[j].exp;
                in[j-1].coef=in[j].coef;
            }
            count--;
            i--;
        }
    }

    //以下为输出
    for (int i = 0; i < count; ++i) {
        printf("%d %d ",in[i].coef,in[i].exp);
    }

    return 0;
}

int cmp(const void *a, const void *b) {
    pnode *p1 = (pnode*) a;
    pnode *p2 = (pnode*) b;
    return p2->exp - p1->exp;
}



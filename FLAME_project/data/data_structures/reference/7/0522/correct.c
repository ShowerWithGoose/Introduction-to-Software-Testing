#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
int da;
struct node *lch,*rch;
int de;
};
int depth;
void goon(struct node *p)
{
    if(p->lch!=NULL){
        goon(p->lch);
    }
    if(p->lch==NULL&&p->rch==NULL){
        printf("%d",p->da);
        printf(" %d\n",p->de);
    }
    if(p->rch!=NULL){
        goon(p->rch);
    }
}
struct node* f(struct node* p,int a)
{
    depth++;
    if(p==NULL){
        struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->da=a; tmp->de=depth;
    tmp->lch=NULL;tmp->rch=NULL;
    p=tmp;
    }
    else if(a<p->da){
        p->lch=f(p->lch,a);
    }
    else{
        p->rch=f(p->rch,a);
    }
    return p;
}
int main()
{
    struct node *t;
    int n,a,i=0;
    scanf("%d",&n);
    while(i<n){
        scanf("%d",&a);
        if(i==0){
           struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->da=a; tmp->de=1;
    tmp->lch=NULL;tmp->rch=NULL;
    t=tmp;
        }
        else{
            depth=0;
            f(t,a);
        }
        i++;
    }
    goon(t);
    return 0;
}


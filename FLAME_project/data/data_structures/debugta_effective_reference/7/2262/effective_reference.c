#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
int da;
struct node *lch,*rch;
int de;
};
int cnt;
void search(struct node *p)
{
    if(p->lch!=NULL){
        search(p->lch);
    }
    if(p->lch==NULL&&p->rch==NULL){
        printf("%d",p->da);
        printf(" %d\n",p->de);
    }
    if(p->rch!=NULL){
        search(p->rch);
    }
}
struct node* insert(struct node* p,int a)
{
    cnt++;
    if(p==NULL){
        struct node *p=(struct node*)malloc(sizeof(struct node));
    p->da=a; p->de=cnt;
    p->lch=NULL;p->rch=NULL;
    p=p;
    }
    else if(a<p->da){
        p->lch=insert(p->lch,a);
    }
    else{
        p->rch=insert(p->rch,a);
    }
    return p;
}
int main()
{
    struct node *root;
    int n,a,i=0;
    scanf("%d",&n);
    while(i<n){
        scanf("%d",&a);
        if(i==0){
           struct node *p=(struct node*)malloc(sizeof(struct node));
    p->da=a; p->de=1;
    p->lch=NULL;p->rch=NULL;
    root=p;
        }
        else{
            cnt=0;
            insert(root,a);
        }
        i++;
    }
    search(root);
    return 0;
}


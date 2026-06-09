#include<stdio.h>
#include<stdlib.h>

struct tree{
    int a;
    struct tree*lc;
    struct tree*rc;
};

struct tree *createbranch(int c){
    struct tree *newbranch=(struct tree*)malloc(sizeof(struct tree));
    newbranch->a=c;
    newbranch->lc=NULL;
    newbranch->rc=NULL;
}; // @@ [Missing return statement in non-void function createbranch]

void f(struct tree *,int);

int main()
{
    int n,m=0;
    scanf("%d",&n);
    scanf("%d",&m);
    struct tree *p;
    struct tree *start=createbranch(m);
    n--;
    while(n--){
        scanf("%d",&m);
        struct tree *q=createbranch(m);
        p=start;
        while(1){
            if(q->a<p->a){
                if(p->lc!=NULL){
                    p=p->lc;
                }
                else{
                    p->lc=q;
                    break;
                }
            }
            else if(q->a>=p->a){
                if(p->rc!=NULL){
                    p=p->rc;
                }
                else{
                    p->rc=q;
                    break;
                }
            }
        }
    }
    f(start,0);
} // @@ [Missing return 0; in main function which is expected to return int]

void f(struct tree*start,int t)
{
    t++;
    if(start->lc==NULL&&start->rc==NULL){
        printf("%d %d\n",start->a,t);
        return;
    }
    else{
        if(start->lc!=NULL){
            f(start->lc,t);
        }
        if(start->rc!=NULL){
            f(start->rc,t);
        }
        return;
    }
}
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
int n,i=1,d=1;
struct NODE{
    int val;
    struct NODE *lch,*rch;
};
typedef struct NODE bnode,*node;
node insert(node p,int x){
    if(p==NULL){
        p=(node)malloc(sizeof(bnode));
        p->val=x;
        p->lch=p->rch=NULL;
    }
    else{
        if(x<p->val)p->lch=insert(p->lch,x);
        else p->rch=insert(p->rch,x);
    }
    return p;
}
void tr(node p){
    if(p==NULL)return;
    if(p->rch==NULL&&p->lch==NULL)printf("%d %d\n",p->val,d);
    d++;
    tr(p->lch);
    tr(p->rch);
    d--;
}
int main() {
    int x;
    scanf("%d",&n);
    node root=NULL;
    for(;i<=n;i++){
        scanf("%d",&x);
        root=insert(root,x);
    }
    tr(root);
    return 0;
}

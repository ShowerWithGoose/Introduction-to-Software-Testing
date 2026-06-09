#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node*lch,*rch;
}tnode;
int i=1;
typedef struct node* tnptr;
tnptr root;
tnptr insert(tnptr p,int m){
    if(p==NULL){
        p=(tnptr)malloc(sizeof(tnode));
        p->val=m;
        p->lch=p->rch=NULL;
    }
    else {
        if (p->val>m) p->lch=insert(p->lch,m);
        else p->rch=insert(p->rch, m);
    }
    return p;
}
void preorder(tnptr p){
    if(p==NULL) return;
    else{
        if(p->lch==NULL&&p->rch==NULL){
            printf("%d %d\n",p->val,i);
        }
        i++;
        preorder(p->lch);
        preorder(p->rch);
        i--;
    }

}
int main(){
   int n,tmp;
   scanf("%d",&n);
   for(int i=0;i<n;i++){
       scanf("%d",&tmp);
       root=insert(root,tmp);
   }
   preorder(root);

}




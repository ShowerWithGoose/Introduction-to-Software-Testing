#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node{
    int num;
    struct node *left,*right;
};
typedef struct node *tree;
tree insert(tree p,int n){
    if(p==NULL){
        p=(tree)malloc(sizeof(tree));
        p->num=n;
        p->left=NULL;
        p->right=NULL;
    }
    else if(n<p->num)
        p->left=insert(p->left,n);
    else if(n>=p->num)
        p->right=insert(p->right,n);
    return p;
}
void visit(tree p,int cot){
    if(p!=NULL){
        cot++;
        visit(p->left,cot);
        cot--;
        cot++;
        visit(p->right,cot);
        cot--;
    //    printf("%d\n",p->num);
        if(p->left==NULL&&p->right==NULL){
            printf("%d %d\n",p->num,cot);
        }
    }
}
int main(){
    int n,i,num;
    scanf("%d",&n);
    tree root=NULL;
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        root=insert(root,num);
    }
    int cot0=1;
    visit(root,cot0);
    return 0;
}


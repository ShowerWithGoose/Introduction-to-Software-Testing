#include<stdio.h>
#include<stdlib.h>
struct bst{
    int content,times;
    struct bst*left,*right;
}*root,*p,*cnm[302],*q;
int main(){
    int n,flag,top=0;
    char cnmi[302]={};
    scanf("%*d%d",&n);
    root=(struct bst*)malloc(sizeof(struct bst));
    root->content=n;root->left=root->right=NULL;root->times=1;
    while(~scanf("%d",&n)){
        p=root;flag=1;
        while(flag){
            if(p->content>n){
                if(p->left!=NULL)p=p->left;
                else{
                    p->left=(struct bst*)malloc(sizeof(struct bst));
                    q=p->left;q->content=n;q->left=q->right=NULL;q->times=p->times+1;
                    flag=0;
                }
            }
            else{
                if(p->right!=NULL)p=p->right;
                else{
                    p->right=(struct bst*)malloc(sizeof(struct bst));
                    q=p->right;q->content=n;q->left=q->right=NULL;q->times=p->times+1;
                    flag=0;
                }
            }
        }
    }
    cnm[top++]=root;n=0;
    while(~n){
        if(cnmi[n]==0){
            if(cnm[n]->left==NULL&&cnm[n]->right==NULL)printf("%d %d\n",cnm[n]->content,cnm[n]->times),top--,n--;
            else if(cnm[n]->left!=NULL)cnmi[n]=1,cnmi[top]=0,cnm[top++]=cnm[n]->left,n++;
            else cnmi[n]=1;
        }
        else if(cnmi[n]==1){
            if(cnm[n]->right!=NULL)cnmi[n]=2,cnmi[top]=0,cnm[top++]=cnm[n]->right,n++;
            else top--,n--;
        }
        else top--,n--;
    }
    return 0;
}

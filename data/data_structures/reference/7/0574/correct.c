#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct Tree
{
    int num,height;
    struct Tree *llink,*rlink;

}TREE;
void PREORDER(TREE* root)
{
    if(root!=NULL){
        if(root->llink==NULL&&root->rlink==NULL)printf("%d %d\n",root->num,root->height);
        PREORDER(root->llink);
        PREORDER(root->rlink);
    }
}
int main()
{
    TREE *root=NULL,*p=NULL,*r=NULL;
    int n,h;
    scanf("%d",&n);
    for(int i=1;i<=n;i++,p=NULL){
        p=(TREE*)malloc(sizeof(TREE));
        scanf("%d",&(p->num));
        p->height=1;
        p->rlink=NULL;
        p->llink=NULL;
        if(root==NULL){
            root=p;
        }
        else{
            for(r=root;;){
                if(p->num>=r->num){
                    if(r->rlink==NULL){
                        r->rlink=p;
                        p->height=r->height+1;
                        break;
                    }
                    else if(r->rlink!=NULL){
                        r=r->rlink;
                        continue;
                    }
                }
                else if(p->num<r->num){
                    if(r->llink==NULL){
                        r->llink=p;
                        p->height=r->height+1;
                        break;
                    }
                    else if(r->llink!=NULL){
                        r=r->llink;
                        continue;
                    }
                }
            }
        }
    }
    PREORDER(root);
    return 0;
}


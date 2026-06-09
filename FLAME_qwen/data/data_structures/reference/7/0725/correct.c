#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
struct tree{
    int n;
    int lev;
    struct tree *left;
    struct tree *right;
};
struct tree *root=NULL;
int front=0,top=-1;
struct tree *crea()
{
    struct tree *p;
    p=(struct tree*)malloc(sizeof(struct tree));
    p->left=NULL;
    p->right=NULL;
    p->lev=0;
    p->n=0;
    return p;
}
void insert(int a)
{
    struct tree *p,*q;
    if(root==NULL){
        root=crea();
        root->n=a;
        q=root;
    }
    else{
        p=crea();
        p->n=a;
        q=root;
        while(1){
            if(a>=q->n){
                p->lev++;
                if(q->right==NULL){
                    q->right=p;
                    break;
                }
                else{
                    q=q->right;
                }
            }
            if(q->n>a){
                p->lev++;
                if(q->left==NULL){
                    q->left=p;
                    break;
                }
                else{
                    q=q->left;
                }
            }
            
        }
    }
}
void search(struct tree *p)
{
    if(p!=NULL){
        search(p->left);
        search(p->right);
        if(p->left==NULL&&p->right==NULL){
            printf("%d %d\n",p->n,p->lev+1);
        }
    }
}
int main(){
    int n,a;
    struct tree *p;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       scanf("%d",&a);
       insert(a); 
    }
    p=root;
    search(p);
    system("pause");
    return 0;
}

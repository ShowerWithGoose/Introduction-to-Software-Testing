#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct node{
    int key;
    struct node *lch,*rch;
}bst,*bstp;

int layer=0;
bstp root=NULL;
bstp cur=NULL;

void InsertBst(int num){
    cur=root;
    while(1){
        if((cur->key)>num){
            if(cur->lch){
                cur=cur->lch;
                continue;
            }
            else{
                cur->lch=(bstp)malloc(sizeof(bst));
                cur=cur->lch;
                cur->key=num;
                cur->lch=NULL;
                cur->rch=NULL;
                break;
            }
        }
        if((cur->key)<=num){
            if(cur->rch){
                cur=cur->rch;
                continue;
            }
            else{
                cur->rch=(bstp)malloc(sizeof(bst));
                cur=cur->rch;
                cur->key=num;
                cur->lch=NULL;
                cur->rch=NULL;
                break;
        }
        break;
    }
    return;
}
}

void DFS(bstp p){
    layer++;
    if(p->lch){
        DFS(p->lch);
        layer--;
    }
    if(p->rch){
        DFS(p->rch);
        layer--;
    }
    if(!(p->lch)&&!(p->rch)) printf("%d %d\n",p->key,layer);
    return;
}

int main(){
	int n;
	scanf("%d",&n);
	int i = 0,tmp;
	for(;i < n; i++){
        scanf("%d",&tmp);
        if(!root){
            root=(bstp)malloc(sizeof(bst));
            root->key=tmp;
            root->lch=NULL;
            root->rch=NULL;
            continue;
        }
        else InsertBst(tmp);
	}
	DFS(root);
	return 0;
}






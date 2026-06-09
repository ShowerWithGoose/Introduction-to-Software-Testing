#include<stdio.h>
#include<malloc.h>
int n;

struct Tree{
    int num;
    struct Tree *left,*right;
}*root;
void insert(struct Tree *now,int num){
    if(num < now->num){
        if(!now->left){
            struct Tree *newson = (struct Tree *)malloc(sizeof(struct Tree));
            newson->left=newson->right=NULL;
            newson->num=num;
            now->left=newson;
        }
        else{
            insert(now->left,num);
        }
    }
    else{
        if(!now->right){
            struct Tree *newson = (struct Tree *)malloc(sizeof(struct Tree));
            newson->left=newson->right=NULL;
            newson->num=num;
            now->right=newson;
        }
        else{
            insert(now->right,num);
        }
    }
}
void print_result(struct Tree * now,int depth){
    if(now->left==NULL&&now->right==NULL) {
        printf("%d %d\n",now->num,depth);
        return;
    }
    if(now->left!=NULL){
        print_result(now->left,depth+1);
    }
    if(now->right!=NULL){
        print_result(now->right,depth+1);
    }
}
int main(){
    scanf("%d",&n);
    root = (struct Tree *)malloc(sizeof(struct Tree));
    root->left=root->right=NULL;
	scanf("%d",&root->num);
    for(int i =0; i < n-1; i++){
        int now ;
        scanf("%d",&now);
        insert(root,now);
    }
    print_result(root,1);
    return 0;
}


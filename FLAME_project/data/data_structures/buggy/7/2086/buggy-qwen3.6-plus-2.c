#include <stdio.h>
#include <stdlib.h>

struct Tree{
    int num;
    struct Tree *left,*right;
};

void insert(struct Tree*,int);
void bfs(struct Tree*,int);
void Tree_free(struct Tree*);

int main(){
    struct Tree *base=calloc(1,sizeof(struct Tree));
    int n,x;

    scanf("%d",&n);
    scanf("%d",&x);
    base->num=x;
    for(int i=1;i<n;i++){
        scanf("%d",&x);
        insert(base,x);
    }

    bfs(base,1);

    Tree_free(base);
    return 0;
}

void insert(struct Tree* base,int x){
    while(1){
        if(x<base->num){
            if(base->left==NULL){
                struct Tree *new_site=calloc(1,sizeof(struct Tree));
                new_site->num=x;
                base->left=new_site;
                break;
            }
            else base=base->left;
        }
        else if(x>base->num){
            if(base->right==NULL){
                struct Tree *new_site=calloc(1,sizeof(struct Tree));
                new_site->num=x;
                base->right=new_site;
                break;
            }
            else base=base->right;
        }else if(x==base->num)break; // @@ The problem states that right child values are greater than or equal to the root. This line breaks the loop when a duplicate value is encountered, effectively ignoring it instead of inserting it into the right subtree as required.
    }
    return;
}

void bfs(struct Tree* base,int n){
    if((base->left==NULL) && (base->right==NULL)){
        printf("%d %d\n",base->num,n);
        return;
    }
    if(base->left!=NULL)bfs(base->left,n+1);
    if(base->right!=NULL)bfs(base->right,n+1);
    return;
}

void Tree_free(struct Tree* base){
    if((base->left==NULL) && (base->right==NULL)){
        free(base);
        return;
    }
    if(base->left!=NULL)Tree_free(base->left);
    if(base->right!=NULL)Tree_free(base->right);
    free(base);
    return;
}
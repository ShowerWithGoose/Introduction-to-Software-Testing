#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Sorttree{
    int data;
    int depth;
    struct Sorttree *left;
    struct Sorttree *right;
}STtree,*sttree;

sttree insertSTtree(sttree p, int item, int depth){
    if(p == NULL){
        p = (sttree)malloc(sizeof(STtree));
        p -> data = item;
        p -> depth = depth;
        p -> left = NULL;
        p -> right = NULL;
    } 
    else if( item < p -> data){
        p -> left = insertSTtree(p -> left, item, depth + 1);
    }
    else if(item >= p -> data){
       p -> right = insertSTtree(p -> right, item, depth + 1);
    }
    else{
//看对相等元素怎么处理
    }
    return p;
}

void btnodeBST(sttree p){
    if(p != NULL){
        btnodeBST(p -> left);
        if(p -> left == NULL && p -> right == NULL){
            printf("%d %d\n",p -> data, p -> depth);
        }
        btnodeBST(p -> right);
    }
}

int main(){
    int n = 0;
    scanf("%d",&n);
    int i = 0;
    int item = 0;
    int depth = 1;
    sttree head = NULL;

    for(i = 0; i < n; i++){
        scanf("%d",&item);
        head = insertSTtree(head,item,1);
    }
    btnodeBST(head);
    return 0;
}

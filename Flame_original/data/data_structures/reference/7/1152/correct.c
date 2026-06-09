#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long

typedef struct node{
    int num;
    struct node* l;
    struct node* r;
}tree;

tree* init_tree(int num){
    tree *tr = (tree*)malloc(sizeof(tree));
    tr->num = num;
    tr->l = NULL;
    tr->r = NULL;
    return tr;
}

tree* insert_tree(tree* tr, int in){//tr = insert_tree(tr, in)
    if(tr == NULL){
        tr = init_tree(in);
        return tr;
    }else if(tr->num > in){
        tr->l = insert_tree(tr->l, in);
    }else if(tr->num < in){
        tr->r = insert_tree(tr->r, in);
    }else{
        tr->r = insert_tree(tr->r, in);
    }
    return tr;
}

tree* search_tree(tree* tr, int in){
    if(tr == NULL){
        return NULL;
    }else if(tr->num > in){
        return search_tree(tr->l, in);
    }else if(tr->num < in){
        return search_tree(tr->r, in);
    }else{
        return tr;
    }
}

void deep_tree(tree* tr, int deep){//(root, 1)
    if(tr->l == NULL && tr->r == NULL){
        printf("%d %d\n", tr->num, deep);
    }
    if(tr->l != NULL){
        deep_tree(tr->l, deep+1);
    }
    if(tr->r != NULL){
        deep_tree(tr->r, deep+1);
    }
    return;
}

int main(){
//    freopen("r.txt","r",stdin);
//    freopen("w.txt","w",stdout);
    tree *tr = (tree*)malloc(sizeof(tree));
    tr = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int num;
        scanf("%d", &num);
        tr = insert_tree(tr, num);
    }
    deep_tree(tr, 1);
    return 0;
}

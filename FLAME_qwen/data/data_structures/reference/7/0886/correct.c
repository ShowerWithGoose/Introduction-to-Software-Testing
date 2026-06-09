//
//  main.c
//  数叶节点遍历
//
//  Created by  on 2022/4/28.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int num;
    int height;
    struct Node *left, *right;
} Basic_tree;
Basic_tree *insert(Basic_tree *gen, int x, int high){
    high++;
    if(gen==NULL){
        gen = (Basic_tree*)malloc(sizeof(Basic_tree));
        gen->num = x;
        gen->left = NULL;
        gen->right = NULL;
        gen->height = high;
    }
    else if(x<gen->num){
        gen->left=insert(gen->left, x, high);
    }
    else
        gen->right=insert(gen->right, x, high);
    return gen;
}
void final(Basic_tree *a){
    if(a==NULL)
        return ;
    else if(a->left==NULL&&a->right==NULL){
        printf("%d %d\n", a->num, a->height);
    }
    final(a->left);
    final(a->right);
}
int main(){
    int i, n, x;
    Basic_tree *gen = NULL;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &x);
        gen = insert(gen, x, 0);
    }
    final(gen);
    return 0;
}


//
//  main.c
//  text9
//
//  Created by  on 2021/9/23.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>

struct node {
    int data;
    struct node *left,*right;
};
typedef struct node type,*typepit;
typepit insert(typepit p,int item){
    if(p==NULL){
        p=(typepit)malloc(sizeof(type));
        p->data=item;
        p->left=p->right=NULL;
    }
    else if(item>=p->data){
        p->right=insert(p->right,item);
    }
    else if(item<p->data){
        p->left=insert(p->left,item);
    }
    return p;
}
void reorder(typepit t,int n){
    if(t!=NULL){
        if(t->left==NULL&&t->right==NULL){
            printf("%d %d\n",t->data,n);
        }
        reorder(t->left,n+1);
        reorder(t->right,n+1);
        free(t);
    }
}
int main() {
    int n;
    int a;
    typepit root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        root=insert(root,a);
    }
    reorder(root,1);
    
    
    
    
    return 0;
}


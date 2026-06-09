//
//  main.c
//  DS5-1
//
//  Created by  on 2022/5/6.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree{
    int data;
  //  int height;
    struct tree *llink,*rlink;
};


struct tree* insertBST(struct tree *p,int d){ //[bug]注意返回的是一个指针*
    if(p==NULL){
        p=(struct tree*)malloc(sizeof(struct tree)+1);
        p->data=d;
        p->llink=NULL;
        p->rlink=NULL;
    }
    else{
        if(d<p->data){
            p->llink=insertBST(p->llink, d);  //注意是you返回值的
        }
        else if(d>=p->data){
            p->rlink=insertBST(p->rlink, d);
        }
        else{}
    }
    return p;
}


int h=1;
void findBST(struct tree *root){
    
    if(root->llink==NULL&&root->rlink==NULL){
       printf("%d %d\n",root->data,h);
        
    }
    else{
        if(root->llink!=NULL){
            h++;
            findBST(root->llink);
            h--;
        }
        if(root->rlink!=NULL){
            h++;
            findBST(root->rlink);
            h--;
        }
    }
    
}

int main() {
    int n;
    int i=0;
    int d;
    struct tree *root=NULL;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&d);
        root=insertBST(root, d);
    }
    findBST(root);
    
    
    return 0;
}




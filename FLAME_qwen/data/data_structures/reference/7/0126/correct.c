#include <stdio.h>
#include<stdlib.h>
typedef struct btnode{
    int data , layer;
    struct btnode *lchild , *rchild;
}btnode , *bttree;

bttree btinsert(bttree s , int a , int l){
    if(s == NULL){
        s = (bttree)malloc(sizeof(btnode));
        s->data = a;
        s->layer = l;
        s->rchild = s->lchild = NULL;
    }
    else{
        if(a < s->data) s->lchild = btinsert(s->lchild, a, l+1);
        else   s->rchild = btinsert(s->rchild, a, l+1);
    }
    return s;
}
void prebttraverse(bttree s){
    if(s == NULL)   return;
    else{
        prebttraverse(s->lchild);
        if(s->lchild == NULL && s->rchild == NULL)
            printf("%d %d\n" , s->data , s->layer);
        prebttraverse(s->rchild);
    }
}
int main(){
    bttree s = NULL;
    int n , tmp , l = 1;
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &tmp);
        s = btinsert(s, tmp, l);
    }
    prebttraverse(s);
    return 0;
}
/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/


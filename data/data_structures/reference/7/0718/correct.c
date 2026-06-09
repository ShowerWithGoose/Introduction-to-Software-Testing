#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct node{
    int date;
    int high;
    struct node *left,*right;
}*BTNodeptr;
BTNodeptr L=NULL;
BTNodeptr insert(BTNodeptr p,int item,int h){
    if(p==NULL){
        p=(BTNodeptr) malloc(sizeof(struct node));
        p->date=item;
        p->left=p->right=NULL;
        p->high=h;
    }
    else if(item<p->date){
        h++;
        p->left= insert(p->left,item,h);
    }
    else if(item>=p->date){
        h++;
        p->right= insert(p->right,item,h);
    }
    return p;
}
void output(BTNodeptr p){
    if(p->right==NULL&&p->left==NULL){
        printf("%d %d\n",p->date,p->high);
    }
    else{
        if(p->left!=NULL)output(p->left);
        if(p->right!=NULL)output(p->right);
    }
    return;
}
int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    int n,i,item;
    BTNodeptr p=NULL;
    scanf("%d",&n);
    scanf("%d",&item);
    p=(BTNodeptr) malloc(sizeof(struct node));
    p->date=item;
    p->left=p->right=NULL;
    p->high=1;
    L=p;
    for(i=1;i<n;i++){
        scanf("%d",&item);
        p= insert(p,item,1);
    }
    output(L);
    return 0;
}



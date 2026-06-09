#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
}BTNode,*BTNodeptr;
BTNodeptr insert(BTNodeptr p,int item){
    if(p==NULL){
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data =item;
        p->left =p->right =NULL;
    }
    else if(item<p->data){
        p->left=insert(p->left ,item);
    }
    else if(item>=p->data ){
        p->right=insert(p->right,item);
    }
    return p;
}
int num=1;
void search(BTNodeptr p){
    //BTNodeptr q=p;
    if(p->left ==NULL&&p->right ==NULL){ // @@ [Missing NULL check for p: if p is NULL (e.g., empty tree or called with a NULL child), this dereference causes a segmentation fault. The reference program checks if(p!=NULL) first.]
        printf("%d %d\n",p->data,num);
    }
    else{
        num++;
        search(p->left ); // @@ [Potentially calls search with a NULL pointer if p->left is NULL, leading to a crash. Should only call if p->left != NULL, or add a NULL check at the beginning of search.]
        search(p->right); // @@ [Same issue as line 30: can pass NULL if p->right is NULL.]
        num--;
    }
}
int main(){
    int n,item,i;
    scanf("%d",&n);
    BTNodeptr root=NULL;
    for(i=0;i<n;i++){
        scanf("%d",&item);
        root=insert(root,item);
    }
    search(root);
    
}
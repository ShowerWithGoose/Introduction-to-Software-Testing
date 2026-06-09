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
    if(p->left ==NULL&&p->right ==NULL){
        printf("%d %d\n",p->data,num);
    }
    else{
        num++;
        search(p->left ); @@ [The function does not check if p->left is NULL before recursing, which can cause a segmentation fault when accessing p->left->left or p->left->right in the next call. Similarly for p->right.]
        search(p->right); @@ [Same issue: no NULL check before recursion leads to undefined behavior on empty subtrees.]
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
    search(root); @@ [If the input n is 0, root will be NULL, and calling search(root) will dereference a NULL pointer in the first line of search(), causing a crash.]
    
}
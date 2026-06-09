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
        search(p->left );
        search(p->right);
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
    search(root); // @@ [The function 'search' may be called with a NULL pointer when the input n is 0, leading to dereferencing a null pointer in 'search'. Also, the height tracking using a global variable 'num' is flawed because it doesn't correctly track the depth during traversal; it assumes a specific order and fails when one subtree is missing.]
    
}
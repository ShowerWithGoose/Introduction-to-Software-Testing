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
} // @@ [The global variable 'num' is used to track height, but it's shared across all recursive calls. This causes incorrect height values because left and right subtree traversals interfere with each other's height tracking. Height should be passed as a parameter instead of using a global variable.]

int main(){
    int n,item,i;
    scanf("%d",&n);
    BTNodeptr root=NULL;
    for(i=0;i<n;i++){
        scanf("%d",&item);
        root=insert(root,item);
    }
    search(root); // @@ [Calling 'search' on an empty tree (if n==0) would dereference a NULL pointer in 'search', causing a runtime error. However, in this test case n=10, so the immediate issue is the incorrect height calculation due to global 'num'. Also, if the root is NULL, 'search' will crash.]
    
}
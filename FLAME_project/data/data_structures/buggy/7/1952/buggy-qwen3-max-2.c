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
        printf("%d %d\n",p->data,num); // @@ [The variable 'num' is a global counter that does not represent the actual height of the current node. It gets incremented and decremented during traversal, but this approach fails to track individual node heights correctly, especially when backtracking affects subsequent branches.]
    }
    else{
        num++; // @@ [Incrementing a global 'num' before traversing children assumes uniform depth progression, but this breaks when traversing right subtrees after returning from left ones, because 'num' is shared across all recursive calls and doesn't reflect per-node height.]
        search(p->left );
        search(p->right);
        num--; // @@ [Decrementing 'num' after recursion assumes perfect symmetry in traversal path, but if one subtree is missing (e.g., only left or only right child), the count becomes incorrect for other leaf nodes. Also, accessing p->left or p->right without checking if they are NULL can cause runtime errors.]
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
    search(root); // @@ [If the tree is empty (n=0), calling search(root) with root=NULL will dereference a null pointer in the first line of search(), causing a runtime error. However, in this test case n=10 so it's not triggered here, but the real issue is in how height is tracked. The main logical error is using a global 'num' instead of passing height as a parameter.]
    
}
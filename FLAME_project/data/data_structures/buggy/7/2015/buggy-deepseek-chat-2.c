#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct Tnode{
    int m;
    struct Tnode* left;
    struct Tnode* right;
}Tnode,*tree;

void bsort(int str[],int len){
    int hold,i,j;
    for(i=0;i<len-1;i++){
    for(j=0;j<len-1-i;j++){
    if(str[j]>str[j+1]){
    hold=str[j];
    str[j]=str[j+1];
    str[j+1]=hold;
}
}    
}
}  

int main(){
    tree t=(tree)malloc(sizeof(Tnode));
    int num[200];
    int len;int i;
    scanf("%d",&len);
    for(i=0;i<len;i++){
        scanf("%d",&num[i]);
    }
    Tnode *p=t;
    Tnode *q;
    t->m=num[0];
    t->left=NULL;
    t->right=NULL;
    for(i=1;i<len;i++){
        p=t;
        while(p!=NULL){
            if(num[i]<p->m){
            q=p;
            p=p->left;
            }
            else{
            q=p;
            p=p->right;
            }
        }
        if(num[i]<q->m){
            q->left=(tree)malloc(sizeof(Tnode));
            p=q->left;
            p->m=num[i];
            p->left=NULL;
            p->right=NULL;
        }
        else if(num[i]>=q->m){
            q->right=(tree)malloc(sizeof(Tnode));
            p=q->right;
            p->m=num[i];
            p->left=NULL;
            p->right=NULL;
        }
    }
    
    
    
    
    
    int dep[200];
    bsort(num,len); // @@ Error: Sorting the array destroys the original insertion order, so the BST structure built earlier does not correspond to the sorted order. The leaf nodes should be identified based on the BST built from the original sequence, not from a sorted array.
    for(i=0;i<len;i++){
        dep[i]=1;
    }
    
    
    
    for(i=0;i<len;i++){
        p=t;
        while(p->m!=num[i]){ // @@ Error: This loop traverses the BST to find each element from the sorted array, but the BST was built from the original unsorted sequence. The traversal may fail to find the element or produce incorrect heights because the BST structure is based on insertion order, not sorted order.
            if(num[i]>=p->m){
                p=p->right;
                dep[i]++;
            }
            else{
                p=p->left;
                dep[i]++;
            }            
        }
            printf("%d %d\n",num[i],dep[i]); // @@ Error: This prints all nodes in sorted order, but the problem requires printing only leaf nodes (nodes with no children) in left-to-right order (which corresponds to the BST's in-order traversal of leaves). The current code prints every node and does not check if it is a leaf.
                
    }
}
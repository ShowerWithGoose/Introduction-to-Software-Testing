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
    tree t=(tree)malloc(sizeof(Tnode)); // @@ [If len is 0, this creates a node with uninitialized data and leads to undefined behavior; also, no check for malloc failure]
    int num[200];
    int len;int i;
    scanf("%d",&len);
    for(i=0;i<len;i++){
        scanf("%d",&num[i]);
    }
    Tnode *p=t;
    Tnode *q;
    t->m=num[0]; // @@ [If len is 0, num[0] is undefined, causing undefined behavior]
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
    bsort(num,len); // @@ [Sorting the input array destroys the original insertion order needed to correctly compute leaf nodes in BST; leaf identification must be based on tree structure, not sorted values]
    for(i=0;i<len;i++){
        dep[i]=1;
    }
    
    
    
    for(i=0;i<len;i++){
        p=t;
        while(p->m!=num[i]){ // @@ [This loop assumes all values are unique; duplicates may cause infinite loop or wrong traversal. Also, after sorting, num[i] may not reflect actual leaf nodes]
            if(num[i]>=p->m){
                p=p->right;
                dep[i]++;
            }
            else{
                p=p->left;
                dep[i]++;
            }            
        }
            printf("%d %d\n",num[i],dep[i]); // @@ [Prints every node (after sorting), not just leaf nodes. Problem requires only leaf nodes in left-to-right (in-order) traversal]
                
    }
}
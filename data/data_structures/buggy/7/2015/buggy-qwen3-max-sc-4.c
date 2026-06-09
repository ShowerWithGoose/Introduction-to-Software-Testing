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
    tree t=(tree)malloc(sizeof(Tnode)); // @@ [t may be used uninitialized if len == 0, but more critically, the program assumes at least one node; however, the main logical error is elsewhere]
    int num[200];
    int len;int i;
    scanf("%d",&len);
    for(i=0;i<len;i++){
        scanf("%d",&num[i]);
    }
    Tnode *p=t;
    Tnode *q;
    t->m=num[0]; // @@ [if len == 0, this accesses num[0] which is invalid; but even if len >= 1, the bigger issue is that the BST construction does not track depth correctly]
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
    bsort(num,len); // @@ [Sorting the input destroys the original insertion order needed to correctly compute depths by traversing the actual BST structure; also, leaf nodes are not all nodes, but only those with no children]
    for(i=0;i<len;i++){
        dep[i]=1;
    }
    
    
    
    for(i=0;i<len;i++){
        p=t;
        while(p->m!=num[i]){ // @@ [This loop assumes all values are unique; duplicates will cause infinite loop or wrong traversal. Also, it recomputes depth by searching from root for each sorted value, which is inefficient and incorrect for identifying leaves]
            if(num[i]>=p->m){
                p=p->right;
                dep[i]++;
            }
            else{
                p=p->left;
                dep[i]++;
            }            
        }
            printf("%d %d\n",num[i],dep[i]); // @@ [Prints every node (after sorting), not just leaf nodes, and in sorted order instead of left-to-right (inorder) traversal of the BST]
                
    }
}
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
    bsort(num,len); // @@ The problem requires outputting leaf nodes in left-to-right order (in-order traversal), not sorted by value. Sorting the input values destroys the original insertion order and structure context needed for correct leaf identification via traversal. Furthermore, simply sorting doesn't identify leaves.
    for(i=0;i<len;i++){
        dep[i]=1;
    }
    
    
    
    for(i=0;i<len;i++){ // @@ This loop iterates through all nodes in sorted order and prints their depth. The problem asks specifically for LEAF nodes only, printed in left-to-right order (which corresponds to in-order traversal for BSTs, or simply checking left-to-right visibility). The current code prints ALL nodes, not just leaves.
        p=t;
        while(p->m!=num[i]){
            if(num[i]>=p->m){
                p=p->right;
                dep[i]++;
            }
            else{
                p=p->left;
                dep[i]++;
            }            
        }
            printf("%d %d\n",num[i],dep[i]); // @@ This prints every node's value and depth. It should only print if the node is a leaf (both left and right children are NULL). Also, the order is wrong (sorted by value instead of left-to-right spatial order/in-order).
                
    }
}
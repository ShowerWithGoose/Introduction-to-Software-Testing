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
    tree t=(tree)malloc(sizeof(Tnode)); // @@ [t is allocated but not checked for NULL; also, if len==0, this leads to undefined behavior later]
    int num[200];
    int len;int i;
    scanf("%d",&len);
    for(i=0;i<len;i++){
        scanf("%d",&num[i]);
    }
    Tnode *p=t;
    Tnode *q;
    t->m=num[0]; // @@ [if len is 0, num[0] is uninitialized and accessing it is undefined behavior]
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
    bsort(num,len); // @@ [sorting the input array destroys the original insertion order needed to correctly compute leaf nodes in left-to-right (in-order) traversal]
    for(i=0;i<len;i++){
        dep[i]=1;
    }
    
    
    
    for(i=0;i<len;i++){
        p=t;
        while(p->m!=num[i]){ // @@ [this loop assumes all values are unique; if duplicates exist, it may never terminate or find wrong node]
            if(num[i]>=p->m){
                p=p->right;
                dep[i]++;
            }
            else{
                p=p->left;
                dep[i]++;
            }            
        }
            printf("%d %d\n",num[i],dep[i]); // @@ [prints every node, not just leaf nodes; also prints in sorted order, not in-order traversal of leaves]
                
    }
}
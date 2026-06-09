#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct TREE{
    int data;
    struct TREE *llink,*rlink;
}*ptree,tree;
void null(ptree root){
    root->llink=NULL;
    root->rlink=NULL;
}
void insert(ptree root,int number){
    ptree q=root;
    int flag=0;
    do{
        if(q->llink==NULL&&q->rlink==NULL){
            if(number<q->data){
                q->llink=(ptree)malloc(sizeof(tree));
                q=q->llink;
                q->data=number;
            }
            else{
                q->rlink=(ptree)malloc(sizeof(tree));
                q=q->rlink;
                q->data=number;         
            }
            flag=1;
            null(q);
        }
        else if(q->llink==NULL&&q->rlink!=NULL){
            if(number<q->data){
                q->llink=(ptree)malloc(sizeof(tree));
                q=q->llink;
                q->data=number;
                flag=1;
                null(q);
            }
            else
                q=q->rlink;
        } 
        else if(q->llink!=NULL&&q->rlink==NULL){
            if(number<q->data)
                q=q->llink;
            else{
                q->rlink=(ptree)malloc(sizeof(tree));
                q=q->rlink;
                q->data=number;
                flag=1; 
                null(q);              
            }       
        }
        else{
            if(number<q->data)
                q=q->llink;
            else
                q=q->rlink;
        }         
    }while(flag==0);
}
void preorder(ptree root,int count){
    count++;
    if(root!=NULL){
        if(root->llink==NULL&&root->rlink==NULL)
            printf("%d %d\n",root->data,count);        
        preorder(root->llink,count);
        preorder(root->rlink,count);
    }
}
int main(){
    int i,n,number;
    ptree root;
    scanf("%d",&n);
    root=(ptree)malloc(sizeof(tree));
    null(root);
    scanf("%d",&root->data);
    for(i=1;i<=n-1;i++){
        scanf("%d",&number);
        insert(root,number);
    }
    preorder(root,0);
    return 0;
}



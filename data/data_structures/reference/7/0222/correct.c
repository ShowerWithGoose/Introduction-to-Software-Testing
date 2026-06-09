#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct TREE{
    int data;
    struct TREE *llink,*rlink;
}*ptree,tree;
void null(ptree p){
    p->llink=NULL;
    p->rlink=NULL;
}
void insert(ptree p,int number){
    ptree q=p;
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
void preorder(ptree p,int count){
    count++;
    if(p!=NULL){
        if(p->llink==NULL&&p->rlink==NULL)
            printf("%d %d\n",p->data,count);        
        preorder(p->llink,count);
        preorder(p->rlink,count);
    }
}
int main(){
    int i,n,number;
    ptree p;
    scanf("%d",&n);
    p=(ptree)malloc(sizeof(tree));
    null(p);
    scanf("%d",&p->data);
    for(i=1;i<=n-1;i++){
        scanf("%d",&number);
        insert(p,number);
    }
    preorder(p,0);
    return 0;
}



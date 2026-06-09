#include<stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
    int number;
    int deep;
    struct node *link[2];
}tree;
tree memory[10000];


int a=0;



tree* create(int num,tree *p,int len){
    
    if(p==NULL){
        p=&memory[a++];
        p->number=num;
        p->deep=len;
        p->link[0]=NULL;
        p->link[1]=NULL;
    }
    else if(num>=p->number){
        p->link[1]=create(num,p->link[1],len+1);
    }
    else if(num<p->number){
        p->link[0]=create(num,p->link[0],len+1);
    }
    return p;
   
    
}
void print(tree *p){
    if(p->link[0]==NULL&&p->link[1]==NULL){
        printf("%d %d\n",p->number,p->deep);
    }
    else{
        if(p->link[0]!=NULL&&p->link[1]!=NULL){
            print(p->link[0]);
            print(p->link[1]);
        }
        else if(p->link[0]==NULL&&p->link[1]!=NULL){
        
            print(p->link[1]);
        }
        else if(p->link[0]!=NULL&&p->link[1]==NULL){
        
            print(p->link[0]);
        }
    }
}
int main(){
    tree *root;
    root=&memory[a++];
    root->link[1]=NULL;
    root->link[0]=NULL;
    root->deep=1;
    int n;
    int num;
    scanf("%d",&n);
    scanf("%d",&num);
    root->number=num;
    while(--n){
        scanf("%d",&num);
        tree *p;
        p=root;
        p=create(num,p,1);
    }
    print(root);
    return 0;
}

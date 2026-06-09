#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


typedef struct node{
    int num;
    int h;
    struct node *left,*right;
}Node,*Nodeptr;
Nodeptr pd(Nodeptr,int,int);
void fw(Nodeptr);

int main(){
    Nodeptr p=NULL;
    int n,i,num;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(p==NULL){
            p=(Nodeptr)malloc(sizeof(Node));
            p->left=p->right=NULL;
            p->num=num;
            p->h=1;
        }
        else {
            pd(p,num,2);
        }
    }
    fw(p);
    return 0;
}

Nodeptr pd(Nodeptr p,int n,int h){
    Nodeptr q;
    if(n>=p->num){
        if(p->right==NULL){
        q=(Nodeptr)malloc(sizeof(Node));
        q->num=n;
        q->h=h;
        q->left=NULL;
        q->right=NULL;
        p->right=q;
        return p;
    }
        else{
            h++;
            return pd(p->right,n,h);
        }
    }
    else if(n<p->num){
        if(p->left==NULL){
        q=(Nodeptr)malloc(sizeof(Node));
        q->num=n;
        q->h=h;
        q->left=NULL;
        q->right=NULL;
        p->left=q;
        return p;
    }
        else{
            h++;
            return pd(p->left,n,h);
        }
    }
    printf("error\n");
    return p;
}

void fw(Nodeptr p){
    if(p!=NULL){
        fw(p->left);
        fw(p->right);
        if((p->left==NULL)&&(p->right==NULL)){
            printf("%d %d\n",p->num,p->h);
        }
    }
}

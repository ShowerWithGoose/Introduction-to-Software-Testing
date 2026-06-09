#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int num;
    struct node *left,*right;
}*tree,*p;
typedef struct node BTNode,*BTNodeptr;
BTNodeptr insertBST(BTNodeptr p,int date){
    if(p==NULL){
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->num=date;
        p->left=p->right=NULL;
    }
    else if(date < p->num){
        p->left=insertBST(p->left,date);
    }
    else if(date >= p->num){
        p->right=insertBST(p->right,date);
    }
    return p;
}
void middleorder(BTNodeptr p,int h){
    if(p!=NULL){
        h++;
        middleorder(p->left,h);
        if(p->left==NULL&&p->right==NULL)
        printf("%d %d\n",p->num,h);
        middleorder(p->right,h);
    }

}

int main(){
    int n,i,date;
    tree=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&date);
        tree=insertBST(tree,date);
    }
    middleorder(tree,0);
    system("pause");
    return 0;
}

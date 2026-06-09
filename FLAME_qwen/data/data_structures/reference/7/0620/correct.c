#include <stdio.h>
#include<stdlib.h>
#include<math.h>
typedef int elem;
typedef struct a{
struct tree* left;
struct tree* right;
elem num;
}tree;

static int pn=0;//现有数量
void start(tree*head){
head->left=NULL;
head->right=NULL;
head->num=0;
}
void intree(tree*p,tree*q){
if(p->num<q->num){
    if(q->left==NULL)
        q->left=p;
        else
            intree(p,q->left);
}
    else if(p->num>=q->num){
        if(q->right==NULL)
            q->right=p;
            else
                intree(p,q->right);
    }
}
void print(tree* p,int d){
    if(p==NULL)
        return;
    if(p->left==NULL&&p->right==NULL)
        printf("%d %d\n",p->num,d);
        else{
            print(p->left,d+1);
            print(p->right,d+1);
        }
}
int main(){
tree* head=(tree*)malloc(sizeof(tree));//固定开头
int n;
scanf("%d",&n);
start(head);
    for(int i=0;i<n;i++){
    elem a;
    scanf("%d",&a);
        if(i==0)
                head->num=a;
            else{
                tree* q=head;//q可变
                tree* p=(tree*)malloc(sizeof(tree));
                p->left=NULL,p->right=NULL;
                p->num=a;//输入
                intree(p,q);
            }
    }
print(head,1);
return 0;
}



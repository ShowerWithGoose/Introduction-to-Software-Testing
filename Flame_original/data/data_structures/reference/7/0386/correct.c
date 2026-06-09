#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define DB double
#define FOR(X,Y,Z)  for(int X = Y;X<Z;X++)  
typedef struct tnode{
    int date;
    struct tnode* lchild;
    struct tnode* rchild;
} Node;
typedef struct tnode* Nodeptr;
int a[100],n; 
Nodeptr head = NULL;
Nodeptr insert(Nodeptr T,int n){
    if(T==NULL){
        T = (Nodeptr)malloc(sizeof(Node));
        T->date = n;
        T->lchild = NULL;
        T->rchild = NULL;

    }
    else if(n < T->date)
    T->lchild=insert(T->lchild,n);
    else
    T->rchild=insert(T->rchild,n);
    return T;
}
int Layer(Nodeptr T, int n){
    Nodeptr stk1[50],p=T;
    int stk2[50],flag,top = -1;
    do{
        while(p!=NULL){
            stk1[++top] = p;
            stk2[top] = 0;
            p = p->lchild;
        }
        p = stk1[top];
        flag = stk2[top--];
        if(flag==0){
            stk1[++top] = p;
            stk2[top] = 1;
            p = p->rchild;
        }
        else{
            if(p->date==n)
            return (top+2);
            p =NULL;
        }
    }while(!(p==NULL&&top==-1));
}
void fuc(Nodeptr T){
    if(T!=NULL){
        fuc(T->lchild);
        if(T->lchild==NULL&&T->rchild==NULL){
        printf("%d %d\n",T->date,Layer(head,T->date));
        }
        fuc(T->rchild);
    }
    
}



int main(){
    //freopen(".in","r",stdin);
    scanf("%d ",&n);
    for(int i = 0;i<n;i++){
    scanf("%d ",&a[i]);
    head = insert(head,a[i]);
    }
    fuc(head);

    return 0;
}




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node* Node;
struct Node{
    int Hight;
    int Element;
    Node Left,Right;
};
Node CreateNode(){
    Node T=malloc(sizeof(struct Node));
    T->Left=T->Right=NULL;
    return T;
}
int IsLeaf(Node T){
    return T->Left==NULL&&T->Right==NULL;
}
void PrintHight(Node T,int h){
    T->Hight=h;
    if(IsLeaf(T)){
        printf("%d %d\n",T->Element,T->Hight);
    }
    if(T->Left!=NULL)PrintHight(T->Left,h+1);
    if(T->Right!=NULL)PrintHight(T->Right,h+1);
}
Node Insert(int x,Node T){
    if(T==NULL){
        T=CreateNode();
        T->Element=x;
        return T;
    }
    else{
        if(x<T->Element)
            T->Left=Insert(x,T->Left);
        else
            T->Right=Insert(x,T->Right);
        return T;
    }
    // int x=Now->Element;
    // if(x<T->Element){
    //     if(T->Left==NULL){
    //         T->Left=Now;
    //     }
    //     else{
    //         Insert(Now,T->Left);
    //     }
    // }
    // else{
    //     if(T->Right==NULL){
    //         T->Left=Now;
    //     }
    //     else{
    //         Insert(Now,T->Right);
    //     }
    // }
}
int main(void){
    int n;
    Node T=NULL;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        // Node New=CreateNode();
        // New->Element=a;
        T=Insert(a,T);
    }
    PrintHight(T,1);
    return 0;
}

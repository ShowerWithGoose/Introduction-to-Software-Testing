#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define S scanf
#define P printf
#define L long long
struct node{
    int data,height;
    struct node *left,*right; 
};
struct node *first;
struct node *build(struct node *root,int len,int t){
    len++;
    if(root==0){
        root=(struct node*)malloc(sizeof(struct node));
        root->data=t;
        root->height=len;
        root->left=root->right=NULL;
        first=root;
    }
    else if(t<root->data) root->left=build(root->left,len,t);
    else root->right=build(root->right,len,t);
    return root;
}
void print(struct node *root){
    if(root!=0){
        if(root->left==NULL&&root->right==NULL)
        P("%d %d\n",root->data,root->height);
        print(root->left);
        print(root->right);
    }
}
int main(){
    int n,len,t;
    struct node *root=NULL;
    S("%d",&n);
    while(S("%d",&t)!=EOF){ // @@ The loop reads all integers including the first one, but the first integer n was already read separately, causing the first data value to be skipped and the loop to read one extra integer beyond the input.
        len=0;
        root=build(root,len,t);
    }
    print(root);
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 typedef struct node
 {
    int data;
    int depth;
    struct node*leftch,*rightch;

 } Tree;
 void chazhao(Tree*root);
 Tree *insert(Tree*root,int val,int deep);
int main()
{
    Tree *root=NULL;
    int n,i,temp,deep=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        root=insert(root,temp,deep);
    }
     chazhao(root);
     return 0;


}
void chazhao(Tree *root)
{
    if(root!=NULL){
        if((root->leftch==NULL)&&(root->rightch==NULL)){
            printf("%d %d\n",root->data,root->depth);
        }
        chazhao(root->leftch);
        chazhao(root->rightch);

    }
}
Tree *insert(Tree *root,int val,int deep)
{
    deep+=1;
    if(root==NULL){
        root=(Tree*)malloc(sizeof(Tree));
        root->data=val;
        root->leftch=NULL;
        root->rightch=NULL;
        root->depth=deep;
    }
    else{
        if(root->data<=val){
            root->rightch=insert(root->rightch,val,deep);
        }
        if(root->data>val){
            root->leftch=insert(root->leftch,val,deep);
        }
    }
    return root;




}


/*
 * @Course: Data Sturctures And Programming
 * @Teacher:
 * @Date: 2022-05-22 14:51:28
 * @LastEditors:
 * @LastEditTime: 2022-05-22 20:23:58
 * @FilePath: \Code\第五次\bst.c
 * @CopyRight:  ©2022 All Rights Reserved
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma pack(8)
typedef struct tree {
  int deep;
  int num;
  struct tree *left;
  struct tree *right;
} tree;
int rootnum=0;
tree *creatpoin(){
   tree *p=(tree *)malloc(sizeof(tree));
   p->deep=0;
  p->num=0;
  p->left=NULL;
  p->right=NULL;
  return p;

}
tree* insert(tree *root, int num,int dep){
   dep++;
   if(root==NULL){
     root=(tree* )malloc(sizeof(tree));
     root->num = num;
     root->deep = dep;
     root->left = NULL;
     root->right = NULL;
     
   }else if(num<root->num){
      root->left= insert(root->left,num,dep);
   }else if(num>=root->num){
      root->right= insert(root->right,num,dep);
   }
   return root;
}
void printnum(tree *root){
if(root!=NULL){
   if(root->left==NULL && root->right==NULL){
      printf("%d %d\n",root->num,root->deep);
   }
      printnum(root->left);
      printnum(root->right);
   }
}
int main(){
   int sum=0,tmp=0;
   scanf("%d",&sum);
   tree *root=NULL;
   for(int i=0;i<sum;i++){
      int dep=0;
      scanf("%d",&tmp);
      if(i==0){
         root=insert(root,tmp,dep);
      }else{
         insert(root,tmp,dep);
      }
   }
   //printf("%d",root->num);
   printnum(root);
}



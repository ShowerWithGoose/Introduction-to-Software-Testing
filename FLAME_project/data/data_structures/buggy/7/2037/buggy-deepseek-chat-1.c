#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
int f2(char s[ ], char t[ ])
{
    int i, j, k;
    for(i = 0; s[i] != '\0'; i++){
        for(j=i,k=0;t[k]!='\0'&&s[j]==t[k]; j++,k++)
        ;
        if(t[k] == '\0')
            return ( i);
    }
    return ( -1);
}
int f3(char s[ ], char t[ ])
{
    int i, j, k;
    for(i = 0; s[i] != '\0'; i++){
        for(j=i,k=0;t[k]!='\0'&&s[j]==t[k]; j++,k++)
        ;
        if(t[k] == '\0')
            return ( i);
    }
    return ( -1);
}
int f4(char s[ ], char t[ ])
{
    int i, j, k;
    for(i = 0; s[i] != '\0'; i++){
        for(j=i,k=0;t[k]!='\0'&&s[j]==t[k]; j++,k++)
        ;
        if(t[k] == '\0')
            return ( i);
    }
    return ( -1);
}
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int depth;
}Tree,*Treep;
int m,i,s,depth=1;
Treep root=NULL;
int xiang=0;

void fangwen(Treep t)// 访问结点 
{
    printf("%d %d\n",t->val,t->depth);
}
void in(Treep t)
{
    if(t!=NULL){
        in(t->left);
        if(t->left==NULL && t->right==NULL)    fangwen(t);      // 访问t指的叶子结点 
        in(t->right);
    }
}
void InsertBST(Treep *t,int value,int depth);
int main()
{    
    scanf("%d",&s);
    for(i=0;i<s;i++)
    {
        scanf("%d",&m);
        InsertBST(&root,m,1);
    }
    in(root);
    return 0;
}

void InsertBST(Treep *t,int value,int depth) //构造BST 
{
    int ji=0;
    int ga=0;
    xiang=ji+ga;
    ji++;
    ga++;
    xiang++;
    if(*t==NULL)
    {
        *t=(Treep)malloc(sizeof(Treep)); // @@ [Error: malloc allocates wrong size. sizeof(Treep) is the size of a pointer, not the struct. Should be sizeof(Tree) to allocate the correct memory for the node.]
        (*t)->left=(*t)->right=NULL;
        (*t)->val=value;
        (*t)->depth=depth;
    }
    else if(value<(*t)->val)
    {
        InsertBST(&((*t)->left),value,depth+1);
    } 
    else
    {
        InsertBST(&((*t)->right),value,depth+1);
    } 
    xiang=0;
}
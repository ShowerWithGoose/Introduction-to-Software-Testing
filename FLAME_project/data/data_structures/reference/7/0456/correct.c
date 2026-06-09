#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
struct shu{
 int num;
 int high;
 struct shu *left,*right;
}tree;

struct shu *build(struct shu *root,int k,int len)
{
    len++;
    if(root==NULL)
        {
            root=(struct shu*)malloc(sizeof(struct shu*));
            root->num=k;
            root->left==NULL;
            root->right==NULL;
            root->high=len;
        }
        else if(k<root->num)
        {
            root->left=build(root->left,k,len);
        }
        else if(k>=root->num)
        {
            root->right=build(root->right,k,len);
        }
        return root;
};
struct shu pri(struct shu *root)
{
    if(root)
    {
    if(root->left==NULL&&root->right==NULL)
    {
        printf("%d %d\n",root->num,root->high);
    }
    pri(root->left);
    pri(root->right);}
}
int main()
{
    int n;
    int i,k;
    struct shu *root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        int len=0;
        root=build(root, k,len);
    }
   pri(root);
    return 0;
}


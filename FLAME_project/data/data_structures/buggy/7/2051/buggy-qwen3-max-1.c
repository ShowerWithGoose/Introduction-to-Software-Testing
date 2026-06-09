#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef int Datatype;
struct node {
    Datatype data;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item);
BTNodeptr  insertBST(BTNodeptr p, Datatype item)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
    } 
    else if( item < p->data)
        p->left = insertBST(p->left, item);
    else if( item > p->data)
       p->right = insertBST(p->right,item);
    else   
    //    do-something; //树中存在该元素
    return p;
} 

BTNodeptr searchroot(BTNodeptr p, Datatype item){
    if(p == NULL || p->data == item)
        return p;
    if(item < p->data)
        return searchroot(p->left, item);
    else
        return searchroot(p->right, item);
}

BTNodeptr printLeaf(BTNodeptr p){
    int i=0;
    if(p != NULL){
        if(p->left == NULL && p->right == NULL)
            printf("%d %d\n", p->data,i);
        else
            {i++;
            printLeaf(p->left);
            printLeaf(p->right);}
    }
}

 typedef struct TreeNode { 
    int data; 
    int height; 
    struct TreeNode *left; 
    struct TreeNode *right; 
    } TreeNode;

 TreeNode* createNode(int value) { 
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); 
    newNode->data = value; 
    newNode->height = 1; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
}

void insert(TreeNode** root, int value, int height) {
    if (*root == NULL) {
        *root = createNode(value);
        (*root)->height = height;
    } else {
        if (value < (*root)->data) {
            insert(&((*root)->left), value, height + 1);
        } else {
            insert(&((*root)->right), value, height + 1);
        }
    }
}

 void printLeafNodes(TreeNode* root) { 
    
    if (root == NULL) { 
        return; 
        } 
    if (root->left == NULL && root->right == NULL) { 
        printf("%d %d\n", root->data, root->height); 
        }
    printLeafNodes(root->left); 
    printLeafNodes(root->right); 
    }

int main()
{
    // int n,i, item;
    // scanf("%d", &n);
    // BTNodeptr  root=NULL;
    // for(i=0; i<n; i++){ 
    //      scanf("%d", &item);
    //      root = insertBST(root, item);
    //  }
    // printLeaf(root);
    // return 0;
    int n;
    scanf("%d", &n);
    TreeNode* root = NULL;

for (int i = 0; i < n; i++) {
    int value;
    scanf("%d", &value);
    insert(&root, value); // @@ [The function 'insert' is called with only two arguments, but it is defined to take three arguments: (TreeNode**, int, int). The missing third argument 'height' causes a compilation error.]
}

printLeafNodes(root);

return 0;
}
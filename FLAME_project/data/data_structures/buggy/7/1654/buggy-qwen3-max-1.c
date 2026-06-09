#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
struct node
{
    int num;
    int high;
    struct node *left, *right;
};
typedef struct node search, *searchptr;
searchptr insert(searchptr, int,int);
void perorder(searchptr);
void perorder1(searchptr);
int main()
{
    int n;
    scanf("%d", &n);
    searchptr root = NULL;
    for (int i = n; i > 0; i--)
    {
        int item = 0;
        int h=1;
        scanf("%d", &item);
        root = insert(root, item,h);
    }
    perorder(root);
    perorder1(root); // @@ [This function prints all nodes in-order, but the problem only requires leaf nodes. It causes extra output.]
    return 0;
}
searchptr insert(searchptr p, int item,int h)
{
    if (p == NULL)
    {
        p = (searchptr)malloc(sizeof(search));
        p->num = item;
        p->high=h;
        p->left = p->right = NULL;
    }
    else if(item<p->num){
        p->left=insert(p->left,item,++h); // @@ [Using pre-increment on h modifies the local variable h, which affects the right subtree call if it occurs. This leads to incorrect height calculation.]
    }
    else if(item>=p->num){
        p->right=insert(p->right,item,++h); // @@ [Same issue: h was already incremented in the left branch or here, causing wrong height values due to shared h variable across recursive calls.]
    }
    else{
        printf("sorry");
    }
    return p;
}
void perorder(searchptr r){
    if(r!=NULL){
        if(r->left==NULL&&r->right==NULL){
            printf("%d %d\n",r->num,r->high);
        }
        perorder(r->left);
        perorder(r->right);
    }
}
void perorder1(searchptr r){
    if(r!=NULL){
        perorder1(r->left);
        printf("%d %d\n",r->num,r->high);
        perorder1(r->right);
    }
}
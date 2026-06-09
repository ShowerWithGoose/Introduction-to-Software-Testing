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
    perorder1(root); // @@ [This function call prints all nodes in-order, which is not required by the problem. The problem only asks to print leaf nodes from left to right, which perorder already does. This extra output causes duplicate or incorrect lines.]
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
        p->left=insert(p->left,item,++h); // @@ [Using ++h modifies h for the current call, which affects the subsequent right subtree insertion if it were to happen in the same call. However, more critically, passing h by value with pre-increment leads to incorrect height calculation because the same incremented h is reused in both left and right paths incorrectly due to order of evaluation and shared variable usage. Also, height should be computed as parent's height + 1, but this approach mutates h before passing.]
    }
    else if(item>=p->num){
        p->right=insert(p->right,item,++h); // @@ [Same issue as above: using ++h here after possibly incrementing it in the left branch leads to incorrect height values. Moreover, since h is passed by value, the correct way is to pass h+1 instead of modifying h with ++.]
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
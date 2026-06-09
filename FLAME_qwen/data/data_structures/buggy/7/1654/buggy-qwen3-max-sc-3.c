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
    perorder1(root); // @@ [The problem only requires printing leaf nodes in left-to-right (in-order) traversal, but this extra function call prints all nodes in in-order, causing incorrect extra output.]
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
        p->left=insert(p->left,item,++h); // @@ [Using pre-increment (++h) modifies h and passes the incremented value, but the same h is reused in the next condition; also, height should be passed as h+1 without modifying h to avoid double increment when both left and right are evaluated.]
    }
    else if(item>=p->num){
        p->right=insert(p->right,item,++h); // @@ [Same issue: ++h uses already incremented h from the previous condition if it was executed, leading to incorrect height calculation. Should pass h+1 instead of using ++h.]
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
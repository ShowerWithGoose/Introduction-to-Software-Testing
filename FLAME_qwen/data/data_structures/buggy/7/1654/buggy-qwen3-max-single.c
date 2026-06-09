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
    perorder1(root); // @@ [The problem only requires printing leaf nodes in left-to-right order once. This extra traversal (perorder1) prints all nodes in-order, which is not part of the expected output and causes incorrect output format.]
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
        p->left=insert(p->left,item,++h); // @@ [Using ++h modifies h before the recursive call, but the same modified h is then used in the next condition (else if). This leads to incorrect height calculation because h is incremented twice when both left and right paths are considered in different calls. Also, passing h by value should use h+1 instead of ++h to avoid side effects.]
    }
    else if(item>=p->num){
        p->right=insert(p->right,item,++h); // @@ [Same issue as above: ++h uses pre-increment on a local copy, but since h was already incremented in the previous condition (if taken), or due to multiple increments across recursive paths, the height becomes incorrect. Should pass h+1 instead.]
    }
    else{
        printf("sorry"); // @@ [This branch is unreachable because all cases (item < p->num and item >= p->num) are already covered. It's logically redundant and unnecessary.]
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
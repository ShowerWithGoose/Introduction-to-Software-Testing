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
    perorder1(root); // @@ [The problem only requires printing leaf nodes in left-to-right order once. This extra traversal prints all nodes in-order, which is incorrect and causes extra output.]
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
        p->left=insert(p->left,item,++h); // @@ [Using ++h modifies h for the right subtree call if it were to happen; but more critically, passing ++h changes the height incorrectly because the same incremented h is used in recursive calls. Height should be passed as h+1 without modifying h.]
    }
    else if(item>=p->num){
        p->right=insert(p->right,item,++h); // @@ [Same issue: using ++h after possibly incrementing it in the left branch leads to incorrect height calculation. Also, if both left and right were called (which they aren't in a single path), this would be problematic. But even in isolation, reusing ++h on the same variable across conditions is error-prone. The correct approach is to pass h+1 directly.]
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
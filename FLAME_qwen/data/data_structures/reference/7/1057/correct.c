#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
//#define MAXN 120
// define mst(s) memset(s,0,sizeof(s))
typedef struct node {
    int num;
    struct node* llink,* rlink;
} tree;
int h;
void LDR(tree* root);
int main(void) {
    //freopen("in.txt","r",stdin);
    int i,j,k,n,m;
    tree* root,* curt,* nxt,* lst;
    scanf("%d",&n);
    for(i = 1; i <= n; i++) {
        scanf("%d",&m);
        if(i == 1) {
            root = ( tree* )malloc(sizeof(tree));
            root->llink = root->rlink = 0;
            root->num = m;
        } else {
            while(1) {
                if(m < curt->num) { // in the left
                    if(curt->llink) { // not null
                        curt = curt->llink;
                    } else { // null
                        curt->llink = ( tree* )malloc(sizeof(tree));
                        curt->llink->num = m;
                        curt->llink->llink = curt->llink->rlink = 0;
                        break;
                    }
                } else { // in the right
                    if(curt->rlink) {
                        curt = curt->rlink;
                    } else {
                        curt->rlink = ( tree* )malloc(sizeof(tree));
                        curt = curt->rlink;
                        curt->num = m;
                        curt->llink = curt->rlink = 0;
                        break;
                    }
                }
            }
        }
        curt=root;
    }
    //中序遍历
    h=1;
    LDR(root);

    return 0;
}

void LDR(tree* root) {
    if(!root->llink&&!root->rlink) {//leaf
        printf("%d %d\n",root->num,h);
    } else {
        if(root->llink) {
            h++;
            LDR(root->llink);
        } else;
        if(root->rlink) {
            h++;
            LDR(root->rlink);
        }
    }
    h--;
    return;
}



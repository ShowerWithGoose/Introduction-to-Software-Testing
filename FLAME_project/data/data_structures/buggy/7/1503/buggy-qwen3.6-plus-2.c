#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
typedef struct dian {
    int num;
    struct dian* left;
    struct dian* right;
    int flag;
}node;
int n = 0,co=1;
int path = 0;
node* head;
node* p, * q;
node* insert(int a, struct dian* root) {
    if (root ==  NULL) {
        struct dian* tmp = (struct dian*)malloc(sizeof(struct dian));
        tmp->left = tmp->right = NULL;
        tmp->num = a;
        tmp->flag = co;
        root = tmp;
        co = 1;
    }
    if (a >root->num) {
        root->right=insert(a, root->right);
        co++;
    }
    
     if (a < root->num) { // @@ The condition should be 'a <= root->num' or handled in an else-if block to match the problem description where right child is greater than or equal. Currently, if a == root->num, it falls through and does nothing, effectively ignoring duplicate values which should go to the right.
        root->left=insert(a, root->left);
        co++;
    }
     return root;
    
}
void put(int count,node* p) {
    int c;
    if (p->left == NULL && p->right == NULL) {
        printf("%d %d\n", p->num,count);
    }
     if (p->left != NULL) {
        c=count+1;
        put(c,p->left);
    }
     if (p->right != NULL) {
        c=count+1;
        put(c,p->right);
    }
}
int main() {    
    scanf("%d", &n);
    scanf("%d", &path);
    n--;
    head = p =(node*) malloc(sizeof(node));
    p->num = path;
    p->left = NULL;
    p->right = NULL;
    while (n--) {
        scanf("%d", &path);
       head= insert(path, head);
    }
    put(1,head);
    return 0;
}
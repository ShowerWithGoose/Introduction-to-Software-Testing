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
        co = 1; @@ [The global variable 'co' is used to track height, but it's incorrectly shared across all recursive calls and branches, leading to wrong height assignment. Height should be passed as a parameter like in the reference program.]
    }
    if (a >root->num) {
        root->right=insert(a, root->right);
        co++; @@ [Incrementing 'co' after recursive call is logically incorrect. The height for the new node was already set during its creation using the current 'co', but then 'co' is modified globally affecting other branches.]
    }
    
     if (a < root->num) {
        root->left=insert(a, root->left);
        co++; @@ [Same issue as above: global 'co' is being mutated during traversal, which corrupts height calculations for other nodes.]
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
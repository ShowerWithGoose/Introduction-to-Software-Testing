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
        tmp->flag = co; // @@ Global variable 'co' is misused for height tracking; height should be computed during traversal, not stored via a global counter.
        root = tmp;
        co = 1; // @@ Incorrectly resets the global counter, which corrupts height tracking for subsequent insertions.
    }
    if (a >root->num) { // @@ Condition should be 'a >= root->num' per problem spec (right child >= root). Also, using 'if' instead of 'else if' causes logical flow issues.
        root->right=insert(a, root->right);
        co++; // @@ Incrementing a global variable does not correctly track the depth/height of the current node.
    }

     if (a < root->num) { // @@ Should be 'else' to correctly route values equal to the root to the right child and avoid redundant checks.
        root->left=insert(a, root->left);
        co++; // @@ Incrementing a global variable does not correctly track the depth/height of the current node.
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
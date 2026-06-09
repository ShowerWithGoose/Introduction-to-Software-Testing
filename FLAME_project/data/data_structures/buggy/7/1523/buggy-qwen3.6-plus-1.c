#include <stdio.h>
struct node {
    int num;
    int deep;
    struct node *left,*right;
};
typedef struct node *bpn;
bpn root,temp;
bpn que[100],ans[100];
int main() {
    int n,a,b;
    root=(bpn)malloc(sizeof(bpn)); // @@ [Error 1: malloc size is incorrect. sizeof(bpn) allocates space for a pointer (4 or 8 bytes), not the struct node. Should be sizeof(struct node). This leads to memory corruption.]
    temp=(bpn)malloc(sizeof(bpn)); // @@ [Error 2: Same as above, incorrect malloc size for temp.]
    scanf("%d %d",&n,&a);
    root->num=a;
    root->left=NULL;
    root->right=NULL;
    root->deep=1; // @@ [Error 3: The depth of the root node is not initialized. It should be 1. Without this, the depth calculation for subsequent nodes or output will be wrong/garbage.]
    que[0]=root;
    for(int i=1; i<n; i++) {
        int flag=2;
        bpn p;
        p=(bpn)malloc(sizeof(bpn)); // @@ [Error 4: Incorrect malloc size for new node p. Should be sizeof(struct node).]
        scanf("%d",&b);
        p->num=b;
        p->left=NULL; // @@ [Error 5: The left and right children of the new node p are not initialized to NULL before insertion logic. Although they are set later in the insertion block, if the logic fails or changes, this is risky. More importantly, the insertion logic below is flawed.]
        p->right=NULL;
        do {
            if(p->num<root->num)
                if(root->left==NULL) {
                    root->left=(bpn)malloc(sizeof(bpn)); // @@ [Error 6: Logic Error. A new node is allocated here, but then immediately overwritten by 'root->left=p'. This causes a memory leak. Also, the malloc size is wrong.]
                    root->left=p;
                    root->left->deep=flag;
                    root->left->left=NULL;
                    root->left->right=NULL;
                    que[i]=p;
                    break;
                } else {
                    root=root->left;
                    flag++;
                }
            if(p->num>=root->num) // @@ [Error 7: Logic Error. This 'if' should be an 'else if' or part of an else block. If the first 'if' (p->num < root->num) was true but root->left was NOT NULL, we moved root to left. Now we check this condition against the NEW root. However, if the first 'if' was false (p->num >= root->num), we enter this block. But if the first 'if' was true and we went into the 'else' (moving root), we fall through to this check as well. This double-checking with updated 'root' is logically messy and potentially incorrect depending on intent. Standard BST insertion uses if/else.]
                if(root->right==NULL) {
                    root->right=(bpn)malloc(sizeof(bpn)); // @@ [Error 8: Logic Error. Similar to Error 6, unnecessary malloc causing leak and wrong size.]
                    root->right=p;
                    root->right->deep=flag;
                    root->right->left=NULL;
                    root->right->right=NULL;
                    que[i]=p;
                    break;
                } else {
                    root=root->right;
                    flag++;
                }
        } while(1);
        root=que[0];
    }
    int n1=0;
    for(int i=0; i<n; i++)
        if(que[i]->left==NULL&&que[i]->right==NULL) {
            ans[n1]=que[i];
            n1++;
        }
//    for(int i=0; i<n1; i++)
//        printf("%d %d %d??\n",ans[i]->num,ans[i]->deep,n1);
    for(int i=0; i<n1; i++)
        for(int j=0; j+1<n1; j++)
            if(ans[j]->num>ans[j+1]->num) {
                temp=ans[j+1];
                ans[j+1]=ans[j];
                ans[j]=temp;
            }
    for(int i=0; i<n1; i++)
        printf("%d %d\n",ans[i]->num,ans[i]->deep);
    return 0;
}
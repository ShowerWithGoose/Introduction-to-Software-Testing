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
    root->deep=1; // @@ [Error 3: The depth of the root node is not initialized. It should be 1 according to the problem description. Uninitialized memory leads to undefined output (like 0 in the bug report).]
    que[0]=root;
    for(int i=1; i<n; i++) {
        int flag=2;
        bpn p;
        p=(bpn)malloc(sizeof(bpn)); // @@ [Error 4: Incorrect malloc size for new node p. Should be sizeof(struct node).]
        scanf("%d",&b);
        p->num=b;
        p->deep=flag; // @@ [Error 5: The depth of the new node p is not set here. Although flag is 2, it might change during traversal. More importantly, the logic below assigns depth to the *parent's* child pointer which is overwritten, see Error 6 & 7.]
        do {
            if(p->num<root->num)
                if(root->left==NULL) {
                    root->left=(bpn)malloc(sizeof(bpn)); // @@ [Error 6: Logic Error. A new node is allocated here, but then immediately overwritten by `root->left=p` on the next line. This causes a memory leak and potentially confusing state. The intention was likely just to assign p.]
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
            if(p->num>=root->num)
                if(root->right==NULL) {
                    root->right=(bpn)malloc(sizeof(bpn)); // @@ [Error 7: Logic Error. Same as Error 6. Unnecessary allocation before assignment.]
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
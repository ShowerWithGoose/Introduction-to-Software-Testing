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
    root=(bpn)malloc(sizeof(bpn)); // @@ [Incorrect allocation size: should be sizeof(struct node), not sizeof(bpn). sizeof(bpn) is pointer size, leading to insufficient memory and undefined behavior.]
    temp=(bpn)malloc(sizeof(bpn)); // @@ [Same error: incorrect allocation size; should be sizeof(struct node).]
    scanf("%d %d",&n,&a); // @@ [Input format mismatch: problem expects first integer n, then next line has n integers. This reads n and first value a from same line.]
    root->num=a;
    root->left=NULL;
    root->right=NULL;
    que[0]=root;
    for(int i=1; i<n; i++) {
        int flag=2;
        bpn p;
        p=(bpn)malloc(sizeof(bpn)); // @@ [Incorrect allocation size again: should be sizeof(struct node).]
        scanf("%d",&b);
        p->num=b;
        do {
            if(p->num<root->num)
                if(root->left==NULL) {
                    root->left=(bpn)malloc(sizeof(bpn)); // @@ [Incorrect allocation size and logic error: overwrites root->left with new allocated memory then immediately assigns p, leaking memory and corrupting structure.]
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
            if(p->num>=root->num) // @@ [Logic error: after moving root in left branch, this condition may still execute in same loop iteration causing inconsistent traversal. Should use else if.]
                if(root->right==NULL) {
                    root->right=(bpn)malloc(sizeof(bpn)); // @@ [Same allocation and assignment error as left branch.]
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
        root=que[0]; // @@ [Restoring root by assignment loses original tree structure modifications because que[0] was never updated after initial assignment.]
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
            if(ans[j]->num>ans[j+1]->num) { // @@ [Output order requirement is left-to-right (in-order traversal), not sorted by value. Sorting by value violates problem specification.]
                temp=ans[j+1];
                ans[j+1]=ans[j];
                ans[j]=temp;
            }
    for(int i=0; i<n1; i++)
        printf("%d %d\n",ans[i]->num,ans[i]->deep);
    return 0;
}
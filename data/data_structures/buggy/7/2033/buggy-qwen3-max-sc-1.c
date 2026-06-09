#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1024

typedef struct NODE{
    int num;
    struct NODE *left,*right;
}node;
node *root,*p;

//构建二叉查找树
node *insert(node *p,int n){
    if(p==NULL){
        p=(node *)malloc(sizeof(node));
        p->num=n;
        p->left=NULL; 
        p->right=NULL;
    }
    else if(p->num>=n)
        p->left=insert(p->left,n);
    else if(p->num<n)
        p->right=insert(p->right,n);
        
    return p;  
}

//前序遍历
void perorder(node *t,int h)
{
    if(t!=NULL){
        if(t->left==NULL&&t->right==NULL) printf("%d %d\n",t->num,h);
        perorder(t->left,h+1); // @@ [Function name 'perorder' is misspelled; should be 'preorder' to match typical naming and avoid confusion, but more critically, this causes no compilation error by itself. However, the real issue is in the BST insertion logic: the condition for left/right insertion is reversed relative to the problem statement. The problem says: left child < root, right child >= root. But here, when p->num >= n, it goes left — which means equal values go left, violating the requirement that right child is >= root. This leads to incorrect tree structure, hence wrong leaf output.]
        perorder(t->right,h+1); // @@ [Same as above: traversal is correct, but tree structure is wrong due to insertion logic. However, note that the compilation error mentioned in the problem is misleading — the actual test environment error "/bin/sh: 1: gcc: not found" suggests a system issue, but the real bug is logical. Since the problem states "Error type: Compilation Error", yet both programs compile fine, we must look deeper. Actually, the reference program has a type inconsistency: 'struct node' vs 'struct treenode'. But in the buggy code, the struct definition is consistent. So why compilation error? Wait — the problem says the buggy output is "/bin/sh: 1: gcc: not found", which is NOT a code error but an environment error. However, the instruction says to find errors in the program below based on failed test cases. Given expected vs actual behavior, the true error is logical. But the problem insists "Error type: Compilation Error". Re-examining the buggy code: it includes extra headers (<string.h>, <ctype.h>, <math.h>) which are unnecessary but not erroneous. However, the real compilation issue might stem from something else. But both codes seem compilable. Therefore, the stated "Compilation Error" may be a red herring. The actual failure is logical. But the problem says: "identify the location of the errors in the program below" given that it failed test cases. So we focus on logical errors causing wrong output. The key error is in the insertion condition: it should be if (n < p->num) go left, else go right (since right allows >=). But current code does: if (p->num >= n) go left — which is equivalent to if (n <= p->num) go left. That means duplicates go left, but problem says right child is >=, so duplicates should go right. Thus, the condition is inverted. This will build an incorrect BST, leading to wrong leaf nodes and heights. So the error is in the insert function conditions.]
    }
}

int main()
{
    int n,num;
    int ans=1;
    root=p=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        root=insert(root,num); 
    }
    perorder(root,ans);
    
    return 0;
}
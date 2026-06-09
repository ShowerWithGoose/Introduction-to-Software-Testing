#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef int Datatype;
struct node
 {
    Datatype data;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr root=NULL;
int  heightTree(BTNodeptr s,BTNodeptr p)
{   int d=1;
    int j=p->data;
    if (s== NULL) 
    return 0; 
    else
    {while(s!=p&&s!=NULL)
    { d++; 
      if(j>=s->data)
      s=s->right;     
      else if(j<s->data) 
      s=s->left;           
    }   
    return d; 
   }
 }
void  inorder(BTNodeptr t)
{
      if(t!=NULL)
      {
             inorder(t->left);
             if(t->left==NULL&&t->right==NULL)
             printf("%d %d\n",t->data,heightTree(root,t));   
             inorder(t->right);
    }
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item)
{
    if(p == NULL)
    {
        p =(BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left =p->right=NULL;
    } 
    else if( item<p->data)
        p->left=insertBST(p->left, item);
    else if( item>=p->data)
        p->right=insertBST(p->right,item);
    else
    return p; // @@ [This 'else return p;' is unreachable and unnecessary. More critically, the function lacks a return statement in all control paths: if none of the conditions match (which shouldn't happen logically), the function ends without returning a value, causing undefined behavior. However, the main issue causing incorrect output is the height calculation logic, not compilation. But note: the reported error was "Compilation Error: gcc not found", which is environment-related, not code-related. However, assuming the real issue is logical (since gcc-not-found is not a code bug), the actual bugs are: (1) heightTree assumes the tree is traversed from root to node using BST property, but if duplicates exist and were inserted to the right, and later a duplicate is searched, the path may not match the actual insertion path if intermediate nodes have same values. But more importantly, (2) the heightTree function starts with d=1 and increments as it moves down, but when s==p immediately (i.e., root is the leaf), it returns d=1 without entering the loop — that seems correct. However, the real critical bug is that heightTree dereferences p->data without checking if p is NULL. But in inorder, we only call heightTree on leaf nodes (t != NULL), so p is not NULL. So why wrong output? Let's reconsider: the problem says root height is 1. In the reference program, during inorder traversal, they pass current height as argument (starting at 1 and incrementing on recursion). In this buggy program, heightTree tries to recompute height by walking from root to the node. That approach is valid only if the path taken matches the actual structure. However, the logic in heightTree uses j = p->data and then compares j with s->data to decide direction. But if there are duplicate values, and the actual node p is in the left subtree of some equal-value ancestor (which shouldn't happen because insertion puts >= to right), but wait: insertion puts >= to right, so all duplicates go right. So when searching for p->data, starting from root, you should follow the same path as insertion. So that part might be okay. BUT: what if multiple nodes have same value? Then when searching for a specific node p by its data value, you might end up at a different node with same value! That’s the bug! heightTree uses the data value to traverse, but if there are duplicates, it may not reach the intended node p, and either loop infinitely or stop at wrong node or crash. For example, insert 5, then 5 again. Now two nodes with 5: root and root->right. When computing height of root->right (a leaf), heightTree starts at root (s=root), j = 5 (p->data=5). Compare j (5) >= s->data (5) → go right. Now s = root->right, which equals p → exit loop, return d=2. That works. But what if tree is: insert 5, then 3, then 5. Now root=5, left=3, right=5 (leaf). When computing height of right leaf (value 5), j=5. Start at root (5): 5>=5 → go right → s = right node == p → d=2. OK. Another case: insert 5, 5, 5. Tree: root=5, right=5, right->right=5. For the deepest leaf (third 5), j=5. Start root: 5>=5 → right (d=2); now s=node2 (5): 5>=5 → right (d=3); s=node3 == p → return 3. Correct. So duplicates may not break it. Then why wrong output? Let's look at another issue: the heightTree function initializes d=1, then enters loop only if s != p. If the node is root (s == p initially), it skips loop and returns 1 — correct. So height calculation seems okay. But wait: the problem says "from left to right, output the values and heights of all the leaf nodes". The inorder traversal does left-to-right (inorder gives sorted order for BST, which is left-to-right in tree structure). So traversal order is correct. Then what's wrong? Look at insertBST: the last 'else return p;' is after 'else if (item >= p->data) ...'. The 'else' will never be executed because any item is either < or >=. So that 'else' is dead code. But more importantly, the function does not return p in the cases where it recurses! Look: in the 'else if (item < p->data)' branch, it assigns p->left = insertBST(...), but then falls through without returning p. Similarly for the 'else if (item >= ...)'. Only the base case (p==NULL) and the dead 'else' return something. So the function has no return statement for the recursive cases! This causes undefined behavior — likely returning garbage, so the tree structure becomes corrupted. THIS IS THE CRITICAL BUG. The function insertBST must return p in all non-NULL cases. The reference program does 'return p;' at the end. Here, after setting p->left or p->right, it doesn't return p. So the function ends without a return, which is undefined behavior (and in practice, may return whatever was in the return register, often the result of the last function call, which is wrong). This will cause the tree to be built incorrectly, leading to wrong leaves or crashes. So the error is missing 'return p;' at the end of insertBST.
} 

int main()
{ 
    int i,n,item;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    { 
        scanf("%d",&item);
        root = insertBST(root,item);
     }
    inorder(root); 
    return 0;
}
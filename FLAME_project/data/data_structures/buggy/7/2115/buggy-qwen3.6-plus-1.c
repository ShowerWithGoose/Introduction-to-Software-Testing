#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    int data;
    int height;
    struct node *left, *right,*father;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr insertBST(BTNodeptr p,BTNodeptr fa, int item)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->father=fa;
        p->data = item;
        p->left = p->right = NULL;
        p->height=fa->height+1;
    } 
    else if( item <= p->data) // @@ The problem states left child is less than root, right child is greater than or equal. This condition puts equal items to the left, which is incorrect. It should be item < p->data for left.
        p->left = insertBST(p->left,p, item);
    else 
       p->right = insertBST(p->right,p,item);
    return p;
}
void  preorder(BTNodeptr t)
{
      if(t!=NULL){
            if(t->left==NULL&&t->right==NULL)
            {
                printf("%d %d\n",t->data,t->height);
            }
             preorder(t->left);
             preorder(t->right);
       }
}

int main()
{
    int n,item;
    scanf("%d",&n); 
    BTNodeptr root=NULL;
    BTNodeptr head=root; // @@ head is initialized to NULL. If n > 0, the first node's father is set to NULL. In insertBST, when creating a new node, fa->height is accessed. If fa is NULL (for the root's children if root was passed as head which is NULL? No, root is created separately). However, look at the loop: root = insertBST(root, head, item). head is NULL. So for every insertion, the 'fa' passed is NULL. Inside insertBST, if p is not NULL, it recurses. If p is NULL, it tries to access fa->height. Since head is NULL and passed as fa, this will cause a segmentation fault or undefined behavior when trying to access NULL->height. The reference program calculates height during traversal or stores it correctly. Here, the height calculation relies on the parent's height. The parent pointer passed is always 'head' which is NULL. This is a major logical error. The second argument to insertBST should be the actual parent of the current node being inserted, which changes during recursion. But here 'head' (NULL) is passed constantly. Wait, looking closer at insertBST signature: insertBST(p, fa, item). In the recursive calls: insertBST(p->left, p, item). Here p is passed as fa. This is correct for recursive steps. BUT, in main: root = insertBST(root, head, item). head is NULL. So for the first call, if root is not NULL, it goes to else. If it goes to left/right, it passes p (root) as fa. That part is okay. The problem is when a new node is created. p->height = fa->height + 1. If the very first node (root) is created in main, its height is set to 1. Its father is head (NULL). Then for subsequent nodes, insertBST is called with fa=head (NULL). If the tree is empty (p==NULL), it accesses fa->height. But p is root (not NULL) after first iteration. So it goes to else. Then recursively calls insertBST with p->left or p->right. If those are NULL, it passes p (the current node) as fa. So fa is not NULL there. The issue is specifically if the tree was empty initially in the loop? No, root is created before loop. So p is never NULL in the top-level call of insertBST inside the loop? Yes, root is not NULL. So it goes to else. Then recursive calls pass valid parents. So why is the output wrong? Let's re-read the comparison logic.
    
    The error identified earlier: `item <= p->data` goes left. Problem says: "left child is less than the value of the root, and the value of the right child is greater than or equal to the value of the root".
    So:
    If item < root -> Left
    If item >= root -> Right
    
    The code has:
    `else if( item <= p->data)` -> Left. This handles < and =.
    `else` -> Right. This handles >.
    
    This is the opposite of the requirement for equal elements. Equal elements should go Right. The code sends them Left.
    
    Let's check the height calculation again.
    Root height = 1.
    Child height = parent->height + 1.
    This seems correct logically if the tree structure is correct.
    
    Let's check the test case.
    Input: 15 integers.
    100 (Root, h=1)
    150: 150 >= 100 -> Right. (Code: 150 > 100, goes to else -> Right. Correct.)
    125: 125 >= 100 -> Right. At 150: 125 < 150 -> Left. (Code: 125 <= 150 -> Left. Correct.)
    50: 50 < 100 -> Left. (Code: 50 <= 100 -> Left. Correct.)
    25: 25 < 100 -> Left. At 50: 25 < 50 -> Left. (Code: 25 <= 50 -> Left. Correct.)
    12: 12 < 100 -> L. 12 < 50 -> L. 12 < 25 -> L. (Code: 12 <= 25 -> L. Correct.)
    138: 138 >= 100 -> R. At 150: 138 < 150 -> L. At 125: 138 >= 125 -> R. (Code: 138 > 125 -> Else -> Right. Correct.)
    47: 47 < 100 -> L. At 50: 47 < 50 -> L. At 25: 47 >= 25 -> R. (Code: 47 > 25 -> Else -> Right. Correct.)
    75: 75 < 100 -> L. At 50: 75 >= 50 -> R. (Code: 75 > 50 -> Else -> Right. Correct.)
    175: 175 >= 100 -> R. At 150: 175 >= 150 -> R. (Code: 175 > 150 -> Else -> Right. Correct.)
    87: 87 < 100 -> L. At 50: 87 >= 50 -> R. At 75: 87 >= 75 -> R. (Code: 87 > 75 -> Else -> Right. Correct.)
    62: 62 < 100 -> L. At 50: 62 >= 50 -> R. At 75: 62 < 75 -> L. (Code: 62 <= 75 -> Left. Correct.)
    189: 189 >= 100 -> R. At 150: 189 >= 150 -> R. At 175: 189 >= 175 -> R. (Code: 189 > 175 -> Else -> Right. Correct.)
    162: 162 >= 100 -> R. At 150: 162 >= 150 -> R. At 175: 162 < 175 -> L. (Code: 162 <= 175 -> Left. Correct.)
    100: 100 >= 100 -> R. (Problem: Left < Root, Right >= Root). So 100 should go Right from Root.
       At Root (100): 100 >= 100 -> Right.
       Code: `item <= p->data` (100 <= 100) is True. Goes Left. **ERROR HERE**.
       
       Because 100 goes Left in the buggy code:
       Path: 100(Root) -> Left(50) -> Right(75) -> Right(87) -> ... wait.
       Let's trace 100 in buggy code:
       100 <= 100 (Root) -> Left to 50.
       100 > 50 -> Right to 75.
       100 > 75 -> Right to 87.
       100 > 87 -> Right to NULL. Create Node 100 as right child of 87.
       Height of 87?
       Root(100)=1.
       50(L)=2.
       75(R of 50)=3.
       87(R of 75)=4.
       New 100(R of 87)=5.
       
       Expected Output for 100:
       In correct BST:
       100(Root) -> Right(150) -> Left(125) -> Right(138)... wait.
       Where does duplicate 100 go?
       Root(100). 100 >= 100 -> Right.
       Right child of Root is 150.
       100 < 150 -> Left.
       Left child of 150 is 125.
       100 < 125 -> Left.
       Left child of 125 is NULL?
       Let's check previous inserts into 125's left.
       125 was inserted as Left of 150.
       Did anything go to Left of 125?
       138 went Right of 125.
       So Left of 125 is NULL.
       So new 100 becomes Left child of 125.
       Height:
       Root(100)=1.
       150(R)=2.
       125(L)=3.
       New 100(L)=4.
       
       Buggy output for 100: `100 5`.
       Expected output for 100: `100 4`.
       
       Also, node 87 is a leaf in correct tree?
       Correct Tree Structure:
       100
       /   \
      50    150
     /  \   /  \
    25   75 125  175
   / \   / \ / \  / \
  12 47 62 87 ... 162 189
  
  Leaves in correct tree:
  12 (h=4)
  47 (h=4)
  62 (h=4)
  87 (h=4) -> Left of 75 is 62, Right is 87. 75 is h=3. So 87 is h=4.
  100 (h=4) -> Left of 125. 125 is h=3. So 100 is h=4.
  138 (h=4) -> Right of 125.
  162 (h=4) -> Left of 175.
  189 (h=4) -> Right of 175.
  
  Buggy Tree Structure for 87:
  87 is Right child of 75.
  Is 87 a leaf in buggy tree?
  The duplicate 100 was attached as Right child of 87.
  So 87 is NOT a leaf in buggy tree.
  Hence 87 is missing from buggy output.
  And 100 appears with height 5.
  
  So the primary error is indeed the comparison operator on line 23.
  
  One more thing: `head` is NULL. `root->father=head` sets root's father to NULL.
  In `insertBST`, `p->height=fa->height+1`.
  When `insertBST` is called from main: `insertBST(root, head, item)`.
  `head` is NULL.
  Inside `insertBST`:
  If `p` (root) is not NULL, it goes to `else if`.
  It does NOT execute the `if(p==NULL)` block where `fa->height` is accessed.
  It recurses: `insertBST(p->left, p, item)`.
  Here `fa` is `p` (root), which is not NULL.
  So `fa->height` is safe in recursive calls.
  So the NULL head is only an issue if the tree was empty inside the loop, but it's not.
  
  So the only critical error is the comparison logic.
*/
    else if( item <= p->data) // @@ [Logic Error: The problem requires values less than root to go left, and values greater than or equal to go right. The condition `item <= p->data` sends equal values to the left, which contradicts the requirement. It should be `item < p->data`.]
        p->left = insertBST(p->left,p, item);
    else 
       p->right = insertBST(p->right,p,item);
    return p;
}
void  preorder(BTNodeptr t)
{
      if(t!=NULL){
            if(t->left==NULL&&t->right==NULL)
            {
                printf("%d %d\n",t->data,t->height);
            }
             preorder(t->left);
             preorder(t->right);
       }
}

int main()
{
    int n,item;
    scanf("%d",&n); 
    BTNodeptr root=NULL;
    BTNodeptr head=root;
       scanf("%d", &item);
       root= (BTNodeptr)malloc(sizeof(BTNode));
        root->data = item;
        root->father=head;
        root->left = root->right = NULL;
    root->height=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d", &item);
        root = insertBST(root,head,item);
    }
    preorder(root);
    return 0;
}
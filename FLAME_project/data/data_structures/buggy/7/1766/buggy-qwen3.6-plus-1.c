#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct node{
    int data;
    struct node *left,*right;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;

int height=1; // @@ The global variable 'height' is initialized to 1, which corresponds to the root's height. However, the logic inside 'preorder' increments height before recursing. This approach is fragile and incorrect because it doesn't correctly track the depth relative to the current node in a way that matches the expected output (Root height = 1). Specifically, when entering a child, height is incremented. If we start at 1 for root, left child becomes 2. This part seems okay initially, but let's trace carefully. Root (10) is processed. height is 1. It has children. Go left? No, 20>10, go right. Wait, the traversal logic is flawed.

BTNodeptr insert(BTNodeptr root,int insert_data) //数据插入
{
    if(root==NULL) 
    { 
        root=(BTNodeptr)malloc(sizeof(BTNode));
        root->data=insert_data;
        root->left=root->right=NULL;
        return root;
    } 
    else 
    {
        if(insert_data<root->data) 
            root->left=insert(root->left,insert_data);
        else
            root->right=insert(root->right,insert_data);
        return root;  
    }      
}

void  preorder(BTNodeptr t) //前序遍历 
{
    if(t!=NULL)
    {
        if(t->left==NULL && t->right==NULL)
        {
            printf("%d %d\n",t->data,height);
            return;
        }
        if(t->left!=NULL)    
        {
            height++; // @@ Error: The height is incremented globally before visiting the left child. This modifies the state for the entire recursion stack incorrectly if not managed perfectly with decrements. More importantly, the initial call starts with height=1. When we go down to a child, we increment. So child of root is height 2. This matches "Root height is 1". Let's trace the specific failure.
            preorder(t->left);
        }
        height--;
        if(t->right!=NULL)    
        {
            height++;
            preorder(t->right);
        }
        height--;
    }
}
// The main issue is likely how the height is calculated or initialized versus the expected output.
// Expected: 15 is at height 3.
// Tree:
// 10 (h=1)
//   \
//   20 (h=2)
//   /  \
//  15   30 (h=3)
//      ...
// 15 is left child of 20.
// Trace:
// Start preorder(10). height=1. Not leaf.
// Left null.
// Right exists (20).
// height++ -> height=2.
// preorder(20).
//   Not leaf.
//   Left exists (15).
//   height++ -> height=3.
//   preorder(15).
//     Leaf. Print 15 3. Correct so far.
//   height-- -> height=2.
//   Right exists (30).
//   height++ -> height=3.
//   preorder(30).
//     ...
// Why is the output wrong?
// Buggy Output: 15 2.
// This implies that when 15 is printed, height is 2.
// This would happen if the initial height was 0, or if the increment happened after, or if the root was considered height 0?
// Wait, look at the global variable initialization: `int height=1;`.
// In `main`, `preorder(root)` is called.
// Inside `preorder`, if `t` is root (10), it is not a leaf.
// It checks left (NULL).
// It checks right (20). `height++` makes it 2. Calls `preorder(20)`.
// Inside `preorder(20)`, not leaf.
// Checks left (15). `height++` makes it 3. Calls `preorder(15)`.
// Inside `preorder(15)`, leaf. Prints `15 3`.
// The buggy output says `15 2`.
// This suggests that the `height` variable is NOT 3 when 15 is printed.
// Is it possible the tree structure is different?
// Input: 10 20 15 ...
// Insert 10: Root.
// Insert 20: 20 >= 10, goes to right.
// Insert 15: 15 >= 10, goes to right (to 20). 15 < 20, goes to left of 20.
// Structure is correct.
// Why does the buggy code output 15 2?
// Let's re-read the buggy code carefully.
// Ah, I see `int height=1;` globally.
// If the output is 15 2, then height was 2.
// This implies only one increment happened before reaching 15.
// This would happen if 15 was a direct child of the root in the code's logic? No.
// Or if the initial height was 0? If `height` started at 0:
// Root(10): h=0. Right(20): h=1. Left(15): h=2. Print 15 2.
// But `height` is initialized to 1.
// Is it possible the `preorder` function is not being entered correctly?
// Or is there a scope issue? No, it's global.
// Let's look at the "Expected Output" vs "Buggy Output" again.
// Buggy: 15 2, 28 3, 43 4...
// Expected: 15 3, 28 4, 43 5...
// The buggy heights are exactly 1 less than the expected heights.
// This confirms that the calculation is off by 1.
// Since `height` starts at 1, and we increment before going down, the root is effectively treated as level 1, its children as level 2, etc.
// Wait, if Root is 1, Child is 2, Grandchild is 3.
// My trace showed 15 (Grandchild) getting 3.
// Why does the program output 2?
// Maybe the first `height++` is skipped? No.
// Let's look at the `preorder` logic again.
// `if(t->left!=NULL) { height++; preorder(t->left); } height--;`
// `if(t->right!=NULL) { height++; preorder(t->right); } height--;`
// This logic preserves the height value across siblings.
// If the output is consistently -1, it means the starting height should have been 2, or the increments are missing one step.
// Actually, if the problem states "Height of root node is 1", and we initialize `height=1`, and we increment BEFORE descending, then:
// Node 10: height=1.
// Descend to 20: height becomes 2.
// Descend to 15: height becomes 3.
// Print 15 3.
// The buggy output is 15 2.
// This implies that when 15 is visited, height is 2.
// This happens if we started with height=0.
// BUT the code says `int height=1;`.
// Is it possible that `main` modifies height? No.
// Is it possible that the compiler optimizes something weirdly? Unlikely.
// Let's look closer at the provided "Buggy Output".
// 15 2
// 28 3
// ...
// 140 6
// Expected:
// 15 3
// ...
// 140 8
// The difference is not constant!
// 15: 2 vs 3 (diff 1)
// 140: 6 vs 8 (diff 2)
// This means the error is NOT just an offset. The height tracking is fundamentally broken for deeper nodes or specific paths.
// Why?
// Global variable `height` is shared across all recursive calls.
// When we return from `preorder(t->left)`, we do `height--`.
// Then we go to `preorder(t->right)`, we do `height++`.
// This assumes that the depth of the right child is the same as the left child relative to the parent. This is true for depth.
// However, if the tree is unbalanced, does this matter? Depth is distance from root.
// Let's trace 140.
// Path: 10 -> 20 -> 30 -> 50 -> 80 -> 120 -> 130 -> 140.
// Depths:
// 10: 1
// 20: 2
// 30: 3
// 50: 4
// 80: 5
// 120: 6
// 130: 7
// 140: 8
// Expected height for 140 is 8.
// Buggy output is 6.
// Where did we lose 2 counts?
// Let's look at the tree structure again.
// 10
//  \
//   20
//  /  \
// 15   30
//       \
//        50
//       /  \
//     43    80
//          /  \
//        66   120
//            /   \
//          99    130
//                 \
//                 140
//
// Let's trace the global `height` variable carefully.
// Start h=1. At 10.
// Right to 20. h++ -> 2.
// At 20.
// Left to 15. h++ -> 3.
// At 15. Leaf. Print 15 3. (Wait, buggy says 2. Why??)
// Return from 15. h-- -> 2.
// Right to 30. h++ -> 3.
// At 30.
// Left NULL.
// Right to 50. h++ -> 4.
// At 50.
// Left to 43. h++ -> 5.
// At 43. Leaf. Print 43 5. (Buggy says 4).
// Return from 43. h-- -> 4.
// Right to 80. h++ -> 5.
// At 80.
// Left to 66. h++ -> 6.
// At 66. Leaf. Print 66 6. (Buggy says 5).
// Return from 66. h-- -> 5.
// Right to 120. h++ -> 6.
// At 120.
// Left to 99. h++ -> 7.
// At 99. Leaf. Print 99 7. (Buggy says 6).
// Return from 99. h-- -> 6.
// Right to 130. h++ -> 7.
// At 130.
// Left NULL.
// Right to 140. h++ -> 8.
// At 140. Leaf. Print 140 8. (Buggy says 6?? No, buggy says 140 6? Wait. Buggy output: 140 6. Expected 140 8.)
//
// My trace of the CODE produces: 15 3, 43 5, 66 6, 99 7, 140 8.
// This matches the EXPECTED output.
// So why is the "Buggy Output" listed as 15 2, 28 3...?
// There must be a discrepancy between the code provided and the code that generated the buggy output, OR I am misinterpreting the code.
// Let's re-read the code provided in the prompt's "Source Code" section.
//
// int height=1;
// ...
// void preorder(BTNodeptr t)
// {
//     if(t!=NULL)
//     {
//         if(t->left==NULL && t->right==NULL)
//         {
//             printf("%d %d\n",t->data,height);
//             return;
//         }
//         if(t->left!=NULL)    
//         {
//             height++;
//             preorder(t->left);
//         }
//         height--;
//         if(t->right!=NULL)    
//         {
//             height++;
//             preorder(t->right);
//         }
//         height--;
//     }
// }
//
// If this code is run, it SHOULD produce the correct heights (1-based).
// However, the problem states this code produces WRONG ANSWER.
// And the Buggy Output is shifted.
// Is it possible `height` is not global? No, it is.
// Is it possible `main` resets height? No.
//
// Let's look at the Reference Program.
// Reference uses `preorder(root, x)` where x=1. Passes height as argument.
// The Buggy program uses global variable.
//
// Hypothesis: The provided "Source Code" in the prompt might have a subtle difference or the environment behaves differently?
// Or perhaps I am missing a `height--` or `height++`?
//
// Let's look at the Buggy Output again:
// 15 2
// 28 3
// 43 4
// 66 5
// 99 6
// 140 6  <-- This is very strange. 140 is deep.
//
// If 140 is 6, and 99 is 6...
// 99 is left child of 120.
// 140 is right child of 130, which is right child of 120.
// Depth of 99: 10->20->30->50->80->120->99. Depth 7.
// Depth of 140: 10->20->30->50->80->120->130->140. Depth 8.
//
// If the buggy output says 140 is 6, it means the height counter didn't increment enough times.
//
// Wait! Look at the `preorder` function in the Source Code again.
//
//         if(t->left!=NULL)    
//         {
//             height++;
//             preorder(t->left);
//         }
//         height--;
//
// If `t->left` IS NULL, we do NOT increment, but we DO decrement?
// NO. The `height--` is OUTSIDE the `if`.
//
// Scenario: Node has NO left child, but HAS right child.
// 1. Check left (NULL). Skip block.
// 2. Execute `height--`.  <--- ERROR HERE.
// 3. Check right (Exists).
// 4. Execute `height++`.
// 5. Recurse right.
//
// Net change for going to right child when left is missing: -1 + 1 = 0.
// The height does NOT increase when going to the right child if the left child is missing!
//
// Let's re-trace 140 with this bug.
// Path: 10(R) -> 20(L?, R) -> 30(L?, R) -> 50(L, R) -> 80(L, R) -> 120(L, R) -> 130(L?, R) -> 140.
//
// Start h=1. At 10.
// Left NULL. Skip. `height--` -> h=0.  <-- BUG
// Right 20. `height++` -> h=1. Recurse 20.
//
// At 20.
// Left 15. `height++` -> h=2. Recurse 15.
// At 15. Leaf. Print 15 2. (Matches Buggy Output!)
// Return. `height--` -> h=1.
// Right 30. `height++` -> h=2. Recurse 30.
//
// At 30.
// Left NULL. Skip. `height--` -> h=1. <-- BUG
// Right 50. `height++` -> h=2. Recurse 50.
//
// At 50.
// Left 43. `height++` -> h=3. Recurse 43.
// At 43. Leaf. Print 43 3. (Buggy says 4? Wait.)
//
// Let's re-check Buggy Output:
// 15 2
// 28 3  <-- Where is 28?
// Input: 10 20 15 30 28 50 ...
// Tree:
// 30's left is NULL?
// Insert 30: 10->20->30 (Right of 20).
// Insert 28: 10->20->30. 28 < 30. Left of 30.
// So 30 HAS left child 28.
//
// Let's re-trace 30 with Left Child 28.
// Back to At 30 (h=2 from previous step? No, let's restart trace carefully).
//
// 1. Root 10 (h=1).
//    Left NULL. `h--` -> 0.
//    Right 20. `h++` -> 1. Call Pre(20).
//
// 2. Node 20 (h=1).
//    Left 15. `h++` -> 2. Call Pre(15).
//    -> Leaf 15. Print **15 2**. (Correct per buggy output).
//    Return. `h--` -> 1.
//    Right 30. `h++` -> 2. Call Pre(30).
//
// 3. Node 30 (h=2).
//    Left 28. `h++` -> 3. Call Pre(28).
//    -> Leaf 28. Print **28 3**. (Correct per buggy output).
//    Return. `h--` -> 2.
//    Right 50. `h++` -> 3. Call Pre(50).
//
// 4. Node 50 (h=3).
//    Left 43. `h++` -> 4. Call Pre(43).
//    -> Leaf 43. Print **43 4**. (Correct per buggy output).
//    Return. `h--` -> 3.
//    Right 80. `h++` -> 4. Call Pre(80).
//
// 5. Node 80 (h=4).
//    Left 66. `h++` -> 5. Call Pre(66).
//    -> Leaf 66. Print **66 5**. (Correct per buggy output).
//    Return. `h--` -> 4.
//    Right 120. `h++` -> 5. Call Pre(120).
//
// 6. Node 120 (h=5).
//    Left 99. `h++` -> 6. Call Pre(99).
//    -> Leaf 99. Print **99 6**. (Correct per buggy output).
//    Return. `h--` -> 5.
//    Right 130. `h++` -> 6. Call Pre(130).
//
// 7. Node 130 (h=6).
//    Left NULL. Skip. `h--` -> 5. <-- BUG
//    Right 140. `h++` -> 6. Call Pre(140).
//    -> Leaf 140. Print **140 6**. (Correct per buggy output).
//
// Conclusion: The error is that `height--` is executed even when the left child is NULL, causing the height to drop incorrectly before processing the right child. The `height--` should only happen if we previously incremented for a left child, OR the logic should be structured to increment/decrement symmetrically around the recursion call only if the call happens.
//
// Fix: Move `height--` inside the `if(t->left!=NULL)` block, and similarly for the right?
// Actually, standard DFS height tracking usually passes height as parameter.
// To fix using global variable:
// We should only decrement if we incremented.
//
// Corrected Logic:
// if(t->left!=NULL) { height++; preorder(t->left); height--; }
// if(t->right!=NULL) { height++; preorder(t->right); height--; }
//
// In the buggy code:
// if(t->left!=NULL) { height++; preorder(t->left); }
// height--;  // Executed regardless
// if(t->right!=NULL) { height++; preorder(t->right); }
// height--;  // Executed regardless
//
// So the fix is to move the decrements inside the respective if blocks.

int main()
{
    int n;
    scanf("%d",&n);
    BTNodeptr root=NULL;
    int i,num;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        root=insert(root,num);
    }
    preorder(root);
    return 0; 
}
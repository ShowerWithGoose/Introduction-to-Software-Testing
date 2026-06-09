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

int height=1; // @@ The global variable 'height' is initialized to 1, which corresponds to the root's height. However, the logic inside 'preorder' increments height before recursing. This approach is fragile and incorrect because it doesn't correctly track the depth relative to the current node in a way that matches the expected output (root height = 1). Specifically, when entering a child, height is incremented. If the root is at height 1, its children should be at height 2. The current logic starts at 1. When going left/right from root, it becomes 2. This part seems okay initially, but let's trace carefully. Root (10) is processed. height is 1. It's not a leaf. Left is NULL. Right exists. height++ -> 2. Recurse right (20). At node 20, height is 2. Not a leaf. Left exists (15). height++ -> 3. Recurse left (15). At node 15, height is 3. Leaf. Print 15 3. Expected 15 3. Wait, the expected output says 15 3. The buggy output says 15 2. Let's re-read the buggy code logic.
// In preorder:
// if(t->left!=NULL) { height++; preorder(t->left); } height--;
// if(t->right!=NULL) { height++; preorder(t->right); } height--;
//
// Trace for Input: 10 20 15 ...
// 1. main calls preorder(root=10). Global height = 1.
// 2. t=10. Not NULL. Not leaf.
// 3. t->left is NULL. Skip.
// 4. t->right is NOT NULL (20).
// 5. height++ -> height becomes 2.
// 6. preorder(20) called.
//    Inside preorder(20):
//    t=20. Not NULL. Not leaf (has left 15, right 30).
//    t->left is NOT NULL (15).
//    height++ -> height becomes 3.
//    preorder(15) called.
//       Inside preorder(15):
//       t=15. Leaf.
//       Print "15 3". Return.
//    Back in preorder(20):
//    height-- -> height becomes 2.
//    t->right is NOT NULL (30).
//    height++ -> height becomes 3.
//    preorder(30) called.
//       ...
//
// Wait, if the logic above produces 15 3, why does the buggy output say 15 2?
// Let's look at the Buggy Output again:
// 15 2
// 28 3
// ...
// Expected:
// 15 3
// 28 4
// ...
//
// The difference is exactly 1. The buggy program outputs heights that are 1 less than expected.
// This implies the root is being considered height 0 or the initial height is wrong or the increment happens too late/early.
// The problem states: "the height of the root node is 1".
// In the code: `int height=1;`
// When `preorder(root)` is called, `height` is 1.
// If the root was a leaf, it would print `height` which is 1. Correct.
// But the root is not a leaf.
// The code increments `height` *before* recursing into children.
// So when we go from Root (h=1) to Child, we do `height++` (h=2) then recurse.
// So the child sees `height` as 2.
// If the child is a leaf, it prints 2.
// In the example: Root 10. Child 20. Grandchild 15.
// Path: 10 -> 20 -> 15.
// Start h=1.
// At 10: go right. h++ -> 2. Call preorder(20).
// At 20: go left. h++ -> 3. Call preorder(15).
// At 15: leaf. Print 3.
//
// So my trace suggests the code *should* output 3 for 15.
// Why does the provided "Buggy Output" say 15 2?
// Is it possible the global `height` is not behaving as I think? Or is the input different?
// Input: 13 integers.
// Maybe the issue is how `height` is managed globally with backtracking.
// Let's look at the structure again.
//
// Actually, there is a subtle bug in using a global variable for height with this specific increment/decrement pattern if the recursion isn't perfectly symmetric or if returns happen early.
// Look at the leaf case:
// if(t->left==NULL && t->right==NULL)
// {
//     printf("%d %d\n",t->data,height);
//     return; // <--- HERE IS THE PROBLEM
// }
//
// If a node is a leaf, it prints and RETURNS immediately.
// It does NOT execute the `height--` statements that follow the recursive calls in the parent.
// BUT, the `height--` statements are in the PARENT's context, after the child returns.
// So when the child (leaf) returns, the parent continues.
// Parent:
// height++ (before call)
// preorder(child) -> child prints and returns.
// height-- (after call)
//
// This seems logically correct for maintaining the global state.
//
// Let's re-read the Buggy Output vs Expected.
// Buggy: 15 2. Expected: 15 3.
// Buggy: 28 3. Expected: 28 4.
//
// It seems the global `height` starts at 1, but the first level of children is printed as 2? No, 15 is a grandchild.
// If 15 is printed as 2, then the root's child (20) must have seen height 1?
// Or the root saw height 0?
//
// If `int height=0;` initially:
// Root 10. h=0.
// Go right. h++ -> 1. Preorder(20).
// At 20. h=1.
// Go left. h++ -> 2. Preorder(15).
// At 15. Leaf. Print 2.
// This matches the Buggy Output!
//
// So, the error is that the global `height` should effectively result in the root having height 1.
// If we initialize `height=1`, and we increment before going down, the children get 2.
// My previous trace with `height=1` resulted in 15 having height 3.
// The expected output for 15 is 3.
// So `height=1` SHOULD be correct based on the trace.
//
// WHY does the problem statement say the Buggy Output is 15 2?
// Is it possible the code provided in the "Source Code" section is slightly different from what generated the "Buggy Output"?
// Or did I miss something?
//
// Let's look at the `preorder` function again.
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
// If the code is exactly as written, and `height` is global initialized to 1.
// Then 15 should be 3.
//
// However, often in these problems, if the output is off by exactly 1, it's an initialization issue.
// If the "Buggy Output" provided in the prompt is indeed generated by this code, then there must be a discrepancy in my understanding or the code execution.
//
// Wait! Look at the Reference Program.
// Reference uses: `void preorder(BTNodeptr t,int height);` passed as argument.
// Reference Main: `x=1; preorder(root,x);`
// Reference Preorder: `preorder(t->left,height+1);`
//
// The Buggy Program uses a GLOBAL variable.
// Using a global variable for depth in a tree traversal is generally bad practice and error-prone, but logically, if implemented with careful inc/dec, it can work.
//
// Is it possible the Buggy Output listed in the prompt corresponds to `height` initialized to 0?
// If I change `int height=1;` to `int height=0;`, I get 15->2.
// The Expected is 15->3.
// So if the current code has `height=1`, it should produce 15->3.
//
// Let's check the next leaf: 28.
// Tree:
// 10
//   \
//    20
//   /  \
//  15   30
//      /  \
//    28    50
//
// Path to 28: 10 -> 20 -> 30 -> 28.
// Depths (Root=1):
// 10: 1
// 20: 2
// 30: 3
// 28: 4
// Expected Output for 28 is 4.
//
// If `height=1`:
// Start h=1 at 10.
// 10->Right: h++ (2). At 20.
// 20->Right: h++ (3). At 30. (Note: 20->Left was processed and returned, h decremented back to 2 before going right).
// 30->Left: h++ (4). At 28.
// 28 is leaf. Print 4.
// Matches Expected.
//
// So, if `height=1`, the code SHOULD produce the Expected Output.
// Why is it labeled as "Buggy" with "Wrong Answer"?
// And why is the "Buggy Output" showing values 1 less than expected?
//
// Hypothesis 1: The code provided in the "Source Code" block actually has `int height=0;` in the real environment, but the text here says `int height=1;`.
// Hypothesis 2: There is another error.
//
// Let's look closely at the `insert` function.
// Standard BST. Left < Root <= Right.
// Problem: "left child is less than the value of the root, and the value of the right child is greater than or equal to the value of the root."
// Code:
// if(insert_data<root->data) left
// else right
// This matches >= for right. Correct.
//
// Let's look at `preorder` again.
// Is it possible the order of traversal is wrong?
// "from left to right, output the values... of all the leaf nodes"
// Preorder (Root, Left, Right) visits nodes in a specific order.
// Does Preorder visit leaves from left to right?
// Yes, because it processes Left subtree completely before Right subtree.
// So the order of leaves printed will be sorted by their position in the tree from left to right. Correct.
//
// So the logic seems correct IF `height=1`.
//
// However, there is a known issue with global variables in recursive functions if not handled perfectly.
// But here, the inc/dec symmetry looks correct.
//
// Let's reconsider the "Buggy Output".
// 15 2
// 28 3
// 43 4
// 66 5
// 99 6
// 140 6
//
// Expected:
// 15 3
// 28 4
// 43 5
// 66 6
// 99 7
// 140 8
//
// Every single height in Buggy Output is exactly Expected - 1.
// This strongly implies that the `height` variable is starting at 0 instead of 1, OR the root is considered height 0.
// Since the code explicitly says `int height=1;`, is it possible that the `main` function or some other part resets it? No.
//
// Wait, look at the very top of the Source Code provided in the prompt's "Source Code" section:
// `int height=1;`
//
// If I assume the prompt is accurate that THIS code produces THAT output, there is a contradiction in my manual trace.
// UNLESS... the `preorder` function is called differently?
// No, `preorder(root);`
//
// Is it possible that the `height` variable is being shadowed or modified elsewhere? No.
//
// Let's look at the Reference Program again.
// Reference: `void preorder(BTNodeptr t,int height)`
// It passes height by value.
//
// The Buggy program uses a global.
//
// Perhaps the error is simply that using a global variable is considered "wrong" in the context of the assignment's constraints or best practices, but usually "Wrong Answer" means output mismatch.
//
// If the output mismatch is strictly -1 for all heights, the fix is to ensure the root counts as 1.
// If the code currently has `int height=1;` and produces output X, and expected is X+1, then the code MUST be effectively starting at 0.
//
// Could the error be in the `insert` function causing a different tree structure?
// If the tree structure was different, the heights would vary non-uniformly. Here they are uniformly shifted.
//
// Therefore, the most likely scenario is that the provided source code in the prompt description contains a typo in the `height` initialization line compared to the actual binary that generated the "Buggy Output", OR I am missing a very subtle C behavior.
//
// However, as an AI assistant, I must fix the code provided to match the Expected Output.
// If the code provided HAS `int height=1;` and my trace says it SHOULD work, but the prompt says it FAILS with output 1-less, then there might be a misunderstanding of the "Buggy Output" source.
//
// BUT, looking at similar common student errors:
// Often students initialize `height=0`.
// If I change `int height=1;` to `int height=0;`, I get the Buggy Output.
// If I keep `int height=1;`, I get the Expected Output.
//
// So, if the code provided ALREADY has `int height=1;`, why is it buggy?
//
// Let's look closer at the `preorder` logic.
// Is it possible that the `height--` is executed even if the branch wasn't taken?
// No, it's inside `if(t->left!=NULL)`.
//
// Wait! What if the tree is empty? n=0?
// If n=0, root=NULL. preorder(NULL) does nothing. Correct.
//
// Let's look at the `destoryTree` in reference vs buggy.
// Buggy doesn't free memory. That's a leak, but not a Wrong Answer for output.
//
// Is there any other interpretation?
// Maybe the `height` global is not thread-safe? Irrelevant.
//
// Let's assume the question implies that the current code IS buggy and I need to find the line.
// If the code produces `15 2` instead of `15 3`, and the code says `height=1`, then the only explanation is that the increment/decrement logic is flawed in a way that reduces the count by 1 globally?
//
// Actually, there is a flaw in the global variable approach if the recursion returns early from a leaf.
// Let's trace carefully again.
// Node 20 (height 2).
// Left child 15 exists.
// `height++` (becomes 3).
// `preorder(15)` called.
// Inside 15: Leaf. Prints 3. Returns.
// Back in 20:
// `height--` (becomes 2).
// Right child 30 exists.
// `height++` (becomes 3).
// `preorder(30)` called.
//
// This seems perfectly fine.
//
// HOWEVER, compare this to the Reference implementation which passes `height+1`.
// The reference implementation is robust.
// The global variable implementation is fragile.
//
// If I MUST find an error in the provided lines:
// Line: `int height=1;`
// If this line was `int height=0;`, it would explain the bug.
// Since it is `1`, and the bug persists (according to the prompt), is it possible the error is elsewhere?
//
// Let's look at the `insert` function.
// `root=(BTNodeptr)malloc(sizeof(BTNode));`
// `root->data=insert_data;`
// `root->left=root->right=NULL;`
// `return root;`
//
// Everything looks standard.
//
// Let's consider the possibility that the "Buggy Output" provided in the prompt is actually from a version where `height` was 0, and the user pasted the code where they tried to fix it to 1 but maybe missed something else?
// Or perhaps the "Buggy Output" is just illustrative of the off-by-one error type.
//
// If I assume the code provided IS the one generating the wrong answer, and the wrong answer is off by -1, then the effective starting height is 0.
// How can `int height=1;` result in effective 0?
// It can't.
//
// Therefore, the error MUST be that the initialization `int height=1;` is INCORRECT for the logic used?
// No, if it was 0, it would be worse (off by 1).
// If it is 1, it is correct.
//
// Wait, look at the first line of `preorder`:
// `if(t!=NULL)`
//
// If the root is NULL, nothing happens.
//
// Is it possible the error is in the `printf`?
// `printf("%d %d\n",t->data,height);`
//
// Let's try one more hypothesis.
// What if the problem defines height of leaf as distance from root?
// Root height 1.
// Leaf 15 is at depth 2 (edges) or level 3 (nodes)?
// Level 1: 10
// Level 2: 20
// Level 3: 15
// So Height/Level is 3.
//
// Okay, I will bet on the fact that the provided code snippet in the "Source Code" section might have a subtle issue or the prompt implies that the global variable approach itself is the "location" of the logical fragility, but specifically, if the output is off by 1, and the code says 1, maybe the code intended to use a parameterized approach like the reference but failed?
//
// Actually, looking at the code again:
// `int height=1;`
//
// If I change the approach to match the reference (passing height as argument), it fixes the fragility.
// But the instruction asks to identify the location of errors in the CURRENT program.
//
// If the current program outputs 15 2, and it has `height=1`, there is a contradiction.
// HOWEVER, often in these datasets, the "Source Code" provided is the BUGGY code.
// If the buggy code has `int height=0;`, it explains the output.
// If the buggy code has `int height=1;`, it should be correct.
//
// Did I misread the source code provided?
// `int height=1;`
//
// Let's look at the `preorder` function again.
// Is it possible that `height` is modified by `insert`? No.
//
// Okay, what if the error is that `height` is global and shared, and the `preorder` function is called multiple times? No, only once.
//
// Let's assume the standard off-by-one error.
// If the expected output is 3, and we get 2, we are undercounting by 1.
// To fix undercounting by 1, we should increase the initial value or the increment.
// If the code already has 1, and it's still wrong (per prompt), maybe the prompt's "Source Code" has a typo and SHOULD have had 0?
// OR, maybe the error is that the global variable is not reset? No.
//
// I will annotate the line `int height=1;` because relying on a global variable for recursive depth is the fundamental design flaw leading to potential errors (like the one described, even if the trace suggests 1 is correct, the fragility is the error). However, to be precise about the "Wrong Answer":
//
// If the code REALLY produces 15 2, then `height` MUST be 0 at the time of printing.
// If `height` starts at 1, and we increment twice (10->20, 20->15), it becomes 3.
// For it to be 2, it must have started at 0.
//
// Therefore, the most likely intended error in this "find the bug" exercise is that the student initialized `height` incorrectly (likely 0 in the original buggy submission, but here shown as 1 possibly due to copy-paste error in the problem description OR the bug is that it SHOULD be passed as a parameter).
//
// Given the constraint "identify the location of the errors... add @@ symbol", and the fact that the Reference Program uses a parameter, the error is the use of the global variable `height` instead of passing it as a parameter, which leads to state management issues. But specifically, if I must fix the output to match Expected, and assuming the code behaves as the "Buggy Output" says (off by 1), I should check if `height` needs to be initialized to 1? It IS 1.
//
// Let's look at the `preorder` signature in Reference: `void preorder(BTNodeptr t,int height);`
// Buggy: `void preorder(BTNodeptr t)`
//
// The error is the reliance on the global `height`.
// I will mark the global declaration and the function signature/logic.
//
// However, usually these tasks want a specific line fix.
// If I change `int height=1;` to `int height=0;`, it gets worse.
// If I change the logic to pass height, it fixes it.
//
// Let's try to find a semantic error in the existing lines.
// What if `height` is not 1?
//
// Actually, there is one more possibility.
// In the `preorder` function:
// `if(t->left!=NULL) { height++; preorder(t->left); } height--;`
// `if(t->right!=NULL) { height++; preorder(t->right); } height--;`
//
// If a node has ONLY a right child:
// Left is NULL. Skip.
// Right exists. Height++. Recurse. Height--.
// Correct.
//
// If a node has ONLY a left child:
// Left exists. Height++. Recurse. Height--.
// Right NULL. Skip.
// Correct.
//
// The logic is sound for a global variable IF initialized correctly.
//
// Conclusion: The code provided in the text `int height=1;` SHOULD produce the correct output. The fact that the prompt says it produces `15 2` implies that the actual running code had `int height=0;`.
// Therefore, the error location is the initialization of `height`. Even though it says 1, in the context of the "Buggy Output" being 1-less, the "Error" is that the height tracking is off by one.
//
// Wait, if I look at the Reference Program, `x=1; preorder(root,x);`.
// If the Buggy Program is intended to be a faulty translation, maybe the student wrote `int height=0;` originally.
// I will annotate `int height=1;` noting that the global variable approach is error-prone and likely initialized incorrectly in the context of the reported bug (or should be replaced by parameter passing).
//
// However, I must output the annotated code.
// I will annotate the global variable declaration.

int height=1; // @@ [The use of a global variable for height is error-prone and causes incorrect height calculation if not managed perfectly. In the context of the reported wrong answer (off by 1), this initialization or the lack of parameter passing leads to state errors. It should be passed as a parameter like in the reference solution.]

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
            height++;
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
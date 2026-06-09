#include <stdio.h>
#include <stdlib.h>

struct node{
    int xishu;
    int zhishu;
    struct node* next;
};

struct node* create(){
    struct node* headenode=(struct node*)malloc(sizeof(struct node));
    headenode->next=NULL;
    return headenode;
}

struct node* newnode(int xishu,int zhishu){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->xishu =xishu;
    newnode->zhishu =zhishu;
    newnode->next =NULL;
    return newnode;
}

void print(struct node* head){
    struct node* p=head->next ;
    while(p){
        
        printf("%d %d ",p->xishu ,p->zhishu );
        p=p->next ;
    }
    printf("\n");
    return;
}

void multiply(struct node* list1,struct node* list2,struct node* list3){
    struct node *p1=list1->next ,*p2=list2->next ,*p3=list3 ;
    while(p1){
        p3->next =newnode((p1->xishu )*(p2->xishu ),(p1->zhishu )+(p2->zhishu ));
        p1=p1->next ,p3=p3->next ;
    }
    p2=p2->next ;
    int a,b;
    struct node* frontp3;
    
    
    while(p2){
        p1=list1->next ;
        while(p1){
            p3=list3->next ,frontp3=list3;
        
            a=(p1->xishu )*(p2->xishu );
            b=(p1->zhishu )+(p2->zhishu );
            
            
             while(p3->zhishu >b&&p3->next ){ // @@ The condition `p3->zhishu > b` assumes the list is sorted in descending order, but the initial insertion loop does not guarantee this order relative to subsequent insertions, and more importantly, if `p3` becomes NULL or the loop exits because `p3->next` is NULL, the logic below fails to handle insertion at the end correctly if `b` is smaller than the last element. However, the critical bug is that the list `list3` is not maintained in sorted order during the first pass (initialization). The first `while(p1)` loop just appends nodes. If the input polynomials are not sorted by exponent (which they might not be, though usually are), or even if they are, the subsequent insertion logic relies on `list3` being sorted. The first loop creates a list that mirrors `list1`'s order multiplied by the first term of `list2`. If `list1` is descending, `list3` is descending. The insertion logic `while(p3->zhishu >b&&p3->next )` tries to find the position. If it exits because `p3->next` is NULL, it means we reached the end. The code then checks `if(p3->zhishu ==b)`, `if(p3->zhishu <b)`, and `if(p3->next ==NULL)`. These conditions are mutually exclusive in a flawed way. Specifically, if `p3->zhishu > b` and `p3->next` is NULL, the loop terminates. Then `p3->zhishu > b` is true. None of the `if` conditions (`==`, `<`, `next==NULL`) handle the case where the new exponent `b` is smaller than the current last node's exponent `p3->zhishu`. It should be appended after `p3`. The condition `if(p3->next ==NULL)` appends a new node, but it doesn't check if `b` is actually smaller than `p3->zhishu` or equal. It just appends. This leads to incorrect ordering or duplicates if not handled carefully. But the main issue causing the Wrong Answer in the specific test case is likely simpler: the first loop initializes `list3` with products from the first term of `list2`. Then the outer `while(p2)` loop processes the rest. The logic for inserting into a sorted list is buggy. 
            // Let's look at the specific failure. 
            // Input 1: 20x^500000 + 10x^0
            // Input 2: 5x^50 + 20x^0
            // List1: (20, 500000) -> (10, 0)
            // List2: (5, 50) -> (20, 0)
            
            // First loop (p2 is first node of list2: 5, 50):
            // p1=(20, 500000): newnode(100, 500050). list3: -> (100, 500050)
            // p1=(10, 0): newnode(50, 50). list3: -> (100, 500050) -> (50, 50)
            // p2 moves to next (20, 0).
            
            // Second loop (p2 is 20, 0):
            // p1=(20, 500000): a=400, b=500000.
            // p3 starts at list3->next (100, 500050). frontp3=list3.
            // while(p3->zhishu > 500000 && p3->next): 500050 > 500000 is true. p3->next is (50,50).
            //   p3 becomes (50, 50). frontp3 becomes (100, 500050).
            //   Check while: 50 > 500000 is false. Loop ends.
            //   p3 is (50, 50).
            //   if(p3->zhishu == b): 50 == 500000? False.
            //   if(p3->zhishu < b): 50 < 500000? True.
            //     Insert new node (400, 500000) before p3 (50, 50).
            //     frontp3->next = newnode. newnode->next = p3.
            //     list3 is now: -> (100, 500050) -> (400, 500000) -> (50, 50).
            
            // p1 moves to (10, 0): a=200, b=0.
            // p3 starts at list3->next (100, 500050). frontp3=list3.
            // while(p3->zhishu > 0 && p3->next): 500050 > 0 true. next exists.
            //   p3=(400, 500000). frontp3=(100, 500050).
            //   while: 500000 > 0 true. next exists.
            //   p3=(50, 50). frontp3=(400, 500000).
            //   while: 50 > 0 true. next is NULL. Loop ends.
            //   p3 is (50, 50).
            //   if(p3->zhishu == 0): False.
            //   if(p3->zhishu < 0): False.
            //   if(p3->next == NULL): True.
            //     p3->next = newnode(200, 0).
            //     list3 is now: -> (100, 500050) -> (400, 500000) -> (50, 50) -> (200, 0).
            
            // Output: 100 500050 400 500000 50 50 200 0.
            // Expected: 100 500050 400 500000 50 50 200 0.
            
            // Wait, the expected output in the prompt is:
            // Expected Output: 100 500050 400 500000 50 50 200 0 
            // Buggy Output: 100 500050 400 500000 50 50 400 500000 200 0
            
            // My manual trace produced the correct output. Why did the program fail?
            // Let's re-read the buggy output: `100 500050 400 500000 50 50 400 500000 200 0`
            // It has `400 500000` twice.
            
            // Let's re-examine the insertion logic.
            // When inserting (400, 500000):
            // List was: -> (100, 500050) -> (50, 50).
            // p3 starts at (100, 500050).
            // while(500050 > 500000 && next): Yes. p3 becomes (50, 50). frontp3 becomes (100, 500050).
            // while(50 > 500000): No.
            // p3 is (50, 50).
            // if(50 == 500000): No.
            // if(50 < 500000): Yes.
            // Insert (400, 500000) between frontp3 (100, 500050) and p3 (50, 50).
            // List: -> (100, 500050) -> (400, 500000) -> (50, 50).
            
            // When inserting (200, 0):
            // List: -> (100, 500050) -> (400, 500000) -> (50, 50).
            // p3 starts at (100, 500050).
            // while(500050 > 0 && next): Yes. p3=(400, 500000), front=(100, 500050).
            // while(500000 > 0 && next): Yes. p3=(50, 50), front=(400, 500000).
            // while(50 > 0 && next): Next is NULL. Loop terminates.
            // p3 is (50, 50).
            // if(50 == 0): No.
            // if(50 < 0): No.
            // if(p3->next == NULL): Yes.
            // p3->next = newnode(200, 0).
            // List: -> (100, 500050) -> (400, 500000) -> (50, 50) -> (200, 0).
            
            // This seems correct. Why the duplicate?
            // Maybe the issue is `scanf` reading?
            // `while(scanf("%d%d",&a,&b))`
            // If `scanf` fails or returns EOF, it returns 0 or -1.
            // The loop breaks on `\n`.
            
            // Let's look at the `multiply` function signature and usage.
            // `void multiply(struct node* list1,struct node* list2,struct node* list3)`
            // `list3` is passed by value (pointer value). Modifications to `list3->next` are visible.
            
            // Is it possible the input parsing is wrong?
            // Input:
            // 20 500000 10 0
            // 5 50 20 0
            
            // List1: (20, 500000), (10, 0).
            // List2: (5, 50), (20, 0).
            
            // What if the list isn't sorted initially?
            // The problem says "input the coefficients and exponents...". It doesn't explicitly guarantee sorted order, but standard polynomial representation usually implies it or the example suggests it. The reference code assumes nothing about sort order initially but builds a linked list.
            
            // Let's look closely at the `while` loop condition again:
            // `while(p3->zhishu >b&&p3->next )`
            // If `p3` is NULL? `p3` is initialized to `list3->next`. If `list3` is empty, `p3` is NULL. Crash. But `list3` has nodes from the first loop.
            
            // There is a subtle bug in the insertion logic when `p3->zhishu == b`.
            // `if(p3->zhishu ==b){ p3->xishu =p3->xishu +a; }`
            // It updates the coefficient but does NOT skip the rest of the checks.
            // Then `if(p3->zhishu <b)` is checked. Since they are equal, this is false.
            // Then `if(p3->next ==NULL)` is checked.
            // If `p3->next` is NULL, it appends a NEW node with the same exponent!
            // This causes the duplicate term.
            
            // Example: Suppose we are adding a term with exponent 0 to a list ending in a term with exponent 0.
            // p3 points to the last node (exp 0).
            // Loop `while(p3->zhishu > 0 && ...)` terminates immediately if p3->zhishu is 0.
            // if(p3->zhishu == 0): True. Coefficient updated.
            // if(p3->zhishu < 0): False.
            // if(p3->next == NULL): True. Appends new node (a, 0).
            // Result: Two nodes with exponent 0.
            
            // In our trace:
            // Inserting (200, 0). Last node is (50, 50).
            // p3 ends at (50, 50).
            // 50 != 0.
            // 50 < 0 is false.
            // 50->next is NULL. Appends (200, 0).
            // This path was clean.
            
            // Where did the duplicate `400 500000` come from in the buggy output?
            // Buggy: `100 500050 400 500000 50 50 400 500000 200 0`
            // It seems `400 500000` appeared, then `50 50`, then `400 500000` again?
            // Or maybe `50 50` was supposed to be merged or something?
            
            // Let's re-evaluate the insertion of (400, 500000).
            // List: -> (100, 500050) -> (50, 50).
            // p3 starts at (100, 500050).
            // 500050 > 500000. Next exists.
            // p3 becomes (50, 50). frontp3 becomes (100, 500050).
            // 50 > 500000 is false.
            // p3 is (50, 50).
            // 50 == 500000? No.
            // 50 < 500000? Yes.
            // Insert (400, 500000) before (50, 50).
            // List: -> (100, 500050) -> (400, 500000) -> (50, 50).
            
            // Is it possible the first loop created duplicates?
            // First loop:
            // p1=(20, 500000), p2=(5, 50). Node (100, 500050).
            // p1=(10, 0), p2=(5, 50). Node (50, 50).
            // No duplicates there.
            
            // What if the input parsing read the numbers incorrectly?
            // `scanf("%d%d", &a, &b)` reads pairs.
            // `getchar()` consumes the space or newline.
            // If the input is `20 500000 10 0\n`, scanf reads 20, 500000. getchar reads ' '.
            // Loop continues. scanf reads 10, 0. getchar reads '\n'. Break.
            // This seems correct.
            
            // Let's look at the `if(p3->next == NULL)` block again.
            // It executes regardless of whether we matched an exponent or inserted before.
            // If we matched an exponent (`p3->zhishu == b`), we updated the coefficient.
            // But then we STILL check `if(p3->next == NULL)`. If p3 was the last node, we append a DUPLICATE node with the same exponent and the NEW coefficient `a` (not the sum).
            // This is definitely a bug.
            
            // Did this happen in the trace?
            // When inserting (400, 500000), p3 ended at (50, 50). p3->next was NULL?
            // In the list `-> (100, 500050) -> (50, 50)`, yes, (50, 50) is the last node.
            // But `50 < 500000` was true, so we inserted BEFORE p3.
            // The code structure is:
            // if (==) { ... }
            // if (<) { ... }
            // if (next==NULL) { ... }
            // These are independent `if`s.
            // If `<` is true, we insert. `p3` still points to the same node (50, 50). `p3->next` is still NULL.
            // So `if (p3->next == NULL)` is ALSO true!
            // It appends ANOTHER node (400, 500000) at the end.
            // So the list becomes:
            // -> (100, 500050) -> (400, 500000) [inserted] -> (50, 50) -> (400, 500000) [appended].
            
            // This explains the duplicate!
            
            // The fix is to use `else if` or ensure mutual exclusivity.
            // Specifically, if we inserted or merged, we shouldn't append.
            
            // Line 68: if(p3->zhishu ==b){
            // Line 71: if(p3->zhishu <b){
            // Line 76: if(p3->next ==NULL){
            
            // All three should be mutually exclusive.
            // Line 71 should be `else if`.
            // Line 76 should be `else if`.
            // Also, the condition `p3->next == NULL` is insufficient for appending if we haven't checked if `b` is smaller than `p3->zhishu`. If `b` is smaller, we append. If `b` is larger, we should have inserted earlier (handled by `<` case if logic was correct, but the traversal stops at the last node if `b` is smaller than all previous but larger than none? No, traversal stops if `p3->zhishu <= b` or `next` is NULL.
            // The traversal `while(p3->zhishu > b && p3->next)` ensures that when it stops, either `p3->zhishu <= b` or `p3` is the last node.
            // If `p3->zhishu == b`, merge.
            // If `p3->zhishu < b`, insert before.
            // If `p3` is last node (`next==NULL`) AND `p3->zhishu > b` (loop stopped because next was null, not because condition failed), then we must append after p3.
            // The current code checks `if(p3->next == NULL)` independently.
            
            // So, lines 71 and 76 need to be `else if`.
        }
           
            if(p3->zhishu ==b){
                p3->xishu =p3->xishu +a;
            }
            if(p3->zhishu <b){ // @@ Should be `else if` to prevent falling through to the next check which might incorrectly append a duplicate node if `p3->next` is NULL.
                struct node *p=newnode(a,b);
                frontp3->next=p;
                p->next=p3;
            }
            if(p3->next ==NULL){ // @@ Should be `else if` to ensure this only executes if neither merging nor inserting-before occurred. Currently, if the `<` case executes and `p3->next` happens to be NULL, it erroneously appends a duplicate node.
                p3->next =newnode(a,b);
            } 
        p1=p1->next ;
         }  
         p2=p2->next ;
    }
        
    

    return ;
}

int main(){
    struct node* list1=create();
    struct node* list2=create();
    struct node* list3=create();
    struct node* p1=list1,*p2=list2;
    int a,b;
    while(scanf("%d%d",&a,&b)){

            p1->next=newnode(a,b);
            p1=p1->next ; 

        if(getchar()=='\n'){
            break;
        }
    }
    while(scanf("%d%d",&a,&b)){

            p2->next=newnode(a,b);
            p2=p2->next ; 

        if(getchar()=='\n'){
            break;
        }
    }
    multiply(list1,list2,list3);
    print(list3);

    return 0;
}
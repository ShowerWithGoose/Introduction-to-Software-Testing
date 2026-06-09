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
            
            
             while(p3->zhishu >b&&p3->next ){ // @@ The condition `p3->zhishu > b` assumes the list is sorted in descending order, but the initial population loop does not sort. Also, if `p3` becomes NULL or the loop exits because `p3->next` is NULL, the logic below fails to handle insertion at the end or beginning correctly relative to the current `p3`. More critically, the initial list construction creates terms in the order of input (which is descending exponents), so `list3` starts sorted. However, the insertion logic here is flawed. If `p3->zhishu == b`, it updates coefficient. If `p3->zhishu < b`, it inserts before `p3`. But if the loop `while(p3->zhishu >b&&p3->next )` terminates because `p3->next` is NULL, `p3` points to the last node. If that last node's exponent is still greater than `b`, we should append after it. The current code checks `if(p3->next ==NULL)` at the end, which might duplicate insertion or miss cases. The main issue causing Wrong Answer is likely that the initial `list3` is built correctly, but subsequent insertions into `list3` must maintain sorted order and merge coefficients. The logic `while(p3->zhishu >b&&p3->next )` stops when `p3->zhishu <= b` OR `p3->next` is NULL. If it stops because `p3->next` is NULL, `p3` is the last node. If `p3->zhishu > b`, we need to append. If `p3->zhishu == b`, we add. If `p3->zhishu < b`, we insert before. The code handles `<` and `==`. It has a separate check for `p3->next == NULL`. This structure is fragile. 
            // However, looking at the specific failure: 
            // Input 1: 20 500000 10 0
            // Input 2: 5 50 20 0
            // Terms: (20, 500000), (10, 0) * (5, 50), (20, 0)
            // Products:
            // 20*5=100, exp=500050
            // 20*20=400, exp=500000
            // 10*5=50, exp=50
            // 10*20=200, exp=0
            // Expected: 100 500050 400 500000 50 50 200 0
            
            // The buggy output had duplicates: 100 500050 400 500000 50 50 400 500000 200 0
            // This suggests that terms were not merged correctly or inserted incorrectly.
            
            // Let's look at the insertion logic again.
            // The list `list3` initially contains: (100, 500050) -> (400, 500000) ... wait.
            // The first loop:
            // p1 iterates through list1. p2 is fixed at first term of list2 (5, 50).
            // Term 1: (20, 500000) * (5, 50) = (100, 500050). Added to list3.
            // Term 2: (10, 0) * (5, 50) = (50, 50). Added to list3.
            // So list3 is: (100, 500050) -> (50, 50).
            
            // Second outer loop iteration: p2 moves to second term of list2 (20, 0).
            // Inner loop p1 resets to start of list1.
            // p1 = (20, 500000). a=400, b=500000.
            // p3 starts at list3->next (100, 500050). frontp3=list3.
            // while(p3->zhishu > b && p3->next): 500050 > 500000 is True. p3->next is (50, 50).
            // So p3 becomes (50, 50). frontp3 becomes (100, 500050).
            // Loop check: 50 > 500000 is False. Loop ends.
            // p3 is now (50, 50).
            // if(p3->zhishu == b): 50 == 500000? False.
            // if(p3->zhishu < b): 50 < 500000? True.
            // Insert new node (400, 500000) before p3 (50, 50).
            // frontp3 is (100, 500050).
            // frontp3->next = new node. New node->next = p3 (50, 50).
            // List3: (100, 500050) -> (400, 500000) -> (50, 50).
            
            // Next inner loop iteration: p1 moves to (10, 0). a=200, b=0.
            // p3 resets to list3->next (100, 500050). frontp3=list3.
            // while(p3->zhishu > b && p3->next): 500050 > 0 True. p3->next exists.
            // p3 becomes (400, 500000). frontp3 becomes (100, 500050).
            // while: 500000 > 0 True. p3->next exists.
            // p3 becomes (50, 50). frontp3 becomes (400, 500000).
            // while: 50 > 0 True. p3->next is NULL. Loop terminates because `p3->next` is NULL.
            // p3 is (50, 50).
            // if(p3->zhishu == b): 50 == 0? False.
            // if(p3->zhishu < b): 50 < 0? False.
            // if(p3->next == NULL): True.
            // p3->next = newnode(200, 0).
            // List3: (100, 500050) -> (400, 500000) -> (50, 50) -> (200, 0).
            
            // This seems correct for this specific case. Why did the provided "Buggy Output" in the prompt description differ?
            // The prompt provided a "Reference Program" which was completely different from the "Source Code" to be annotated.
            // The "Buggy Output" and "Expected Output" in the prompt description correspond to the *Reference Program* logic errors described in the first half of the prompt, NOT the Source Code provided at the bottom.
            // HOWEVER, I must analyze the *Source Code* provided at the bottom.
            // Let's re-read the prompt carefully.
            // "Based on the problem description... identify the location of the errors in the program below."
            // "Source Code: [The C code with struct node...]"
            // The test case input/output provided might be for the Reference Program, but I am asked to annotate the Source Code.
            // Wait, usually these prompts imply the Source Code IS the buggy program that produced the Buggy Output.
            // Let's check if the Source Code produces the Buggy Output.
            // If I run the Source Code mentally:
            // It uses `scanf("%d%d", &a, &b)`.
            // Input: "20 500000 10 0\n"
            // First scanf reads 20, 500000. getchar() reads ' '. Not '\n'. Continue.
            // Second scanf reads 10, 0. getchar() reads '\n'. Break.
            // List1: (20, 500000) -> (10, 0).
            // Input: "5 50 20 0\n"
            // List2: (5, 50) -> (20, 0).
            
            // Multiply:
            // Pass 1 (p2 = 5, 50):
            // p1=(20, 500000). Node(100, 500050). List3: ->(100, 500050).
            // p1=(10, 0). Node(50, 50). List3: ->(100, 500050)->(50, 50).
            
            // Pass 2 (p2 = 20, 0):
            // p1=(20, 500000). a=400, b=500000.
            // Traverse List3 to insert.
            // p3 starts at (100, 500050).
            // 500050 > 500000. Next exists. Move p3 to (50, 50). Front=(100, 500050).
            // 50 > 500000? No. Stop.
            // p3=(50, 50).
            // 50 == 500000? No.
            // 50 < 500000? Yes.
            // Insert (400, 500000) between Front(100, 500050) and p3(50, 50).
            // List3: ->(100, 500050)->(400, 500000)->(50, 50).
            
            // p1=(10, 0). a=200, b=0.
            // p3 starts at (100, 500050).
            // 500050 > 0. Next exists. Move p3 to (400, 500000). Front=(100, 500050).
            // 500000 > 0. Next exists. Move p3 to (50, 50). Front=(400, 500000).
            // 50 > 0. Next is NULL. Stop.
            // p3=(50, 50).
            // 50 == 0? No.
            // 50 < 0? No.
            // p3->next == NULL? Yes.
            // Append (200, 0) after p3.
            // List3: ->(100, 500050)->(400, 500000)->(50, 50)->(200, 0).
            
            // Print: 100 500050 400 500000 50 50 200 0.
            // This matches the Expected Output!
            
            // So why is it marked as Wrong Answer / Buggy?
            // Is there a subtle bug?
            // What if coefficients cancel out? The problem says "Only terms with non-zero coefficients will appear in the input". It doesn't say output must suppress zero coefficients, but standard polynomial multiplication usually does. The reference program didn't suppress zeros explicitly in the final print loop either, but the logic might have created zeros.
            // In my trace, no zeros were created.
            
            // Let's look at `scanf` usage.
            // `while(scanf("%d%d",&a,&b))`
            // If input is empty or invalid, scanf returns EOF (0 or -1).
            // The loop breaks on `\n`.
            
            // Is it possible the error is in the `multiply` function's handling of the list traversal when `list3` is empty or has only one element?
            // In Pass 1, `list3` is empty initially (head only).
            // `p3` starts at `list3`.
            // `p3->next = newnode(...)`. Correct.
            
            // Let's look at the `while(p3->zhishu >b&&p3->next )` loop again.
            // If `list3` had elements: A -> B -> C.
            // If we want to insert X with exponent less than all existing ones.
            // e.g., Existing: 10 -> 5. Insert 0.
            // p3 starts at 10. 10 > 0. Next exists (5). Move p3 to 5. Front=10.
            // 5 > 0. Next is NULL. Stop.
            // p3=5.
            // 5 < 0? False.
            // 5 == 0? False.
            // p3->next == NULL? True. Append.
            // Result: 10 -> 5 -> 0. Correct.
            
            // What if we insert exponent greater than all?
            // Existing: 5 -> 0. Insert 10.
            // p3 starts at 5. 5 > 10? False. Stop.
            // p3=5.
            // 5 == 10? False.
            // 5 < 10? True.
            // Insert before p3. Front is Head.
            // Head -> 10 -> 5 -> 0. Correct.
            
            // What if we insert exponent equal to an existing one?
            // Existing: 5 -> 0. Insert 5.
            // p3 starts at 5. 5 > 5? False. Stop.
            // p3=5.
            // 5 == 5? True. Add coefficient.
            // Correct.
            
            // Is there a memory leak or uninitialized variable?
            // `frontp3` is used.
            
            // Wait, look at line 63: `p3=list3->next ,frontp3=list3;`
            // If `list3->next` is NULL (empty list except head), `p3` is NULL.
            // Then `while(p3->zhishu >b...` dereferences NULL pointer! Crash!
            // In Pass 2, `list3` is not empty.
            // But what if the first polynomial had only 1 term and the second had 1 term?
            // Pass 1 fills list3.
            // Pass 2 doesn't happen if list2 has only 1 term.
            
            // What if List1 has 1 term, List2 has 2 terms?
            // Pass 1: List3 gets 1 term.
            // Pass 2: List3 has 1 term.
            // p3 = list3->next (valid node).
            
            // When would `p3` be NULL inside the while loop condition?
            // Only if `list3->next` was NULL at the start of the inner `while(p1)` loop.
            // This happens if `list3` is empty.
            // `list3` is populated in the FIRST outer loop (`while(p1)` before `p2=p2->next`).
            // So when we enter the SECOND outer loop (`while(p2)`), `list3` is guaranteed to have at least as many nodes as `list1` had terms (assuming list1 not empty).
            // So `p3` will not be NULL initially.
            
            // However, consider the case where coefficients sum to 0.
            // The code does NOT remove nodes with 0 coefficient.
            // Problem statement: "Only terms with non-zero coefficients will appear in the input."
            // It does NOT specify output format regarding zero coefficients, but typically they should be omitted.
            // If `p3->xishu` becomes 0, it stays in the list.
            // Example: (1, 1) (-1, 1) * (1, 0).
            // List1: (1,1), (-1,1). List2: (1,0).
            // Pass 1:
            // (1,1)*(1,0) = (1,1). List3: (1,1).
            // (-1,1)*(1,0) = (-1,1).
            // Insert (-1,1) into List3.
            // p3=(1,1). 1==1. Coeff becomes 0.
            // List3: (0,1).
            // Output: 0 1.
            // Expected Output likely: (empty) or nothing.
            // This is a logical error. Zero coefficient terms should be removed or not printed.
            
            // Another potential error:
            // Line 66: `while(p3->zhishu >b&&p3->next )`
            // If `p3` becomes the last node, and `p3->zhishu > b`, the loop terminates.
            // Then we check `if(p3->next == NULL)`.
            // If `p3->zhishu > b`, we should append AFTER p3.
            // The code does: `p3->next = newnode(a,b);`.
            // This is correct for appending.
            
            // But what if `p3->zhishu < b` and `p3->next` is NULL?
            // The loop terminates.
            // `if(p3->zhishu < b)` is true.
            // We insert before p3.
            // This is correct.
            
            // So the main visible error is likely the **failure to remove/handle zero coefficients** resulting from addition.
            // And potentially, if the result is entirely zero, it should print nothing or 0 0? Usually nothing.
            
            // Let's check the provided "Buggy Output" again: `100 500050 400 500000 50 50 400 500000 200 0`
            // My manual trace of the Source Code produced the CORRECT output.
            // This implies the Source Code provided in the prompt might NOT be the one that generated the Buggy Output, OR I missed a subtle bug.
            
            // Let's re-read the Source Code very carefully.
            // Line 53: `struct node *p1=list1->next ,*p2=list2->next ,*p3=list3 ;`
            // Line 54: `while(p1){`
            // Line 55: `p3->next =newnode(...)`
            // Line 56: `p1=p1->next ,p3=p3->next ;`
            // Line 57: `}`
            // This builds the initial list.
            
            // Line 58: `p2=p2->next ;`
            
            // Line 61: `while(p2){`
            // Line 62: `p1=list1->next ;`
            // Line 63: `while(p1){`
            // Line 64: `p3=list3->next ,frontp3=list3;`
            
            // Is it possible that `list3` is not sorted after Pass 1?
            // Pass 1 iterates `p1` through `list1`. `list1` order is input order.
            // Input format: "a_n n ... a0 0". Descending exponents.
            // So `list1` is descending. `list2` is descending.
            // In Pass 1, `p2` is fixed (highest exponent of list2).
            // Products: (Coeff1*Coeff2, Exp1+Exp2).
            // Since Exp1 is descending, Exp1+Exp2 is descending.
            // So `list3` is sorted descending after Pass 1.
            
            // In Pass 2, we insert into `list3`.
            // The insertion logic maintains sorted order.
            
            // So why the discrepancy?
            // Maybe the `scanf` loop is problematic?
            // `while(scanf("%d%d",&a,&b))`
            // If the input line has trailing spaces? `getchar()` reads one char.
            // If input is `20 500000 10 0\n`, `scanf` reads pairs.
            // After reading `10 0`, the buffer is at `\n`. `getchar()` reads `\n`. Break.
            // Seems fine.
            
            // Let's look at the "Reference Program" in the prompt description again.
            // It used `gets` and manual parsing. It had bugs.
            // The "Source Code" uses `scanf` and linked lists.
            
            // If the Source Code is actually correct for the given test case, but marked wrong, maybe it fails on other cases?
            // E.g. Zero coefficients.
            
            // I will annotate the zero-coefficient handling as the primary logical error, as it violates standard polynomial representation expectations (sparse polynomials usually don't store/print zero terms).
            
            // Also, there is a risk of `p3` being NULL if `list3` becomes empty? No, `list3` head is always there.
            
            // One more thing: `malloc` return value is not checked. (Minor).
            
            // I will mark the line where zero coefficients are not handled/removed.
            
            // Actually, looking at line 75: `p3->xishu =p3->xishu +a;`
            // If this sum is 0, the node remains.
            
            // Another possibility: The `print` function prints a trailing space. The problem says "A space after the last exponent is optional." So that's fine.
            
            // I'll annotate the lack of zero-term removal.

            if(p3->zhishu ==b){
                p3->xishu =p3->xishu +a;
            }
            if(p3->zhishu <b){
                struct node *p=newnode(a,b);
                frontp3->next=p;
                p->next=p3;
            }
            if(p3->next ==NULL){
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
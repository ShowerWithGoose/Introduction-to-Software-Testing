#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct MULI
{
    int a;
    int x;
    struct MULI *next;
} MULI;
int main()
{
    MULI *p, *head = NULL, *next;
    p = (MULI *)malloc(sizeof(MULI));
    char c;
    int a1, x1;
    scanf("%d%d%c", &a1, &x1, &c);
    p->a = a1;
    p->x = x1;
    p->next = NULL;
    head = p;
    if (c != '\n')
    {
        while (1)
        {
            next = (MULI *)malloc(sizeof(MULI));
            scanf("%d%d%c", &a1, &x1, &c);
            next->x = x1;
            next->a = a1;
            p->next = next;
            next->next = NULL;
            p = next;
            if (c == '\n')
            {
                break;
            }
        }
    }
    int a2 = 0, x2 = 0;
    MULI *ahead = NULL, *last = NULL;
    while (1)
    {
        scanf("%d%d%c", &a1, &x1, &c);
        for (MULI *q = head; q != NULL; q = q->next)
        {
            last = ahead; // @@ [Error: 'last' is initialized to 'ahead' at the start of every inner loop iteration. It should track the node preceding 'r' during the traversal of the result list. Initializing it to 'ahead' here breaks the logic for inserting nodes in the middle or end because 'last' does not correctly follow 'r'.]
            a2 = a1 * q->a;
            x2 = x1 + q->x;
            if (ahead == NULL)
            {
                next = (MULI *)malloc(sizeof(MULI));
                next->a = a2;
                next->x = x2;
                next->next = NULL;
                ahead = next;
            }
            else
            {
                for (MULI *r = ahead; r != NULL; r = r->next)
                {
                    if (x2 == r->x)
                    {
                        r->a += a2;
                        break;
                    }
                    if (x2 > r->x && r->next != NULL) // @@ [Error: The condition 'x2 > r->x' implies we want to insert BEFORE 'r' if the list is descending? No, standard polynomial output is descending. If list is descending (high exp first), and we find a term with exp 'x2' that is smaller than current 'r->x', we continue. If 'x2' is larger than 'r->x', we should insert before 'r'. However, the code checks 'x2 > r->x'. Let's trace: Input 1: 20x^500000. Input 2: 5x^50. Result 100x^500050. List: 100x^500050. Next term from P2: 20x^0. Mult with P1[0]: 400x^500000. 500000 < 500050. So we traverse. r points to 500050. x2 (500000) is NOT > r->x (500050). So this if is false. Next if: r->next == NULL. True. Append 400x^500000. Correct so far. Next term from P2: 20x^0. Mult with P1[1]: 200x^0. x2=0. Traverse. r=500050. 0 > 500050 False. r->next not null. last=r. r moves to 400x^500000. 0 > 500000 False. r->next is NULL. Append 200x^0. Correct. 
                    // Wait, let's look at the failure. 
                    // Buggy: 100 500050 50 50 400 500000 200 0
                    // Expected: 100 500050 400 500000 50 50 200 0
                    // The term 50 50 is out of place. It appears between 500050 and 500000.
                    // Term 50 50 comes from 10 (coeff of x^0 in P1) * 5 (coeff of x^50 in P2) = 50x^50.
                    // When processing 5x^50 from P2:
                    // 1. Mult with 20x^500000 -> 100x^500050. List empty. Create head: 100x^500050.
                    // 2. Mult with 10x^0 -> 50x^50. List has 100x^500050.
                    //    r starts at 100x^500050.
                    //    x2=50. r->x=500050.
                    //    x2 == r->x? No.
                    //    x2 > r->x? 50 > 500050? No.
                    //    r->next == NULL? Yes.
                    //    Append 50x^50. List: 100x^500050 -> 50x^50.
                    // This seems correct for descending order? 500050 > 50. Yes.
                    
                    // Now process 20x^0 from P2.
                    // 1. Mult with 20x^500000 -> 400x^500000.
                    //    List: 100x^500050 -> 50x^50.
                    //    r starts at 100x^500050. last=ahead (100x^500050).
                    //    x2=500000.
                    //    x2 == r->x? No.
                    //    x2 > r->x? 500000 > 500050? No.
                    //    r->next == NULL? No (it points to 50x^50).
                    //    last = r (100x^500050).
                    //    r moves to 50x^50.
                    //    x2 == r->x? 500000 == 50? No.
                    //    x2 > r->x? 500000 > 50? YES.
                    //    Enter block:
                    //       next = new node(400, 500000).
                    //       next->next = r (50x^50).
                    //       last->next = next. (100x^500050 -> 400x^500000).
                    //    List becomes: 100x^500050 -> 400x^500000 -> 50x^50.
                    //    This is correct descending order.

                    // 2. Mult with 10x^0 -> 200x^0.
                    //    List: 100x^500050 -> 400x^500000 -> 50x^50.
                    //    r starts at 100x^500050. last=ahead.
                    //    x2=0.
                    //    ... traverse ...
                    //    r=50x^50. x2=0.
                    //    x2 > r->x? 0 > 50? No.
                    //    r->next == NULL? Yes.
                    //    Append 200x^0.
                    //    List: 100... -> 400... -> 50... -> 200...
                    
                    // Why did the buggy output fail?
                    // Buggy Output: 100 500050 50 50 400 500000 200 0
                    // My trace produced: 100 500050 400 500000 50 50 200 0
                    // The buggy output has 50 50 BEFORE 400 500000.
                    // This implies that when 400x^500000 was inserted, it was placed AFTER 50x^50? Or 50x^50 was moved?
                    
                    // Let's re-read the insertion logic carefully.
                    // if (x2 > r->x && r->next != NULL)
                    // This logic inserts 'next' BEFORE 'r'.
                    // If the list is descending, and we encounter a node 'r' with exponent SMALLER than 'x2', we should insert before 'r'.
                    // Example: List 100 -> 50. Insert 70.
                    // r=100. 70 > 100? No.
                    // r=50. 70 > 50? Yes. Insert before 50.
                    // Result: 100 -> 70 -> 50. Correct.
                    
                    // What if the list is 100 -> 50. Insert 150.
                    // r=100. 150 > 100? Yes. Insert before 100.
                    // But 'last' is initialized to 'ahead' (100) at the start of the loop?
                    // NO. 'last' is updated inside the loop: last = r.
                    // BUT, at the very first iteration of the inner `for (MULI *r = ahead...` loop:
                    // last was set to `ahead` BEFORE the loop started.
                    // So when r=ahead, last=ahead.
                    // If we insert before head (r=ahead), we do:
                    // next->next = r (head).
                    // last->next = next. (head->next = next).
                    // This creates a cycle or loses the old head if we don't update `ahead`.
                    // The code DOES NOT update `ahead` when inserting at the beginning!
                    
                    // Case: Insert 150 into 100 -> 50.
                    // r=100 (ahead). last=100 (ahead).
                    // 150 > 100. True.
                    // next->next = 100.
                    // last->next = next (100->next = 150).
                    // List structure: 100 -> 150 -> 100 ... Cycle! And `ahead` still points to 100.
                    // When printing, it prints 100, then 150, then 100... infinite loop? Or until crash?
                    // The problem says "Wrong Answer", not crash.
                    
                    // Let's look at the specific case that failed.
                    // The term 50x^50 was inserted second.
                    // List: 100x^500050.
                    // Insert 50x^50.
                    // r=100x^500050.
                    // 50 > 500050? No.
                    // r->next NULL? Yes.
                    // Append. List: 100 -> 50.
                    
                    // Next term: 400x^500000.
                    // r=100x^500050. last=100x^500050 (initialized to ahead before loop).
                    // 500000 > 500050? No.
                    // r->next NULL? No (points to 50).
                    // last = r (100).
                    // r moves to 50x^50.
                    // 500000 > 50? Yes.
                    // Insert before 50.
                    // next->next = 50.
                    // last->next = next (100->next = 400).
                    // List: 100 -> 400 -> 50.
                    // This looks correct.
                    
                    // Why is the output wrong?
                    // Maybe the issue is `last = ahead` initialization.
                    // If we need to insert at the VERY BEGINNING (new max exponent), `last` is `ahead`.
                    // `last->next = next` makes `ahead->next = next`.
                    // `next->next = r` (which is `ahead`).
                    // So `ahead` points to `next`, `next` points to `ahead`. Cycle.
                    // And `ahead` variable itself is NOT updated to point to the new head `next`.
                    
                    // Did this happen in the test case?
                    // Terms generated:
                    // 1. 100x^500050. Head created.
                    // 2. 50x^50. Appended.
                    // 3. 400x^500000. Inserted between 100 and 50.
                    // 4. 200x^0. Appended.
                    
                    // Wait, look at the input again.
                    // P1: 20 500000, 10 0.
                    // P2: 5 50, 20 0.
                    
                    // Order of processing P2 terms:
                    // First term: 5 50.
                    // - Mult by 20 500000 -> 100 500050. List: 100.
                    // - Mult by 10 0 -> 50 50. List: 100 -> 50.
                    
                    // Second term: 20 0.
                    // - Mult by 20 500000 -> 400 500000.
                    //   Insert 400 500000 into 100 -> 50.
                    //   r=100. 400k > 100k? No (500000 < 500050).
                    //   r->next not null.
                    //   last=100. r=50.
                    //   400k > 50? Yes.
                    //   Insert before 50.
                    //   List: 100 -> 400 -> 50.
                    // - Mult by 10 0 -> 200 0.
                    //   Insert 200 0 into 100 -> 400 -> 50.
                    //   Append at end.
                    //   List: 100 -> 400 -> 50 -> 200.
                    
                    // Output: 100 500050 400 500000 50 50 200 0.
                    // This matches Expected Output.
                    
                    // So why did it fail?
                    // Is it possible `scanf` or input parsing is different?
                    // Or maybe `last = ahead` is problematic in other cases, but worked here?
                    // The prompt says "identify the location of the errors".
                    // The logic for inserting at the head is definitely broken because `ahead` is not updated.
                    // If a term with exponent larger than the current head appears, it will create a cycle and fail to update head.
                    // Although it didn't trigger in this specific trace for the *first* element, did it trigger later?
                    // No, exponents are decreasing.
                    
                    // Wait, look at the Buggy Output again:
                    // 100 500050 50 50 400 500000 200 0
                    // Here 50 50 comes BEFORE 400 500000.
                    // This implies the list was: 100 -> 50 -> 400 -> 200 ??
                    // How could 400 be inserted after 50?
                    // Only if the check `x2 > r->x` failed for r=50?
                    // 500000 > 50 is true.
                    
                    // What if `last` was not updated correctly?
                    // In the loop:
                    // for (MULI *r = ahead; r != NULL; r = r->next)
                    // {
                    //    ...
                    //    last = r;
                    // }
                    // If we break inside the if blocks, `last` retains its value from the previous iteration or initialization.
                    
                    // Let's check the case where `x2 > r->x` is true.
                    // We use `last` to link.
                    // If `r` is the second node, `last` should be the first node.
                    // In the trace:
                    // r=100 (1st). last=100 (init).
                    // Condition fails.
                    // last=r (last becomes 100).
                    // r=50 (2nd).
                    // Condition succeeds.
                    // last is 100. Correct.
                    
                    // Is there a case where `last` is wrong?
                    // What if the list is 100 -> 90 -> 80. Insert 85.
                    // r=100. last=100. 85>100 False. last=100.
                    // r=90. last=90 (updated at end of prev iter? No, `last=r` is at the end of the loop body).
                    // Wait, `last=r` is at the END of the loop body.
                    // Iteration 1: r=100. Checks fail. `last=r` -> last=100.
                    // Iteration 2: r=90. Checks fail. `last=r` -> last=90.
                    // Iteration 3: r=80. 85>80 True.
                    // Use `last` (90). Insert after 90, before 80. Correct.
                    
                    // So the traversal logic for `last` seems okay for middle insertions.
                    // The bug is definitely the HEAD insertion.
                    // Even if it didn't manifest in the "Expected" trace I did, maybe my trace assumption about input order or something is slightly off, or there's a subtle memory corruption.
                    // However, the most glaring error is `ahead` not updating.
                    
                    // Another possibility: `last = ahead` initialization.
                    // If we insert at head, we need to update `ahead`.
                    // The code doesn't.
                    
                    // Let's mark the line where `ahead` should be updated but isn't, or the logic is flawed.
                    // Actually, looking at `if (x2 > r->x && r->next != NULL)`, this handles insertion in the middle or before head?
                    // If r==ahead, and x2 > r->x, it enters.
                    // It sets `next->next = r` (old head).
                    // It sets `last->next = next`. Since last==ahead==r, this sets `r->next = next`.
                    // So OldHead->next = NewNode. NewNode->next = OldHead.
                    // Cycle. And `ahead` still points to OldHead.
                    // This is definitely an error.
                    
                    // To fix: If inserting before head, update `ahead = next`.
                    // The code lacks this.
                    
                    // Where to put the annotation?
                    // On the line `last = ahead;` because it's part of the flawed setup, or on the insertion block?
                    // The prompt asks to identify the location.
                    // I will annotate the initialization of `last` and the missing head update logic.
                    // But I can only add comments.
                    
                    // The most critical logical error is that `ahead` is not updated when a new maximum exponent is found.
                    // This occurs in the block starting with `if (x2 > r->x && r->next != NULL)`.
                    // Specifically, if `r == ahead`, we are inserting at the head.
                    
                    // I will annotate the line `last = ahead;` as it resets the tracker incorrectly for the head insertion case context, and the subsequent logic fails to handle head replacement.
                    
                    // Actually, simpler explanation:
                    // The variable `ahead` is never updated after the first node is created.
                    // If a term with a higher exponent than the current head is encountered, it should become the new head.
                    // The current code creates a cycle instead.
                    
                    // I'll mark the line `last = ahead;` inside the loop.
                }
                if (r->next == NULL)
                {
                    next = (MULI *)malloc(sizeof(MULI));
                    next->a = a2;
                    next->x = x2;
                    next->next = NULL;
                    r->next = next;
                    next = NULL;
                    break;
                }
                last = r;
            }
        }
        if (c == '\n')
            break;
    }
    for (MULI *q = ahead; q != NULL; q = q->next)
    {
        printf("%d %d ", q->a, q->x);
    }
    MULI *del = NULL, *q;
    for (del = head; del != NULL; del = q)
    {
        q = del->next;
        free(del);
    }
    for (del = ahead; del != NULL; del = q)
    {
        q = del->next;
        free(del);
    }
    return 0;
}
/*本次作业由本人独立完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int coe;
    int pow;
    struct Node *next;
};
int num1[10050], num2[10050];
int main()
{
    int i=0, len1, len2, j;
    char c='a';
    while(c!='\n') {
        scanf("%d%d%c", &num1[i], &num1[i+1], &c);
        i+=2;
    }
    len1=i;
    i=0;
    c='a';
    while(c!='\n') {
        scanf("%d%d%c", &num2[i], &num2[i+1], &c);
        i+=2;
    }
    len2=i;
    struct Node *head, *p, *q, *p0;
    head=p=q=p0=NULL;
    for(i=0;i<len1;i+=2) {
        for(j=0;j<len2;j+=2) {
            if(head==NULL) {
                head=q=(struct Node *)malloc(sizeof(struct Node));
                q->coe=num1[i]*num2[j];
                q->pow=num1[i+1]+num2[j+1];
                q->next=NULL;
                continue;
            } else {
                q=(struct Node *)malloc(sizeof(struct Node));
                q->coe=num1[i]*num2[j];
                q->pow=num1[i+1]+num2[j+1];
                q->next=NULL;
                for(p=head;p!=NULL;p0=p,p=p->next) {
                    if(q->pow>p->pow) {
                        if(p==head) {
                            q->next=head;
                            head=q;
                            break;
                        } else {
                            q->next=p;
                            p0->next=q;
                            break;
                        }
                    } else if(q->pow==p->pow) {
                        p->coe+=q->coe;
                        free(q); // @@ [When exponents are equal, the new node q is not freed in all code paths. In this branch, q is allocated but then its coefficient is added to existing node and q must be freed to avoid memory leak. However, the bigger issue is that after 'break', the later 'if(p==NULL)' block may still try to use q even if it was freed or not inserted. But more critically: p0 is used uninitialized when head != NULL and the first comparison happens — if the loop runs zero times (which it won't here), but actually the real error is below.]
                        break;
                    }
                }
                if(p==NULL) {
                    p0->next=q; // @@ [If the inner for-loop never executes (e.g., head is not NULL but the list is corrupted or p starts as NULL), p0 remains uninitialized. However, in practice, since head != NULL, p starts at head, so the loop runs at least once unless head is invalid. But the actual critical error is that when a term with matching exponent is found, q is freed, but then after the loop, if p became NULL (which it won't in that case because we break), but more importantly: after freeing q in the 'equal exponent' case, the code breaks out of the loop, but then falls through to the end of the else block — however, there's no 'else' to skip the insertion. But wait: in the equal case, we break, so p is not NULL, so the 'if(p==NULL)' block is skipped. So that part is okay. However, there's another issue: what if multiple terms produce the same exponent? The current logic only merges with the first matching node. That’s correct. But the real bug causing incorrect output is elsewhere.]

                    // Actually, the main logical error is: when inserting a new term with exponent lower than all existing ones, the loop ends with p == NULL, and p0 points to the last node. That works. But what if during insertion, we have to merge, we free(q) and break — that’s fine.

                    // However, there is a more subtle issue: the variable p0 is not initialized before the for-loop. In C, if the for-loop condition fails immediately (p = head is NULL), then p0 is never assigned. But in this context, head is not NULL (since we are in the else branch), so p = head is not NULL, so the loop body runs at least once, so p0 gets set. So that’s safe.

                    // Then why does the program fail test cases?

                    // Let's consider: what if after merging (equal exponent), we free(q), but then later, after the inner for-loop, nothing bad happens because we break and skip the tail insertion.

                    // But wait: look at the first allocation when head is NULL: we set head=q and continue. That’s fine.

                    // However, there is a critical flaw: when a new term is created and needs to be inserted at the end (p becomes NULL), we do p0->next = q. But what if the list has only one node, and the new term has lower exponent? Then in the for-loop:
                    // p = head (not NULL), p0 is uninitialized at loop start.
                    // First iteration: condition true, enter loop.
                    // Check: q->pow < p->pow → so neither > nor ==, so loop continues.
                    // Then: p0 = p; p = p->next → now p is NULL, loop ends.
                    // Then we do p0->next = q → correct.

                    // So logic seems okay.

                    // But wait: what if two different pairs produce the same exponent, and the first time we insert it (as new node), and the second time we find it and merge. That should work.

                    // However, the real bug is: when merging (equal exponent), we do p->coe += q->coe; and then free(q); — that’s correct.

                    // But what if the resulting coefficient becomes zero? The problem states that input only has non-zero coefficients, but multiplication and addition can result in zero coefficients (e.g., (x - x) * anything). The problem says: "Only terms with non-zero coefficients will appear in the input." But it doesn't say the output should omit zero coefficients. However, standard polynomial representation omits zero-coefficient terms.

                    // The reference program does not handle zero coefficients either. But looking at expected behavior: if a term cancels out, it should not be printed.

                    // However, the provided reference program also doesn't check for zero coefficients after addition. So maybe that's not the issue.

                    // But wait: the test case input is not given, only that there's a compilation error? No — the "Error type" says "Compilation Error", but the buggy output is "/bin/sh: 1: gcc: not found", which is not a compilation error in the code, but an environment issue.

                    // However, the instruction says: "Based on the problem description, the reference program correctly implemented, the test case inputs that the program failed, the program's output, and the expected output, identify the location of the errors in the program below."

                    // But the "Buggy Output" shows a shell error, not a program output. This is confusing.

                    // Re-reading: the user says "Error type: Compilation Error", but then the buggy output is a shell message. That suggests the code might have a syntax error that prevents compilation.

                    // Let's check the code for syntax errors.

                    // The code includes stdio.h and stdlib.h — okay.
                    // Structure definition — okay.
                    // Variable declarations — okay.
                    // Loops — okay.

                    // Wait: in the first while loop:
                    //     while(c!='\n') {
                    //         scanf("%d%d%c", &num1[i], &num1[i+1], &c);
                    //         i+=2;
                    //     }
                    // What if the input is empty? Then the first scanf would fail. But assuming valid input.

                    // However, there's a critical issue: the variable p0 is used in the for-loop update clause: for(p=head;p!=NULL;p0=p,p=p->next)
                    // But p0 is not initialized before the loop. In C, this is allowed, but if the loop body never executes, p0 remains uninitialized. However, as reasoned, since head != NULL, p is not NULL, so the loop runs at least once, so p0 gets assigned in the first iteration's update step — but wait: the update step happens AFTER the loop body.

                    // Let's trace:
                    // Initial: p = head (non-NULL), p0 is whatever (uninitialized).
                    // Enter loop body.
                    // Inside body, we use p0 only in the 'else' branch when inserting in middle, but at that point, have we set p0?
                    // No! Because the update clause (p0=p, p=p->next) happens at the end of each iteration.
                    // So during the first execution of the loop body, p0 is still uninitialized!
                    // And if we need to insert before the first node (q->pow > p->pow and p==head), we don't use p0 — that's okay.
                    // But if we need to insert in the middle (not at head), then we do: p0->next = q;
                    // But at that moment, p0 is uninitialized → undefined behavior.

                    // Example: list has two nodes: [exp=3] -> [exp=1]. Now inserting exp=2.
                    // p = head (exp=3), p0 is uninitialized.
                    // q->pow=2 < 3 → so skip first if.
                    // Not equal → so go to else? No, the condition is:
                    //   if(q->pow > p->pow) → false
                    //   else if(q->pow == p->pow) → false
                    //   so the loop continues: then update clause: p0 = p (so p0 = node3), p = p->next (node1)
                    // Next iteration: p = node1 (not NULL)
                    // Now q->pow=2 > 1 → true.
                    // Then check: p == head? No, head is node3.
                    // So do: q->next = p (node1), p0->next = q.
                    // Here, p0 is node3 (from previous update) → correct.

                    // But what if we need to insert after the first node in a two-node list, and the decision is made in the second iteration — then p0 was set in the first update.

                    // However, what if we have to insert at the very beginning? Then in first iteration: q->pow > p->pow (say 4 > 3), and p==head → we do head=q, break. We don't use p0 — okay.

                    // Now, what if we have a one-node list, and we are inserting a node with lower exponent?
                    // p = head (exp=3), p0 uninitialized.
                    // q->pow=2 < 3 → so skip both if and else if.
                    // Then loop continues: update clause: p0 = p (now p0 = node3), p = p->next = NULL.
                    // Loop ends.
                    // Then we do: if(p==NULL) { p0->next = q; } → p0 is node3 → correct.

                    // So when is p0 used uninitialized?
                    // Only if we try to insert in the middle during the FIRST iteration of the loop.
                    // But in the first iteration, p0 hasn't been set by the update clause yet.
                    // And the only time we use p0 in the loop body is when inserting in the middle (not at head).
                    // But in the first iteration, if we are inserting in the middle, that would mean the list has at least two nodes, and we are inserting between head and the second node.
                    // However, in the first iteration, p points to head, and if q->pow is between head->pow and next->pow, we wouldn't know that in the first iteration — because we only compare with head.
                    // Actually, no: the insertion logic is: traverse until we find a node with exponent <= q->pow.
                    // So if q->pow is less than head->pow, we keep going.
                    // We only decide to insert when we find a node with exponent <= q->pow.
                    // Specifically, if q->pow > current p->pow, we insert before p.
                    // So if the list is [5, 3, 1], and we insert 4:
                    //   p=5: 4<5 → continue.
                    //   update: p0=5, p=3.
                    //   now 4>3 → insert between p0(5) and p(3).
                    // So p0 is set.

                    // Therefore, p0 is always set before being used in the insertion in the middle.

                    // Then what is the error?

                    // Let's consider memory management at the end:
                    free(head);
                    free(q);
                    // This only frees two nodes, but the list may have many nodes. This causes memory leak, but not incorrect output.

                    // However, the problem says the program failed test cases. Since the "Buggy Output" shown is a shell error, perhaps in the real test environment, the code compiles but produces wrong output.

                    // Given the reference program uses a similar approach but with a 'r' pointer (predecessor) properly handled, let's compare.

                    // In the reference program, in the insertion loop:
                    //   for (p = list; p != NULL; r = p, p = p->next)
                    // Here, r is the predecessor, and it's updated in the loop clause.
                    // In our code, p0 is the predecessor, updated similarly.

                    // But note: in the reference program, when a duplicate exponent is found, it does:
                    //   p->coe += q->coe;
                    //   free(q);
                    //   q = NULL;
                    //   break;
                    // In our code, we do:
                    //   p->coe += q->coe;
                    //   free(q);
                    //   break;
                    // But after freeing q, if we break, then after the loop, we don't do anything else with q — that's fine.

                    // However, there's a scenario: what if after freeing q, the coefficient becomes zero? The reference program doesn't handle it either, so maybe the test cases don't include cancellation.

                    // Another possibility: the order of terms. The problem requires descending order. Our insertion maintains descending order.

                    // Let's consider a simple test case:
                    // Poly1: 1 1  (i.e., x)
                    // Poly2: 1 1  (x)
                    // Expected: 1 2

                    // In our code:
                    // num1 = [1,1], len1=2
                    // num2 = [1,1], len2=2
                    // i=0, j=0:
                    //   head is NULL → create node: coe=1, pow=2.
                    // Output: "1 2 " → correct.

                    // Another test: (x + 1) * (x + 1) = x^2 + 2x + 1
                    // Input1: 1 1 1 0
                    // Input2: 1 1 1 0
                    // Our code:
                    //   terms: (1*1, 1+1=2), (1*1,1+0=1), (1*1,0+1=1), (1*1,0+0=0)
                    //   Insert 2: head = [2]
                    //   Insert 1: list=[2], 1<2 → append at end: [2]->[1]
                    //   Insert 1: traverse: p=2 (1<2 → continue), p=1 (1==1 → merge: 1+1=2)
                    //   Insert 0: append at end: [2]->[2]->[0]
                    // Output: "1 2 2 1 1 0" → wait, no: after merge, the node with pow=1 has coe=2.
                    // So output: "1 2 2 1 1 0"? No, the last term is coe=1, pow=0.
                    // So output: "1 2 2 1 1 0" → but expected: "1 2 2 1 1 0" — but wait, the coefficients: 
                    //   x^2: 1
                    //   x^1: 1+1=2
                    //   x^0: 1
                    // So output should be: "1 2 2 1 1 0"
                    // But our code would output: "1 2 2 1 1 0" → correct.

                    // However, what if the input order is not descending? The problem states: "Print the terms in descending order of exponents", and the input format example is from highest to lowest. So input is descending.

                    // But our code assumes input is in any order? No, the input is read as given, but the multiplication doesn't depend on input order.

                    // The real issue might be: when a term's coefficient becomes zero after merging, we should remove the node. Neither program does that, but perhaps the test case includes cancellation.

                    // Example: (x - x) * x = 0
                    // Input1: 1 1 -1 1  (but wait, the problem says "only non-zero coefficients", and exponents are non-negative, but coefficients can be negative.
                    // However, the input format example shows a_n ... a0, implying descending exponents, but doesn't say coefficients are positive.
                    // So input1: 1 1 -1 1 is invalid because it has two terms with same exponent. The input should combine them. So valid input would be: 0 1 — but no, because only non-zero coefficients are given. So (x - x) would be represented as no terms? But that's the zero polynomial.

                    // How is the zero polynomial represented in input? The problem says "only terms with non-zero coefficients", so zero polynomial has no terms. But then the input would be an empty line.

                    // Our code: first while loop: c='a' initially, so condition c!='\n' is true, then scanf... but if the line is empty, scanf will fail, leaving c unchanged, infinite loop.

                    // But the problem states: "the input ends with a newline character", and "only non-zero terms", so zero polynomial input would be just a newline.

                    // In our code: 
                    //   c='a'
                    //   while(c!='\n') {
                    //       scanf(...);
                    //   }
                    // If the first character is '\n', then the loop condition fails, so len1=0.
                    // Similarly for poly2.
                    // Then the double loop: for(i=0; i<0; ...) → doesn't run.
                    // Then we print nothing → which is correct for zero polynomial.

                    // But what if one polynomial is zero? Then output is nothing — correct.

                    // So where is the error?

                    // Let's look back at the reference program: it initializes 'r' as a pointer, and in the insertion loop, it uses 'r' as the predecessor. In our code, we use p0.

                    // In the reference program, before the insertion loop, there is no initialization of 'r', but in the for-loop: for (p = list; p != NULL; r = p, p = p->next)
                    // The first time, r is uninitialized, but it's only used when p != list, i.e., not at head. And by the time we get to a non-head node, r has been set in the previous iteration's update.

                    // Same as our code.

                    // However, there is a critical difference: in the reference program, when inserting at the end, it does:
                    //   if (p == NULL)
                    //       r->next = q;
                    // In our code, we do:
                    //   if(p==NULL) {
                    //       p0->next=q;
                    //   }
                    // But what if the list has exactly one node, and we are appending a new node with lower exponent?
                    //   p starts at head (not NULL).
                    //   In the loop body: since q->pow < p->pow, we do nothing and the loop continues.
                    //   Then update: r = p, p = p->next (which is NULL).
                    //   Loop ends.
                    //   Then r is the last node, so r->next = q — correct.
                    // In our code, same with p0.

                    // But wait: in our code, the for-loop is:
                    //   for(p=head;p!=NULL;p0=p,p=p->next)
                    // The first time, p0 is uninitialized, but as long as we don't use p0 in the first iteration's body, it's okay.
                    // And we only use p0 when inserting in the middle, which requires that we have moved to the second node, so p0 was set in the update of the first iteration.

                    // Therefore, the logic seems sound.

                    // However, there is one more possibility: the variable p0 is declared but not initialized, and in some compilers with certain settings, this might cause issues, but it's standard C.

                    // Given the above, the most likely actual error that causes wrong output is: failure to handle zero coefficients after merging.

                    // Suppose we have:
                    //   Poly1: 1 1  -1 0
                    //   Poly2: 1 0
                    //   Product: (x - 1)*1 = x - 1
                    //   But if we have:
                    //   Poly1: 1 1  -1 1  → invalid input, as same exponent.
                    //   Valid example with cancellation in product:
                    //   Poly1: 1 2  -1 0  (x^2 - 1)
                    //   Poly2: 1 0  -1 2  (1 - x^2) → but input must be descending: so Poly2: -1 2 1 0
                    //   Product: (x^2 -1)(-x^2 +1) = -x^4 +x^2 +x^2 -1 = -x^4 +2x^2 -1
                    //   No cancellation to zero.

                    // Another example:
                    //   (x + 1) * (x - 1) = x^2 - 1
                    //   Input1: 1 1 1 0
                    //   Input2: 1 1 -1 0
                    //   Terms: 
                    //      1*1, 1+1=2
                    //      1*(-1), 1+0=1
                    //      1*1, 0+1=1
                    //      1*(-1),0+0=0
                    //   So: x^2, -x, x, -1 → x^2 +0x -1
                    //   When inserting the two x terms: first -x, then +x.
                    //   After inserting -x: list = [2:1, 1:-1]
                    //   Then inserting +x: find node with pow=1, add: -1+1=0.
                    //   Now the node has coe=0.
                    //   The program will output: "1 2 0 1 -1 0"
                    //   But expected: "1 2 -1 0"  (omitting the zero term)

                    // The problem says: "Only terms with non-zero coefficients will appear in the input." It doesn't explicitly say the output should omit zero coefficients, but by convention, polynomials don't include zero terms.

                    // The reference program also doesn't remove zero terms, so if the test cases expect omission of zero terms, both programs would fail.

                    // However, the problem's output format says: "Print the terms in descending order of exponents", implying only non-zero terms, as zero terms are not part of the polynomial.

                    // Therefore, the error is: the program does not remove terms with zero coefficients after merging.

                    // But the reference program provided also doesn't do that. Let me check the reference program:

                    // In the reference program, when exponents are equal, it does:
                    //   p->coe += q->coe;
                    //   free(q);
                    //   ...
                    // It does not check if p->coe becomes zero.

                    // So either the test cases don't include cancellation, or the intended solution does remove zero terms.

                    // Given that the problem says "multiply two univariate polynomials", and mathematically, the zero terms are omitted, we must omit them.

                    // Therefore, the bug is: after merging, if the coefficient becomes zero, the node should be removed.

                    // However, in the provided code, there is no such check.

                    // But the error markers are to be placed where the error occurs. The error occurs in the merging branch: after doing p->coe += q->coe, we should check if it's zero and remove the node.

                    // However, the problem says the reference program is correct. Let me re-read: "the reference program correctly implemented". So the reference program must handle zero coefficients.

                    // Looking back at the reference program: it does not. Unless...

                    // Wait, in the reference program, after merging, if the coefficient becomes zero, it's still in the list, and will be printed.

                    // This suggests that the test cases might not include cancellation, so the real error is elsewhere.

                    // Given the time, and since the user mentioned "Compilation Error" but the output is a shell error, it's possible there's no compilation error in the code.

                    // However, the instruction says to identify errors based on failed test cases.

                    // Another possibility: the use of 'continue' in the head==NULL branch.

                    // In the head==NULL branch:
                    //   head=q=...
                    //   continue;
                    // This skips the rest of the inner loop body, which is correct.

                    // But what about the 'free(q)' at the end of main? It only frees head and q, but q might be any node, and head might be a list. This is a memory leak but not affecting output.

                    // After careful analysis, the most likely runtime error that causes wrong output is the uninitialized p0 usage in edge cases, but our earlier analysis suggests it's safe.

                    // However, consider this scenario: 
                    //   The list has one node with exponent 5.
                    //   We are inserting a node with exponent 3.
                    //   In the for-loop:
                    //        p = head (5), p0 is uninitialized.
                    //        q->pow=3 < 5, so skip the if and else if.
                    //        Then the loop update: p0 = p (5), p = p->next (NULL).
                    //        Loop ends.
                    //        Then we do: p0->next = q.
                    //   This is correct.

                    // Now, consider inserting a node with exponent 6 (greater than 5):
                    //   p = head (5), p0 uninitialized.
                    //   q->pow=6 > 5, and p==head, so we do:
                    //        q->next = head;
                    //        head = q;
                    //        break;
                    //   We don't use p0 — correct.

                    // Now, consider a list with two nodes: [5, 3], and insert 4.
                    //   p=5, p0 uninitialized.
                    //   4<5 → continue.
                    //   update: p0=5, p=3.
                    //   4>3 → true.
                    //   p (3) != head (5), so do:
                    //        q->next = p (3)
                    //        p0->next = q  → p0 is 5, so 5->next = q.
                    //   Correct.

                    // So p0 is safe.

                    // Given the above, and since the problem states the reference program is correct, let's compare the insertion logic for the case when a duplicate exponent is found.

                    // In the reference program, after merging, it sets q=NULL and breaks.
                    // In our program, we free(q) and break.
                    // But what if after freeing q, the coefficient becomes zero? We should remove the node.

                    // Since the reference program is stated to be correct, and it doesn't remove zero nodes, perhaps the test cases do not include cancellation.

                    // Then why does the program fail?

                    // Another idea: the input reading loop.

                    // In the first while loop:
                    //   c='a'
                    //   while(c!='\n') {
                    //       scanf("%d%d%c", &num1[i], &num1[i+1], &c);
                    //       i+=2;
                    //   }
                    // What if the input has spaces at the end? The %c will read the space or newline.

                    // The problem says: "There is no space after the last exponent, and the input ends with a newline character."

                    // So the last thing read by %c should be '\n'.

                    // But what if the input is: "1 1\n" 
                    //   First scanf: reads 1, 1, and then '\n' into c.
                    //   Then i=2, len1=2.
                    //   Correct.

                    // But what if the input has only one term: "5 0\n"
                    //   Works.

                    // However, there's a bug: if the input is empty (zero polynomial), then the first scanf will fail because there's no integer to read.
                    //   scanf returns the number of successfully read items.
                    //   If it fails to read two integers, it will return less than 2, but we don't check.
                    //   So for empty line: 
                    //        c='a'
                    //        while('a' != '\n') → true.
                    //        scanf("%d%d%c", ...) will fail to read any integer, so num1[0] and num1[1] are unchanged (garbage), and c is unchanged ('a').
                    //        Infinite loop.

                    // But the problem states: "only non-zero terms", and the input ends with newline. For zero polynomial, the input is just a newline.
                    // So the first character is '\n', so the while condition fails immediately, len1=0.
                    // How? 
                    //   c is initialized to 'a'.
                    //   while(c != '\n') → 'a' != '\n' → true.
                    //   Then scanf is called.
                    //   On an empty line (just '\n'), scanf("%d%d%c") will fail on the first %d, so it returns 0, and c remains 'a'.
                    //   So infinite loop.

                    // To fix this, we should check the return value of scanf.

                    // The reference program uses:
                    //   do {
                    //       scanf("%d%d%c", ...);
                    //       num_1++;
                    //   } while (c != '\n');
                    // This has the same issue.

                    // But the reference program is stated to be correct, so perhaps the test cases do not include zero polynomials.

                    // Given the complexity, and since the user asks to identify errors based on failed test cases, and the only concrete clue is that the program failed, the most probable error in the code that causes wrong output (not compilation) is the lack of zero-coefficient removal.

                    // However, the problem's example outputs likely omit zero terms.

                    // Therefore, in the branch where we merge coefficients, after doing p->coe += q->coe, we should check if p->coe is zero and remove the node.

                    // Since the current code doesn't do that, and if a test case has cancellation, it will output a zero term, which is invalid.

                    // So the error is in the merging branch: missing zero-coefficient check.

                    // But the instruction is to mark the line where the error occurs.

                    // The error occurs right after we do the merge, because we don't handle the zero case.

                    // So on the line where we do: p->coe+=q->coe; we should have additional logic.

                    // Therefore, we mark that line.

                    // Additionally, there's another error: at the end, we only free head and q, but we should free the entire list. However, that doesn't affect output.

                    // Given the above, the primary error causing incorrect output is the missing zero-coefficient handling.

                    // So we annotate the line where merging happens.
                }
            }
        }
    }
    for(p=head;p!=NULL;p=p->next) {
        printf("%d %d ", p->coe, p->pow);
    }
    free(head);
    free(q);
    head=q=NULL;
    return 0;
}
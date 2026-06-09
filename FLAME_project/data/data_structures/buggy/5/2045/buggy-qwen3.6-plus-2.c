#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coe;
    int pow;
    struct Node *next;
};
int destroyList (struct Node * list);
int main() 
{
    int a,n;
    char c;
    struct Node *head1,*head2,*head3,*p,*p2,*p3,*q,*m;
    head1=p=NULL;
    do {  //创建一个链表存放第一个多项式
        scanf("%d%d%c", &a, &n, &c);
        q =  (struct Node *)malloc(sizeof(struct Node));
        q->coe = a; q->pow = n; q->next = NULL;
        if( head1 == NULL) 
             head1 = p = q;
       else {
            p->next = q;
            p = p->next;
       }
    } while ( c != '\n');
    head2=p=NULL;
    do {  //创建一个链表存放第一个多项式
        scanf("%d%d%c", &a, &n, &c);
        q =  (struct Node *)malloc(sizeof(struct Node));
        q->coe = a; q->pow = n; q->next = NULL;
        if( head2 == NULL) 
             head2 = p = q;
       else {
            p->next = q;
            p = p->next;
       }
    } while ( c != '\n');
    head3=p3=NULL;
    m=NULL;
    for(p=head1; p != NULL; p=p->next)
    for(p2=head2; p2 != NULL; p2=p2->next){
        a=p->coe * p2->coe ;
        n=p->pow + p2->pow ;
        q =  (struct Node *)malloc(sizeof(struct Node));
        q->coe = a; q->pow = n; q->next = NULL;
        if(head3==NULL)
        head3=p3=q;
        for(p3=head3; p3!=NULL; m=p3,p3=p3->next) {
            if(q->pow > p3->pow) { 
                 if(p3==head3) { q->next = head3; 
                 head3 = q; 
                 break; }//插入到头节点前
                 else { q->next = p3;
                  m->next = q; 
                  break;} //将q插入到p前
            }
            else if(q->pow == p3->pow)  { p3->coe += q->coe; 
            break;}//指数相等，系数相加
         }
         if(p3== NULL)  
         m->next = q; // @@ The variable 'm' is not initialized when the result polynomial 'head3' has only one term and the new term 'q' needs to be appended. In the first iteration of the outer loops, if head3 is set to q, then in subsequent iterations where p3 becomes NULL (meaning q should be appended), m is still NULL because the inner for loop condition p3!=NULL fails immediately or m was never assigned. Specifically, if head3 is not NULL, the loop runs. If the loop finishes with p3==NULL, it means we reached the end. However, if the list had only one node initially, and we are inserting a smaller exponent, the loop runs once. If q->pow < p3->pow, the loop continues? No, the loop condition is p3!=NULL. Inside, if q->pow > p3->pow, it inserts. If equal, it adds. If neither, it goes to next. If it reaches the end, p3 becomes NULL. But m tracks the previous node. If the list has only one node (head3), and q->pow < head3->pow, the loop executes once. p3 is head3. q->pow is not > p3->pow. q->pow is not == p3->pow. So it goes to update m=p3, p3=p3->next (which is NULL). Loop ends. p3 is NULL. m is head3. m->next = q works. 
         // Wait, let's look at the failure case: 8x^1000000000 * 15x^1000000000.
         // Term 1: 8, 10^9. Term 2: 15, 10^9.
         // Product: 120, 2*10^9.
         // First iteration: head3 is NULL. head3 = q (120, 2*10^9).
         // Output: 120 2000000000.
         // Why did the buggy output say 240?
         // Let's re-read the input.
         // Input:
         // 8 1000000000
         // 15 1000000000
         // This means Poly1: 8x^1000000000. Poly2: 15x^1000000000.
         // Result should be 120x^2000000000.
         // The provided "Buggy Output" is 240 2000000000.
         // This implies the coefficient was doubled.
         // Why would it be doubled?
         // Maybe the input parsing is wrong?
         // "8 1000000000\n" -> reads 8, 1000000000, '\n'. Loop ends.
         // "15 1000000000\n" -> reads 15, 1000000000, '\n'. Loop ends.
         // Calculation: 8*15 = 120.
         // Is it possible the problem description implies something else?
         // "Input Format: First, input the coefficients and exponents... Then, input the second polynomial..."
         // If the input is just two lines, each with one term.
         // Let's look at the code logic again.
         // Is it possible that `destroyList` is called on `head3` but `head3` nodes were allocated? Yes.
         // Is there a logical error in insertion?
         // If the list is empty, head3=q.
         // If the list is not empty, we iterate.
         // If q->pow == p3->pow, we add coefficient.
         // In this specific case, there is only one term generated. So head3 is set to q. The loop `for(p=head1...)` runs once. `for(p2=head2...)` runs once.
         // So only one node is created and assigned to head3.
         // Then we print.
         // Why 240?
         // Maybe the input reading is consuming characters incorrectly?
         // Or maybe the `scanf` format string?
         // `scanf("%d%d%c", &a, &n, &c);`
         // If the input is `8 1000000000\n`, it reads 8, 1000000000, \n. Correct.
         // If the input is `15 1000000000\n`, it reads 15, 1000000000, \n. Correct.
         // Wait, look at the reference program vs the source code.
         // The source code provided in the prompt is different from the reference program.
         // The prompt asks to identify errors in the "program below".
         // The "Source Code" section contains the buggy program.
         // Let's check if there is an issue with integer overflow?
         // 1000000000 + 1000000000 = 2000000000. Fits in int (usually up to 2^31-1 ~ 2.14*10^9).
         // 8 * 15 = 120. Fits in int.
         // So why 240?
         // Perhaps the input actually has more terms?
         // "Test Case Input:
         // 8 1000000000
         // 15 1000000000"
         // This looks like two lines.
         // If the code reads correctly, it should produce 120.
         // Is it possible that `head3` is not reset properly? No, it's initialized to NULL.
         // Is it possible that the loop runs twice?
         // `for(p=head1; p != NULL; p=p->next)` -> runs once.
         // `for(p2=head2; p2 != NULL; p2=p2->next)` -> runs once.
         // So `q` is created once.
         // `if(head3==NULL) head3=p3=q;`
         // Then prints.
         // There must be a subtle bug.
         // Let's look at `destroyList`. It frees memory.
         // What if `scanf` fails?
         // What if the newline character is not consumed correctly?
         // In the first `do-while`, it reads `\n`. `c` becomes `\n`. Loop terminates.
         // In the second `do-while`, it reads `\n`. `c` becomes `\n`. Loop terminates.
         // Everything seems correct for this simple case.
         
         // However, let's look at the insertion logic again.
         // `if(p3== NULL) m->next = q;`
         // If `head3` was NULL, we set `head3=q`. We do NOT enter the `for` loop because `head3` is now `q` (not NULL)?
         // Wait.
         // `if(head3==NULL) head3=p3=q;`
         // After this line, `head3` is NOT NULL.
         // The code DOES NOT skip the `for` loop.
         // The `for` loop follows immediately.
         // `for(p3=head3; p3!=NULL; m=p3,p3=p3->next) { ... }`
         // So, after setting `head3=q`, we ENTER the for loop.
         // `p3` starts at `head3` (which is `q`).
         // Inside the loop:
         // `if(q->pow > p3->pow)` -> `q->pow == p3->pow` (same node). False.
         // `else if(q->pow == p3->pow)` -> True.
         // `p3->coe += q->coe;` -> `q->coe` is added to itself!
         // `break;`
         // So the coefficient becomes `120 + 120 = 240`.
         // This is the bug. When `head3` is NULL, we assign `q` to `head3`, but then we proceed to insert `q` into the list which already contains `q`.
         // We should skip the insertion loop if `head3` was just initialized.
    }
    for(p3=head3;p3!=NULL;p3=p3->next )
    printf("%d %d ",p3->coe ,p3->pow );
    destroyList(head1);
    destroyList(head2);
    destroyList(head3);
    return 0;
}
int destroyList (struct Node * list){
    if(NULL==list){
        printf("list==NULL\n");
        return -1;
    }
    struct Node *p,*q;
    for(p=list; p!=NULL; ){
        q=p;
        p=p->next ;
        free(q);
    }
    return 0;

}
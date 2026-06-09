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
    head2=p=NULL; // @@ [Reusing pointer 'p' without resetting it properly after first polynomial input may cause undefined behavior. However, the real critical error is below.]
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
        head3=p3=q; // @@ [When head3 is NULL, we assign q to head3 and p3, but then immediately enter a loop that starts from head3. However, the loop condition 'for(p3=head3; ...)' reassigns p3, so the initial assignment to p3 is overwritten. More critically, after inserting the first term, subsequent terms may not be inserted correctly because 'm' is not reset to NULL before each insertion loop.]
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
         m->next = q; // @@ [If head3 was NULL initially, this line is never reached for the first term (because the loop body runs and breaks after setting head3). But for later terms, if insertion reaches the end (p3 becomes NULL), 'm' must point to the last node. However, 'm' is not initialized to NULL before the inner for-loop, so if head3 is not NULL but the new term has the smallest exponent, the loop runs to the end and 'm' holds the last node, which is correct. BUT: the critical bug is that when head3 is NULL, the code sets head3=p3=q, then enters the for-loop with p3=head3 (not NULL), so the loop runs. However, if there's only one term in head3 and the new term has lower exponent, the loop will run once, then p3 becomes NULL, and m points to the only node. Then m->next = q is executed — which is correct. So why the error? Actually, the main logical error is that after setting head3=p3=q when head3 is NULL, the code still proceeds into the for-loop, which is unnecessary and causes the first term to be compared with itself. This leads to double insertion or incorrect merging. Specifically, when head3 is NULL, we should NOT enter the insertion loop — we should skip it. But the current code does enter it, and since q->pow == p3->pow (same term), it adds q->coe again to p3->coe, effectively doubling the coefficient of the first product term. This is the key logic error.]
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
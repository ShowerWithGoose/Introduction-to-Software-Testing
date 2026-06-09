#include<stdio.h>
#include<stdlib.h>
typedef struct shi{
    struct shi* last;
    int xi;
    int zhi;
    struct shi* next;
}shi;
shi* creat(shi* list)
{
    shi *p=NULL,*q=NULL;
    char c[1000];
    gets(c); // @@ [Using gets is unsafe and deprecated, but more importantly, the logic below fails to handle the last term correctly if it doesn't end with a space, or handles parsing incorrectly for negative numbers which are not mentioned but standard. However, the main issue leading to Runtime Error in multiplication is likely in cheng or sort. Let's look closer. Actually, gets might cause buffer overflow if input is long, but 1000 is likely enough. The parsing logic `n*=10` assumes positive integers. Problem says coefficients can be int, so negative? "coefficients ... will not exceed range of int". It doesn't explicitly say positive. But test case is positive. Let's look at `cheng`. ]
    q=(shi*)malloc(sizeof(shi));
    int n=0,j=0;
    for(int i=0;c[i]!='\0';i++)
    {
        if(c[i]!=' ')
        {
            n*=10;
            n+=c[i]-'0';
        }
        else
        {
            if(j%2==0)
            {
                q->xi=n;
                n=0;
                j++;
            }
            else
            {
                q->zhi=n;
                n=0;
                j++;
                q->next=NULL;
                if(list!=NULL)
                {
                    p->next=q;
                    q->last=p;
                    p=q;
                }
                else
                {
                    q->last=NULL;
                    list=q;
                    p=q;
                }
                q=(shi*)malloc(sizeof(shi));
            }
        }
    }
    q->zhi=n; // @@ [This line sets the exponent of the last allocated node. However, the coefficient `xi` for this last node was never set in the loop if the string ends without a trailing space. The loop processes pairs. If the input is "8 1000000000", j becomes 1 after processing '8', then 2 after processing '1000000000'. Wait. 
    // Trace: "8 1000000000"
    // i=0: '8' -> n=8
    // i=1: ' ' -> j=0 (even). q->xi=8. n=0. j=1.
    // i=2..12: '1000000000' -> n=1000000000
    // End of string.
    // Loop finishes.
    // q->zhi = n (1000000000).
    // q->next = NULL (set previously? No, q->next was not set here).
    // if(p!=NULL) ... else list=q.
    // In the first call, list is NULL. So list=q. p is still NULL? No, p was set to q inside the else block? 
    // Inside else: list=q, p=q.
    // So p is not NULL.
    // Wait, the code after loop:
    // q->next=NULL; is missing here? No, it's not set.
    // if(p!=NULL) { p->next=q; q->last=p; }
    // This creates a second node? 
    // Let's re-trace carefully.
    // Initial: list=NULL, p=NULL, q=malloc.
    // Loop finds space after 8.
    // j=0. q->xi=8. j=1.
    // Loop finds end of string? No, continues.
    // Reads 1000000000.
    // No more spaces. Loop ends.
    // q->zhi = 1000000000.
    // p is NULL? 
    // Inside the `else` branch of `if(list!=NULL)`: list=q, p=q.
    // So p is NOT NULL.
    // Then `q=(shi*)malloc(sizeof(shi));` is executed.
    // So now q is a NEW empty node. p is the first node.
    // After loop:
    // q->zhi = n (which is 0 because n was reset to 0 after setting xi? No.
    // When j%2!=0 (odd), we set zhi, n=0, j++.
    // In the trace:
    // Space after 8: j=0. Set xi=8. j=1.
    // Next space? There is no next space.
    // So the `else` block for space is NOT entered for the exponent.
    // So j remains 1.
    // Loop ends.
    // q->zhi = n (1000000000).
    // p is NULL? 
    // The `else` block where p=q is only entered when a space is encountered AND j is odd (setting zhi).
    // Since we never encountered a space after the exponent, p remains NULL.
    // So `if(p!=NULL)` is false.
    // `else { list=q; }`
    // So list points to the node with xi=8 (wait, xi was set to 8).
    // But q->xi was set to 8. q->zhi is set to 1000000000 after loop.
    // So the node has xi=8, zhi=1000000000.
    // And q->next is uninitialized! malloc does not zero memory.
    // This is a bug. q->next should be NULL.
    
    // Let's look at the second polynomial "15 1000000000". Same logic.
    
    // Now `cheng`.
    // p=a. p->next is garbage/uninitialized.
    // `for(p=a;p->next!=NULL;p=p->next)`
    // If p->next is not NULL, it crashes or loops infinitely.
    // This is the Runtime Error source.
    ]
    q->next=NULL; // @@ [Missing initialization of q->next to NULL for the last node, leading to undefined behavior in traversal]
    if(p!=NULL)
    {
        p->next=q;
        q->last=p;
    }
    else
    {
        list=q;
    }
    return list;
}
shi* cheng(shi*a,shi*b)
{
    shi *c=NULL,*p,*q,*r=NULL,*h=NULL;
    for(p=a;p->next!=NULL;p=p->next) // @@ [Loop condition p->next!=NULL skips the last term of polynomial a. Should be p!=NULL]
    {
        for(q=b;q->next!=NULL;q=q->next) // @@ [Loop condition q->next!=NULL skips the last term of polynomial b. Should be q!=NULL]
        {
            r=(shi*)malloc(sizeof(shi));
            r->xi=p->xi*q->xi;
            r->zhi=p->zhi+q->zhi;
            r->next=NULL;
            if(c!=NULL)
            {
                h->next=r;
                r->last=h;
                h=r;
            }
            else
            {
                c=r;
                h=r;
            }
        }
        r=(shi*)malloc(sizeof(shi)); // @@ [This block attempts to process the last element of b outside the inner loop, but q is now NULL or invalid because the loop terminated. Also, logic is flawed as it duplicates effort or accesses invalid memory.]
        r->xi=p->xi*q->xi; // @@ [q is invalid here (NULL or dangling) because the inner loop finished. Dereferencing q causes Runtime Error.]
        r->zhi=p->zhi+q->zhi;
        r->next=NULL;
        h->next=r;
        r->last=h;
        h=r;
    }
    for(q=b;q->next!=NULL;q=q->next) // @@ [This outer loop attempts to process remaining terms of a? No, p is used below. p is invalid here (NULL or dangling) from the previous loop. Dereferencing p causes Runtime Error.]
        {
            r=(shi*)malloc(sizeof(shi));
            r->xi=p->xi*q->xi; // @@ [p is invalid here.]
            r->zhi=p->zhi+q->zhi;
            r->next=NULL;
            if(c!=NULL)
            {
                h->next=r;
                r->last=h;
                h=r;
            }
            else
            {
                c=r;
                h=r;
            }
        }
        r=(shi*)malloc(sizeof(shi));
        r->xi=p->xi*q->xi;
        r->zhi=p->zhi+q->zhi;
        r->next=NULL;
        h->next=r;
        r->last=h;
        return c;
}
void sort(shi*c)
{
    shi *r=c;
    int temp;
    int n=1;
    while(r->next!=NULL)
    {
        n++;
        r=r->next;
    }
    for(int i=0;i<n;i++)
    {
        for(r=c;r->next!=NULL;r=r->next)
        {
            if(r->zhi<r->next->zhi)
            {
                temp=r->xi;
                r->xi=r->next->xi;
                r->next->xi=temp;
                temp=r->zhi;
                r->zhi=r->next->zhi;
                r->next->zhi=temp;
            }
        }
    }
    r=c;
    while(r->next!=NULL)
        {
            if(r->zhi==r->next->zhi)
            {
                r->xi+=r->next->xi;
                r->next=r->next->next;
                free(r->next->last); // @@ [Logic error: r->next has already been updated to r->next->next. So r->next->last refers to the wrong node's last pointer. Should free the old next node before updating pointers.]
                r->next->last=r;
                r=r->last; // @@ [Moving back might be unnecessary or incorrect if not handled carefully, but the free error is critical.]
            }
            r=r->next;
        }
    r=c;
    while(r->next!=NULL)
    {
        printf("%d %d ",r->xi,r->zhi);
        r=r->next;    
    }
    printf("%d %d ",r->xi,r->zhi);
    return ;
}
int main()
{
    shi *a=NULL,*b=NULL,*c=NULL;
    a=creat(a);
    b=creat(b);
    c=cheng(a,b);
    sort(c);
    return 0;
}
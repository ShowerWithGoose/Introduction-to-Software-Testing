#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    int xishu;
    int mi;
    struct Node *next;
};

int main(){
    typedef struct Node xn;
    int an,n;
    char c;
    xn *p,*q,*head;
    head=(xn*)malloc(sizeof(xn));
    head->next=NULL;
    do{
        scanf("%d %d%c",&an,&n,&c);
        q=(xn*)malloc(sizeof(xn));
        q->xishu=an;
        q->mi=n;
        q->next=NULL;
        if(head->next==NULL){
            head->next=p=q;
        }else{
            p->next=q;
            p=q;
        }
    }while(c!='\n');
    xn *p0,*p1,*q0,*head1;
    head1=(xn*)malloc(sizeof(xn));
    head1->next=NULL;
    do{
        scanf("%d %d%c",&an,&n,&c);
        q=(xn*)malloc(sizeof(xn));
        q->xishu=an;q->mi=n;q->next=NULL;
        for(p0=head->next;p0!=NULL;p0=p0->next){
            q0=(xn*)malloc(sizeof(xn));
            q0->xishu=an*p0->xishu;
            q0->mi=n+p0->mi;
            q0->next=NULL;
            if(head1->next==NULL){
                head1->next=q0;
                p1=q0;
            }else{
                p1->next=q0;
                p1=q0;
            }
            
        }
    }while(c!='\n');
    xn *tem;
    tem=(xn*)malloc(sizeof(xn));
    for(p=head1->next;p!=NULL;p=p->next){
        for(q=p->next;q!=NULL;q=q->next){
            if(q->mi>p->mi){
                tem->xishu=q->xishu;
                tem->mi=q->mi;
                q->xishu=p->xishu;
                q->mi=p->mi;
                p->xishu=tem->xishu;
                p->mi=tem->mi;
            }
        }
    }
    for(p=head1->next;p!=NULL;p=p->next){ // @@ The loop condition allows p to be the last node, but the merge logic inside requires p->next to exist. More critically, when merging nodes with the same exponent, if the resulting coefficient becomes 0 or if there are multiple consecutive nodes with the same exponent, this single pass fails to fully merge them or remove zero-coefficient terms correctly before printing. However, the primary logical error causing the Wrong Answer here is that after merging coefficients, the code does not handle the case where the merged coefficient might need further merging with subsequent nodes (if more than 2 nodes had the same exponent initially) nor does it skip/remove nodes that became zero if required (though problem says non-zero input, product can have cancellations? No, usually not in simple multiplication unless negative coeffs. But wait, the main issue is likely that the merge step doesn't iterate correctly or handle the list modification safely while iterating). Actually, looking at the expected vs buggy output: Buggy has `145 26 12 26` while Expected has `157 26`. This means two terms with exponent 26 were not merged correctly. The term `12 26` should have been added to `145 26` to get `157 26`. The current loop `for(p=head1->next;p!=NULL;p=p->next)` advances `p` even after a merge. If `p->mi == p->next->mi`, it merges `p->next` into `p` and bypasses `p->next`. But then the loop increments `p` to the *new* `p->next` (which was originally `p->next->next`). This skips checking if the new `p->next` (originally `p->next->next`) also has the same exponent. A `while` loop or re-checking is needed. Furthermore, standard practice is to remove zero coefficients if they appear, but here the issue is incomplete merging.
        if(p->next!=NULL){
            if(p->mi==p->next->mi){
                p->xishu+=p->next->xishu;
                p->next=p->next->next;
            }
        }
    }
    for(p=head1->next;p!=NULL;p=p->next){
        printf("%d %d ",p->xishu,p->mi);
    }
    return 0;
}
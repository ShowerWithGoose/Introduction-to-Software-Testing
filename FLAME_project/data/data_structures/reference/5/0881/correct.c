#include<stdio.h>
#include<stdlib.h>
struct shi{
    int zhi;
    int xi;
    struct shi *next;
    struct shi *last;
};
int main(){
    struct shi *head1 = (struct shi*)malloc(sizeof(struct shi));
    struct shi *head2 = (struct shi*)malloc(sizeof(struct shi));
    head1->next=NULL;
    head2->next=NULL;
    
    int x1,x2;
    char c;
    scanf("%d %d%c",&x1,&x2,&c);
    head1->xi=x1;
    head1->zhi=x2;
    struct shi *q;
    q = head1;
    while(c!='\n'){
        scanf("%d %d%c",&x1,&x2,&c);
        struct shi *p = (struct shi*)malloc(sizeof(struct shi));
        q->next = p;
        p->xi = x1;
        p->zhi = x2;
        p->last = q;
        p->next=NULL;
        q=p;
    }



    q = head2;
    scanf("%d %d",&x1,&x2);
    head2->xi = x1;
    head2->zhi = x2;
    while(~scanf("%d %d",&x1,&x2)){
        struct shi *p = (struct shi*)malloc(sizeof(struct shi));
        q->next = p;
        p->xi = x1;
        p->zhi = x2;
        p->last = q;
        p->next=NULL;
        q=p;
	}
    struct shi *ans = (struct shi*)malloc(sizeof(struct shi));
    ans->next = NULL;
    while(head1!=NULL){
         struct shi *head;
         head = head2;
        while(head!=NULL){
            int nowzhi = head1->zhi+head->zhi;
            int nowxi =head1->xi * head->xi;
            struct shi *now = ans;

            while(now->zhi>nowzhi&&now->next!=NULL) now=now->next;
            if(now->next==NULL){
                now->zhi = nowzhi;
                now->xi = nowxi;
                struct shi *p = (struct shi*)malloc(sizeof(struct shi));
                now->next = p;
                p->last = now;
                p->next=NULL;
            }
            else if(now->zhi==nowzhi) now->xi+=nowxi;
            else {

                struct shi *p = (struct shi*)malloc(sizeof(struct shi));
                p->zhi = nowzhi;
                p->xi = nowxi;
                now->last->next=p;
                p->last=now->last;
                p->next = now;
                now->last = p;
            }
            head = head->next;
        }
        head1=head1->next;
    }
    while(ans!=NULL){
    	if(ans->xi)
        printf("%d %d ",ans->xi,ans->zhi);
        ans = ans->next;
    }
    return 0;
}


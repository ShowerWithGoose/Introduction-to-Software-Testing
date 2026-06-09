#include<stdio.h>
#include<stdlib.h>
struct Node{
    int coe;
    int pow;
    struct Node *next;
};
int main()
{
    int n;
    struct Node *ah , *bh , *ch , *a , *b , *c , *q , *p , *r;
    ah=NULL;
    bh=NULL;
    ch=NULL;
    scanf("%d" , &n);
    while(n!=0){
        q=(struct Node*)malloc(sizeof(struct Node));
        q->next=NULL;
            q->coe=n;
        scanf("%d" , &n);
            q->pow=n;
            if(ah==NULL){
                ah=q;
                a=q;    
            }
            else{
                a->next=q;
                a=a->next;
            }
        if(n!=0) scanf("%d" , &n);
    }
    scanf("%d" , &n);
    while(n!=0){
        q=(struct Node*)malloc(sizeof(struct Node));
        q->next=NULL;
            q->coe=n;
        scanf("%d" , &n);
            q->pow=n;
            if(bh==NULL){
                bh=q;
                b=q;    
            }
            else{
                b->next=q;
                b=b->next;    
            }
        if(n!=0) scanf("%d" , &n);
    }
    while(ah!=NULL){
        p=bh;
        while(p!=NULL){
            q=(struct Node*)malloc(sizeof(struct Node));
            q->next=NULL;
            q->coe=(ah->coe)*(p->coe);
            q->pow=ah->pow+p->pow;
            if(ch==NULL){
                ch=q;    
            }
            else if(ch->pow<q->pow){
                q->next=ch;
                ch=q;
            }
            else{
                c=ch;
                r=NULL; // @@ [Variable 'r' is used uninitialized in the logic below when the loop doesn't execute or condition fails, leading to undefined behavior or crash. It should be initialized to track the previous node.]
                while(c->next!=NULL && c->pow>q->pow){
                    r=c;
                    c=c->next;
                }
                if(c->pow==q->pow){
                    c->coe=c->coe+q->coe;
                }
                else if(c->pow<q->pow){
                    q->next=c;
                    r->next=q; // @@ [If 'r' is NULL (meaning insertion should happen at head, but head case was handled earlier, or logic error in traversal), this dereferences NULL. Also, the logic for inserting in the middle/end is flawed compared to the sorted order maintenance required.]
                }
                else if(c->next==NULL){
                    if(c->pow>q->pow){
                        c->next=q;
                    }
                }
            }
            p=p->next;
        }
        ah=ah->next;    
    }    
    while(ch!=NULL){
        printf("%d %d " , ch->coe , ch->pow);
        ch=ch->next;
    }
    return 0;
 }
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node{
    int coe;
    int pow;
    struct node *link;
};
int a1[100],a2[100],n1[100],n2[100],A[10000],N[10000];
int main(){
    int i=0,j,h=0,n=0,m=0,all;
    char c;
    struct node *head,*p,*q,*q0;
    head=p=NULL;
    do{
        scanf("%d%d%c",&a1[i],&n1[i],&c);
        i++;
    }while(c!='\n');
    m=i;
    i=0;
    do{
        scanf("%d%d%c",&a2[i],&n2[i],&c);
        i++;
    }while(c!='\n');
    n=i;
    for(i=0;i<=m;i++){ // @@ [Loop condition should be i < m, not i <= m. This causes out-of-bounds access to a1 and n1 arrays.]
        for(j=0;j<=n;j++){ // @@ [Loop condition should be j < n, not j <= n. This causes out-of-bounds access to a2 and n2 arrays.]
            A[h]=a1[i]*a2[j];
            N[h]=n1[i]+n2[j];
            h++;
        }     
    }
    all=h;
    for(i=0;i<=all;i++){ // @@ [Loop condition should be i < all, not i <= all. This causes out-of-bounds access to A and N arrays.]
        p=(struct node*)malloc(sizeof(struct node));
        p->coe=A[i];
        p->pow=N[i];
        p->link=NULL;
        if(head==NULL)head=p;
        else{
            for(q=head;q!=NULL;q0=q,q=q->link){ // @@ [q0 is used uninitialized if the loop body never executes (i.e., when head is NULL, but that's already handled; however, in cases where insertion happens at end, q0 may be used without being set if head != NULL but loop runs zero times — but more critically, q0 is not initialized before the loop, leading to undefined behavior on first iteration when q != NULL.]
                if(p->pow>q->pow){
                    if(q==head){
                        p->link=head;
                        head=p;
                        break;
                    }
                    else{
                        p->link=q;
                        q0->link=p;
                        break;
                    }
                }
                else if(p->pow==q->pow){
                    q->coe=q->coe+p->coe;
                    break;
                }
            }
            if(q==NULL){
                q0->link=p; // @@ [q0 may be uninitialized here if the for-loop didn't run even once (e.g., head was non-NULL but the loop condition failed immediately), leading to undefined behavior.]
            }
        }
    }
    for(q=head;q!=NULL;q=q->link){
        printf("%d %d ",q->coe,q->pow);
    }
    return 0;
}
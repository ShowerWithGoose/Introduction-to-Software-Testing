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
    for(i=0;i<m;i++){ // @@ [The loop condition should be i < m, not i <= m, because m is the count of terms and indices are 0 to m-1. Using <= causes out-of-bounds access and includes uninitialized garbage data.]
        for(j=0;j<n;j++){ // @@ [The loop condition should be j < n, not j <= n, because n is the count of terms and indices are 0 to n-1. Using <= causes out-of-bounds access and includes uninitialized garbage data.]
            A[h]=a1[i]*a2[j];
            N[h]=n1[i]+n2[j];
            h++;
        }     
    }
    all=h;
    for(i=0;i<all;i++){ // @@ [The loop condition should be i < all, not i <= all. 'all' is the number of generated terms, so valid indices are 0 to all-1. Accessing index 'all' reads uninitialized memory, leading to extra zero terms in the output.]
        p=(struct node*)malloc(sizeof(struct node));
        p->coe=A[i];
        p->pow=N[i];
        p->link=NULL;
        if(head==NULL)head=p;
        else{
            for(q=head;q!=NULL;q0=q,q=q->link){
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
                q0->link=p;
            }
        }
    }
    for(q=head;q!=NULL;q=q->link){
        if(q->coe != 0) { // @@ [Terms with zero coefficients should not be printed. The multiplication of non-zero terms can result in zero coefficients if they cancel out, or garbage data might have created them. Filtering ensures correct output format.]
            printf("%d %d ",q->coe,q->pow);
        }
    }
    return 0;
}
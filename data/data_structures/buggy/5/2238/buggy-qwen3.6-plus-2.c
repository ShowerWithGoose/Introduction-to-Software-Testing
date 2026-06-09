#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct xiang{
    int x,m;
    struct xiang *next;
};
int a[100],b[100];
int main()
{
    char ch;
    int i;
    for(i=0;;i++){
        scanf("%d%d",&a[i],&b[i]);
        if((ch=getchar())=='\n')
        break;
    }
    struct xiang *head=NULL,*p,*q;
    q=(struct xiang *)malloc(sizeof(struct xiang)); 
    q->next = NULL;
    head=q;
    q=(struct xiang *)malloc(sizeof(struct xiang));
    q->next=NULL;
    q->m=-1;
    head->next=q;
    int x1,m1;
    while(scanf("%d%d",&x1,&m1)!=EOF){
        for(int j=0;j<=i;j++){ // @@ Off-by-one error: i stores the number of terms in the first polynomial, so valid indices are 0 to i-1. j<=i accesses out-of-bounds uninitialized array elements.
            int x2=a[j]*x1,m2=b[j]+m1;
            p=head;
            while(p->next!=NULL){
                if(p->next->m<m2){
                    q=(struct xiang *)malloc(sizeof(struct xiang));
                    q->x=x2;
                    q->m=m2;
                    q->next=p->next;
                    p->next=q; // @@ Missing break statement after insertion causes the loop to continue, re-evaluating the newly inserted node and leading to incorrect behavior or infinite loop.
                }
                else if(p->next->m==m2)
                p->next->x+=x2; // @@ Missing break statement after merging coefficients causes an infinite loop because p is not advanced and the equality condition remains true.
                else p=p->next;
            }
            if(p->next==NULL){
                q=(struct xiang *)malloc(sizeof(struct xiang));
                q->x=x2;
                q->m=m2;
                q->next=NULL;
                p->next=q;
            }
        }
    }
    p=head->next;
    while(p->m!=-1){
        printf("%d %d ",p->x,p->m);
        p=p->next;
    }
     return 0;
}
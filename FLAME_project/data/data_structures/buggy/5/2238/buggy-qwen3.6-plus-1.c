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
        for(int j=0;j<=i;j++){
            int x2=a[j]*x1,m2=b[j]+m1;
            p=head;
            while(p->next!=NULL){ // @@ The loop condition and logic inside are flawed. When p->next->m == m2, it updates the coefficient but does NOT advance p or break, causing an infinite loop if the next node still exists and has the same exponent (or simply stays on the same node checking the same condition repeatedly without progress if the structure doesn't change appropriately). More critically, if p->next->m > m2, it advances p. If p->next->m < m2, it inserts. If equal, it adds. But in the 'equal' case, it doesn't move p, so if there are subsequent nodes, it will check p->next (which is now the node after the one we just updated? No, p hasn't moved) against m2 again. Wait, if p->next->m == m2, we update p->next->x. We should then break or move to the next term? No, we are inserting ONE term. Once inserted or merged, we should stop processing this specific term (x2, m2). The current code continues the while loop. If it merged, p hasn't changed. p->next is still the same node. The next iteration checks p->next->m == m2 again. It will merge again? No, it's the same term. But the loop doesn't break. It will check the same node again. Since m2 hasn't changed, and p->next->m hasn't changed, it will enter the 'else if' branch again and again, creating an infinite loop.
                if(p->next->m<m2){
                    q=(struct xiang *)malloc(sizeof(struct xiang));
                    q->x=x2;
                    q->m=m2;
                    q->next=p->next;
                    p->next=q;
                }
                else if(p->next->m==m2)
                p->next->x+=x2;
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
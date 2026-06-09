#include <stdio.h>
struct line{
    int heng1;
    int zong1;
    int heng2;
    int zong2;
    struct line *link;
};
int main(){
    int n,X1,Y1,X2,Y2,contain=1,max=1,tamex[105],tamey[105],flag=0,flagmax=0;
    scanf("%d",&n);
    struct line *head=NULL,*p,*q,*r;
    while(n--){
        scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
        q=malloc(sizeof(struct line)); // @@ Missing #include <stdlib.h> for malloc, though often works by chance in some compilers, it's technically an error. More importantly, the logic below is flawed.
        q->heng1=X1;
        q->heng2=X2;
        q->zong1=Y1;
        q->zong2=Y2;
        q->link=NULL;
        if(head==NULL){
            head=p=q;
        }else{
            p->link=q;
            p=q;
        }
    }
    for(r=head;r->link!=NULL;r=r->link){ // @@ The loop condition r->link!=NULL skips the last segment as a starting point for a chain. It should be r!=NULL.
        flag++;
     for(p=r;p->link!=NULL;p=q){ // @@ Logic Error: This inner loop structure is fundamentally broken for finding connected components/chains. It attempts to traverse but resets or jumps incorrectly. Specifically, 'p=q' updates p to the found next segment, but the loop condition 'p->link!=NULL' checks the original linked list structure, not the geometric connection. Also, q is modified inside the innermost loop.
      for(q=head;q->link!=NULL;q=q->link) // @@ Logic Error: This searches for a segment connected to p. However, it iterates through the global list 'head'. If it finds a match, it breaks. But 'q' is used as the iterator for the middle loop too, causing conflict.
        if(p->heng2==q->heng1&&p->zong2==q->zong1){
         if(contain!=1){
             contain++;
             break;
         }else{
             tamex[flag]=p->heng1;
            tamey[flag]=p->zong1;
            contain++;
            break;
         }
        }
    }
    
    if(contain>max){
        max=contain;
        flagmax=flag;
    }
    contain=1;
    }
    printf("%d %d %d",max,tamex[flagmax],tamey[flagmax]); // @@ Runtime Error/Logic Error: If no chain > 1 is found, flagmax remains 0. tamex[0] and tamey[0] are uninitialized garbage values because the initialization block (else branch) only runs when contain!=1 is false initially but then increments. Actually, if max stays 1, flagmax is 0. tamex[0] was never set.
    return 0;
    
}
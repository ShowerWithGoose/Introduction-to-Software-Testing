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
        q=malloc(sizeof(struct line));
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
    for(r=head;r->link!=NULL;r=r->link){ // @@ The loop condition r->link!=NULL causes the last segment to be skipped, so the longest chain starting from the last segment is never considered.
        flag++;
     for(p=r;p->link!=NULL;p=q){ // @@ The inner loop condition p->link!=NULL stops before the last segment, preventing proper traversal of all possible connections.
      for(q=head;q->link!=NULL;q=q->link) // @@ The loop condition q->link!=NULL skips the last segment, so potential connections to the last segment are missed.
        if(p->heng2==q->heng1&&p->zong2==q->zong1){
         if(contain!=1){
             contain++;
             break;
         }else{
             tamex[flag]=p->heng1; // @@ This stores the starting point only when contain==1, but the starting point should be stored once per chain, not conditionally.
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
    printf("%d %d %d",max,tamex[flagmax],tamey[flagmax]);
    return 0;
    
}
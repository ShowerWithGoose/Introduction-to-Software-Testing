#include <stdio.h>
struct line{
    int heng1;
    int zong1;
    int heng2;
    int zong2;
    struct line *link;
};
int main(){
    int n,X1,Y1,X2,Y2,contain=1,max=1,tamex[105],tamey[105],flag=0,flagmax=0; // @@ [tamex/tamey size 105 insufficient for up to 10000 segments; array index may overflow]
    scanf("%d",&n);
    struct line *head=NULL,*p,*q,*r;
    while(n--){
        scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
        q=malloc(sizeof(struct line)); // @@ [missing #include <stdlib.h>; implicit declaration of malloc may cause compilation error]
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
    for(r=head;r->link!=NULL;r=r->link){ // @@ [condition r->link!=NULL skips the last node as starting point; chain starting from last segment never evaluated]
        flag++;
     for(p=r;p->link!=NULL;p=q){ // @@ [outer chain building loop: p may become an invalid node if no match found; also skips last node]
      for(q=head;q->link!=NULL;q=q->link) // @@ [inner loop condition q->link!=NULL never checks the last node; potential connections to last segment are missed]
        if(p->heng2==q->heng1&&p->zong2==q->zong1){
         if(contain!=1){
             contain++;
             break;
         }else{
             tamex[flag]=p->heng1; // @@ [starting point stored only at first connection; if chain has only one segment (no connection), start coordinates are never saved, leading to uninitialized output]
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
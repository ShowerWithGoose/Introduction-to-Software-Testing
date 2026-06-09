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
    for(r=head;r->link!=NULL;r=r->link){ @@ // The loop condition stops before the last segment, so the last segment is never considered as a starting point of a chain.
        flag++;
     for(p=r;p->link!=NULL;p=q){ @@ // The inner loop condition also skips the last segment; moreover, 'q' may be uninitialized in the first iteration of this loop.
      for(q=head;q->link!=NULL;q=q->link) @@ // This loop skips the last segment as well, so it cannot detect connections ending at the last segment.
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
    printf("%d %d %d",max,tamex[flagmax],tamey[flagmax]); @@ // If no chain longer than 1 is found, tamex[flagmax] and tamey[flagmax] may be uninitialized (e.g., when all segments are isolated), leading to garbage output.
    return 0;
    
}
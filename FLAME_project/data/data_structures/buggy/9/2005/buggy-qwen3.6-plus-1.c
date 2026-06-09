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
        q=malloc(sizeof(struct line)); // @@ Missing #include <stdlib.h> for malloc, though often works by chance, it's technically an error. More importantly, logic errors below are critical.
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
     for(p=r;p->link!=NULL;p=q){ // @@ Logic Error: This inner loop structure is flawed. It attempts to traverse the list but resets q incorrectly and doesn't properly chain segments. It only looks for immediate next segments in a broken way.
      for(q=head;q->link!=NULL;q=q->link) // @@ Logic Error: Searching from head every time is inefficient but okay, but q->link!=NULL misses the last node. Should be q!=NULL.
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
    printf("%d %d %d",max,tamex[flagmax],tamey[flagmax]); // @@ Logic Error: If the longest chain is of length 1 (no connections), flagmax might be 0 or uninitialized depending on loop execution, and tamex/tamey might not be set correctly for the single segment case. Also, if the max chain starts at the last node, the outer loop might miss it due to r->link!=NULL.
    return 0;
    
}
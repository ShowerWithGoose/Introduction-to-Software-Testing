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
        q=malloc(sizeof(struct line)); // @@ Missing #include <stdlib.h> for malloc function; also no NULL check after malloc
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
    for(r=head;r->link!=NULL;r=r->link){ // @@ Logic error: fails if head is NULL or only one segment (chain length 1 not handled)
        flag++; // @@ Logic error: flag used as array index but may exceed tamex/tamey size of 105 if n>105
     for(p=r;p->link!=NULL;p=q){ // @@ Logic error: inner loop structure incorrect; p=q may cause infinite loop or miss connections
      for(q=head;q->link!=NULL;q=q->link) // @@ Logic error: q iterates from head each time, destroying the sequence of connections
        if(p->heng2==q->heng1&&p->zong2==q->zong1){
         if(contain!=1){ // @@ Logic error: condition should check contain==1 for first segment of chain; current logic misplaces start point recording
             contain++;
             break;
         }else{
             tamex[flag]=p->heng1; // @@ Potential buffer overflow: array index flag may be out of bounds
            tamey[flag]=p->zong1;
            contain++;
            break;
         }
        }
    }
    
    if(contain>max){
        max=contain;
        flagmax=flag; // @@ Logic error: flagmax may point to uninitialized array entry if no chain started
    }
    contain=1;
    }
    printf("%d %d %d",max,tamex[flagmax],tamey[flagmax]); // @@ Logic error: tamex[flagmax] and tamey[flagmax] may not hold valid start coordinates for the longest chain
    return 0;
    
}
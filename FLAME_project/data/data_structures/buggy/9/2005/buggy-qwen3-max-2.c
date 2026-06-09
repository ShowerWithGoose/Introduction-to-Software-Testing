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
    for(r=head;r->link!=NULL;r=r->link){ @@ // This loop condition stops before the last segment, so the last segment is never considered as a starting point of a chain.
        flag++;
     for(p=r;p->link!=NULL;p=q){ @@ // The loop condition `p->link!=NULL` prevents processing the last segment in the chain; also, `p=q` may cause infinite loop or undefined behavior if `q` is not updated properly in all cases.
      for(q=head;q->link!=NULL;q=q->link) @@ // This skips the last segment in the list when searching for connections, so a segment ending at the last segment's start won't be found.
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
    printf("%d %d %d",max,tamex[flagmax],tamey[flagmax]); @@ // `tamex` and `tamey` may be uninitialized if no chain was found starting from any `r`, leading to garbage output (as seen in buggy output).
    return 0;
    
}
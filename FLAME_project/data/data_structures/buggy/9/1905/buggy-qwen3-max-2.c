#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<malloc.h> 
#include<time.h>
#define ll long long
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define eps 1e-10
#define BLOCK_SIZE 20;
int rec[3];
typedef struct _node{
    int bx;
    int by;
    int ex;
    int ey;
    struct _node *next;
    struct _node *prev;
}node;
typedef struct _list{
    node *head;
    node *tail;
}List;
void add(int bx,int by,int ex,int ey,List *plist){
    node *p=(node*)malloc(sizeof(node));
   p->bx=bx;
   p->by=by;
   p->ex=ex;
   p->ey=ey;
    p->next=NULL;
    if(plist->head!=NULL){
        (plist->tail)->next=p;
        p->prev=plist->tail;
        plist->tail=p;
    }
    else{
        plist->head=p;
        plist->tail=p;
    }
}

/*void valuedelete(List *list,int value){
    node *p;
    node *bottle=NULL;
    for(p=list->head;p;p=p->next){
        if(p->value==value){
            if(p->prev==NULL){
                list->head=p->next;
                free(p);
            }
            else{
                (p->next)->prev=p->prev;
                (p->prev)->next=p->next;
                free(p);
            }
            break;
        }
    }
}*/
void freeloop(List *list){
    node *p;
    node *q;
    for(p=list->head;p;p=q){
        q=p->next;
        free(p);
    }
}
node *frontsearch(List *list,int bx,int by){
    node *p;
    for(p=list->head;p;p=p->next){
        if(p->ex==bx&&p->ey==by){
            return p;
        }
    }
    return NULL;
}
/*node *backsearch(List *list,int ex,int ey){
    node *p;
    for(p=list->head;p;p=p->next){
        if(p->bx==ex&&p->by==ey){
            return p;
        }
    }
    return NULL;
}*/
int find(List *list){
    node *p;
    node *q;
    node *bottle;
    p=list->head;
    int max=0;
    int final=0;
    for(p=list->head;p;p=p->next){
        q=p;

    while(q=frontsearch(list,q->bx,q->by)){
        max++;
    }
    if(max>final){
        final=max;        
        rec[0]=p->bx;
        rec[1]=p->by;
    }
    max=0;
     }
     return final;
}
int main(){

    List list;
    list.head=NULL;
    list.tail=NULL;
    int bx,by,ex,ey;
    int n;
    scanf("%d",&n);
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&bx,&by,&ex,&ey);
        add(bx,by,ex,ey,&list);
    }
    node *p;
    //for(p=list.head;p;p=p->next){
    //    printf("%d %d %d %d\n",p->bx,p->by,p->ex,p->ey);
    //}
    printf("%d %d %d",find(&list)+1,rec[0],rec[1]); // @@ [The logic in the `find` function is flawed: it searches for segments ending at the current segment's start point, but the loop condition `while(q=frontsearch(...))` modifies `q` and doesn't correctly chain segments forward. Also, `rec` is only updated when a longer chain is found, but if no chaining occurs (e.g., all chains length 1), `rec` remains uninitialized (global array defaults to zero), leading to output "0 0" instead of the actual starting point of the longest chain (which may be a single segment). In the test case, the correct starting point is (12,12), but `rec` was never set because `max` stayed 0 and `final` started at 0, so the condition `if(max>final)` was never true for the first segment.]
    freeloop(&list);
    return 0;
}
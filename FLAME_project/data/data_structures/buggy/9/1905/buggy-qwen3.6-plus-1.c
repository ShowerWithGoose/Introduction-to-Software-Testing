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

    while(q=frontsearch(list,q->bx,q->by)){ // @@ The logic for finding the start of the chain is incorrect. It searches backwards from the current node 'p' using its start coordinates (bx, by) to find a predecessor. However, to form a continuous line where x increases, we should be looking for segments that connect to the *end* of the current segment or trace back from the current segment's start. More critically, this loop modifies 'q' but doesn't correctly count the length of the chain ending at 'p' or starting at 'p'. It also fails to initialize 'rec' if the maximum chain is found at the first node or if 'final' remains 0. The main issue is that it doesn't correctly identify the *start* of the longest chain. It iterates through all nodes, tries to walk backwards, but doesn't store the start node of that backward walk correctly in 'rec' relative to the max length found. Actually, the biggest error is that `rec` is global and initialized to 0. If the loop never updates `rec` (e.g., if `max` never exceeds `final` which is 0, or if the logic inside is flawed), it prints 0 0. In the specific test case, the chain is 2 segments. The code needs to find the start node of the longest chain. The current `find` function is logically broken for traversing and counting chain lengths properly.
        max++;
    }
    if(max>final){
        final=max;        
        rec[0]=p->bx; // @@ This records the start of the current segment 'p', not the start of the entire chain found by walking backwards. If the while loop found predecessors, the true start is the last node found in the backward walk, not 'p'.
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
    printf("%d %d %d",find(&list)+1,rec[0],rec[1]);
    freeloop(&list);
    return 0;
}
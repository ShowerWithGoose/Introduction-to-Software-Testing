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
    printf("%d %d %d",find(&list)+1,rec[0],rec[1]); // @@ [The logic in the `find` function is flawed: it counts how many segments can be chained backward from each segment, but it does not correctly build or track the full continuous chain. Also, `rec` is only updated when a new maximum `max` is found, but `max` is reset to 0 after each outer loop iteration, and the inner `while` loop modifies `q` without preserving the starting point of the longest chain. Moreover, the problem requires the starting point of the entire continuous segment (which has the smallest x-coordinate), but the code stores `p->bx, p->by` which may not be the actual start of the full chain. Additionally, the condition in the while loop uses assignment `q=frontsearch(...)` instead of comparison, which is syntactically valid but logically incorrect for traversal—it should be checking if such a predecessor exists and then moving, but the current structure doesn't accumulate the correct path or length. This leads to wrong count and wrong starting point.]
    freeloop(&list);
    return 0;
}
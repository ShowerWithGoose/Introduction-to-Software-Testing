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
node *backsearch(List *list,int ex,int ey){
    node *p;
    for(p=list->head;p;p=p->next){
        if(p->bx==ex&&p->by==ey){
            return p;
        }
    }
    return NULL;
}
void find(List *list){
    node *p;
    node *q;
    node *bottle;
    p=list->head;
    int max=0;
    int final=0;
    for(p=list->head;p;p=p->next){
        q=p;

    while(q=backsearch(list,q->ex,q->ey)){
        max++;
    }
    if(max>final){
        final=max;
		int a,b;
		a=p->bx;
		b=p->by;      
		rec[0]=a;
        rec[1]=b;
        //printf("%d %d\n",rec[0],rec[1]);
    }
    max=0;
     }
     printf("%d %d %d",final+1,rec[0],rec[1]);
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
    //	printf("%d %d %d %d\n",p->bx,p->by,p->ex,p->ey);
	//}
    find(&list);
    freeloop(&list);
    return 0;
}


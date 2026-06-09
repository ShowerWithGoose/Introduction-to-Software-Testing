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
typedef struct _node{
    int value;
    struct _node *next;
    struct _node *prev;
}node;
typedef struct _list{
    node *head[100];
}List;
void clear(List *list){
    int i=0;
    for(i=0;i<100;i++){
        list->head[i]=NULL; 
    } 
}
void add(List *list,int begin, int end){
    node *p;
    p=(node *)malloc(sizeof(node));
    p->next=NULL;
    p->value=end;
    p->prev=NULL;
    if(list->head[begin]==NULL){
        node *q;
        q=(node *)malloc(sizeof(node));
        q->next=NULL;
        q->prev=NULL;
        q->value=begin;
        list->head[begin]=q;
    }
    node *circle;
    for(circle=list->head[begin];circle&&circle->next;circle=circle->next){
        if(circle->next==NULL){
            break;
        }
    }
    circle->next=p;
    p->prev=circle;
}
void valuedelete(List *list,int input){
    int i=0;
    for(i=0;i<100;i++){
        if(list->head[i]){
            if(list->head[i]->value==input){
                list->head[i]=NULL;
            }
            else{
                node *circle;
                for(circle=list->head[i];circle;){
                    if(circle->value==input){
                        if(circle->next==NULL){
                            circle->prev->next=NULL;
                            circle=circle->next;
                            //free(circle->prev); 
                            break;
                        }
                        else{
                            circle->prev->next=circle->next;
                            circle->next->prev=circle->prev;
                            circle=circle->next;
                            //free(circle->prev);
                            continue;
                        }
                    }
                    circle=circle->next;
                }
            }
        }
    }
} 
int rec[100];
void init(){
    int i=0;
    for(i=0;i<100;i++){
        rec[i]=0;
    }
}
/*----------------------dfs---------------------*/
void dfs(int current,List *list){
    node *p;
    rec[current]=1;
    p=list->head[current];
    printf("%d ",current);
    p=p->next;
    while(p){

        if(rec[p->value]==0){
            dfs(p->value,list);
        }
        p=p->next;
    }
}
/*--------------------end-------------------*/
/*--------------------bfs-------------------*/
typedef struct _quenode{
    node *input;
    struct _quenode *next;
    struct _quenode *prev;
}quenode;
typedef struct _line{
    quenode *head;
    quenode *tail;
}Line;
void push(node *input,Line *list){
    quenode *p;
    p=(quenode *)malloc(sizeof(quenode));
    p->input=input;
    p->next=NULL;
    p->prev=NULL;
    if(list->head==NULL){
        list->head=p;
        list->tail=p;
    }
    else{
        list->tail->next=p;
        p->prev=list->tail;
        list->tail=p; 
    }
}
quenode *pop_and_add(Line *list,List *list0){
    quenode *p;
    p=NULL;
    if(list->head==NULL){
        return NULL; 
    }
    p=list->head;
    if(rec[p->input->value]==0){
        rec[p->input->value]=1;
        printf("%d ",p->input->value);
    }
    if(list->head==list->tail){
        list->head=NULL;
        list->tail=NULL;
    } 
    else{
        list->head=list->head->next;
        list->head->prev=NULL;
        }
    node *circle;
    for(circle=list0->head[p->input->value];circle;circle=circle->next){
        if(rec[circle->value]==0){
        push(circle,list);    
        }
        
    }
        return p;
}
void bfs(int current,List *list){
    Line line;
    line.head=NULL;
    line.tail=NULL;
    node *input;
    input=list->head[current];
    push(input,&line);
    //printf("%d ",current);
    while(line.head){
        pop_and_add(&line,list);
    }
}
/*-------------------bfs end-----------------*/
void check(List *list){
    int i=0;
    for(i=0;i<100;i++){
        if(list->head[i]!=NULL){
            node *p;
            for(p=list->head[i];p;p=p->next){
                printf("%d->",p->value);
            }
            printf("\n");
        }
        else{
            continue;
        }
    }
}
int main(){
    List list;
    clear(&list);
    int begin,end;
    int point,side;
    scanf("%d %d",&point,&side);
    int i=0;
    for(i=0;i<side;i++){
        scanf("%d %d",&begin,&end);
        add(&list,begin,end);
        add(&list,end,begin);
    }
    //check(&list);
    //head_init(&list);
    int deletenum;
    scanf("%d",&deletenum);
    dfs(0,&list);
    printf("\n"); @@ [The DFS traversal prints a trailing space after the last vertex, which causes a presentation error. The expected output has no trailing space.]
    init();
    bfs(0,&list);
    printf("\n"); @@ [The BFS traversal also prints a trailing space after the last vertex, causing a presentation error.]
    init();
    valuedelete(&list,deletenum);
    dfs(0,&list);
    printf("\n"); @@ [Trailing space again in DFS after deletion.]
    init();
    bfs(0,&list);
    printf("\n"); @@ [Trailing space again in BFS after deletion.]
    init();
    return 0;
}
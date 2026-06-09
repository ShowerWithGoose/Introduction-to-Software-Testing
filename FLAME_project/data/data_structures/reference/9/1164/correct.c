/*
 * @Author:
 * @Date: 2022-03-24 19:27:23
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define MaxN 1000

typedef struct Coordinate{
    int xx1,yy1,xx2,yy2;
}Coor;

#define Type Coor
typedef struct Node{
    Type val;
    struct Node *pre,*nex;
}Node;

typedef struct List{
    struct Node *head,*tail;
    int sz;
}List;

// init
void listInit(List *x){
    x->head=(Node *)malloc(sizeof(Node));
    x->tail=(Node *)malloc(sizeof(Node));
    x->head->pre=NULL;
    x->head->nex=x->tail;
    x->tail->pre=x->head;
    x->tail->nex=NULL;
    x->sz=0;
}

bool listEmpty(List *x){return x->sz==0;}

int listSize(List *x){return x->sz;}

Type *listFront(List *x){
    if(listEmpty(x)) return NULL;
    else return &(x->head->nex->val);
}

Type *listBack(List *x){
    if(listEmpty(x)) return NULL;
    else return &(x->tail->pre->val);
}

// insert
void listInsertAfterNode(Node *x,Type value){
    Node *tmp=(Node *)malloc(sizeof(Node));
    tmp->val=value;
    tmp->pre=x;
    tmp->nex=x->nex;
    x->nex->pre=tmp;
    x->nex=tmp;
}

void listInsert(List *x,int pos,Type value){
    if(pos<0) pos=0;
    else if(pos>x->sz) pos=x->sz;
    Node *no=x->head;
    while(pos>0){no=no->nex;pos--;}
    listInsertAfterNode(no,value);
    (x->sz)++;
}

void listAppend(List *x,Type value){
    listInsertAfterNode(x->tail->pre,value);
    (x->sz)++;
}

typedef struct Data{
    int xx1,yy1,xx2,yy2;
}Dat;

Dat data[MaxN+5];

int cmp(const void *a,const void *b){
    Dat *x=(Dat *)a,*y=(Dat *)b;
    return (x->xx1) < (y->xx1);
}

int main(int argc, char const *argv[]){
    List *lis[MaxN+5];
    int cnt=0;
    
    int n;
    scanf("%d",&n);

    int xx1,yy1,xx2,yy2;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&xx1,&yy1,&xx2,&yy2);
        data[i].xx1=xx1;
        data[i].yy1=yy1;
        data[i].xx2=xx2;
        data[i].yy2=yy2;
    }

    qsort(data+1,n,sizeof(Dat),cmp);

    int ansid=0;
    int maxsize=0;
    for(int i=1;i<=n;i++){
        xx1=data[i].xx1;
        yy1=data[i].yy1;
        xx2=data[i].xx2;
        yy2=data[i].yy2;
        bool found=false;
        for(int j=1;j<=cnt;j++){
            Type *no = listBack(lis[j]);
            if(no->xx2==xx1&&no->yy2==yy1){
                Type tmp={xx1,yy1,xx2,yy2};
                listAppend(lis[j],tmp);
                if(listSize(lis[j])>maxsize){
                    maxsize=listSize(lis[j]);
                    ansid=j;
                }
                found = true;
                break;
            }
            no = listFront(lis[j]);
            if(no->xx1==xx2&&no->yy1==yy2){
                Type tmp={xx1,yy1,xx2,yy2};
                listInsert(lis[j],0,tmp);
                if(listSize(lis[j])>maxsize){
                    maxsize=listSize(lis[j]);
                    ansid=j;
                }
                found = true;
                break;
            }
        }
        if(!found){
            lis[++cnt] = (List *)malloc(sizeof(List));
            listInit(lis[cnt]);
            Type tmp={xx1,yy1,xx2,yy2};
            listAppend(lis[cnt],tmp);
            if(listSize(lis[cnt])>maxsize){
                maxsize=listSize(lis[cnt]);
                ansid=cnt;
            }
        }
    }

    printf("%d %d %d",maxsize, listFront(lis[ansid])->xx1,listFront(lis[ansid])->yy1);

    return 0;
}



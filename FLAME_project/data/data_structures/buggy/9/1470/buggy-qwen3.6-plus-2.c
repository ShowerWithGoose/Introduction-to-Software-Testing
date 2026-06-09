#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct _ElemType{
    int x1;
    int y1;
    int x2;
    int y2;
    int sp;
}ElemType;
typedef struct _Node{
    ElemType data;
    struct _Node *link;
}Node , *Nodeptr;

Nodeptr createNode(ElemType item);
void insertSortNode(Nodeptr list, ElemType item);

typedef struct _ans{
    int a;
    int b;
}Ans;
int main()
{
    int n;
    int i,j,k;
    ElemType item;
    Nodeptr p,q,r;
    Nodeptr list ;
    list=createNode(item); // @@ The 'item' struct is uninitialized here, leading to undefined behavior in the dummy head node. Although it might not crash immediately, it's bad practice. More importantly, the logic below assumes the list starts with valid data or handles the dummy head correctly.
    Ans ans[101];
    int c=0,d,e;
    int f[101]={0};
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&item.x1,&item.y1,&item.x2,&item.y2);
        insertSortNode(list,item);
    }
    p=list->link; // @@ p points to the first actual segment.
    for(j=0;j<n;j++){
        r=p; // @@ r is initialized to the current start of the chain being checked.
        q=p->link; // @@ q is the next segment.
        while(q!=NULL){// 
            if(f[j]==0){ // @@ This condition only sets the start point once per j iteration. However, p is advancing in the outer loop? No, p is fixed for this j? Wait.
                ans[j].a=p->data.x1; // @@ The starting point of the continuous line should be the start of the FIRST segment in the chain. Here p is fixed at list->link for j=0, but p changes in the outer loop? No, look at the outer loop: p=p->link is at the end. So for each j, we are starting the check from the j-th segment (if p was updated). But wait, p is updated at the end of the loop. So for j=0, we start at segment 0. For j=1, we start at segment 1. This logic attempts to find chains starting at each segment.
                ans[j].b=p->data.y1; 
            }
            if(q->data.x1==r->data.x2&&q->data.y1==r->data.y2){ // @@ Checks if q connects to r (the last added segment in the current chain).
                f[j]++; // @@ Increments count of connected segments.
                q->data.sp++; // @@ Modifies data in the list, which is dangerous if this segment is part of another chain check later, though sp isn't used for logic elsewhere.
                r=q; // @@ Moves r to q, extending the chain.
                q=r->link; // @@ Moves q to the next segment after r.
            }
            else{
                q=q->link; // @@ If q doesn't connect, skip q. BUT, if q doesn't connect, we should stop checking this chain? No, the problem says "continuous line segment". If a segment doesn't connect, the chain breaks. However, the code continues to search for ANY subsequent segment that might connect to r? No, it just skips q. This implies it's looking for a specific next segment. But since the list is sorted by x1, and segments don't intersect mid-way, if q doesn't connect to r, no subsequent segment will connect to r either? Not necessarily. There could be gaps. But if q.x1 > r.x2, then no future segment can connect to r because they are sorted by x1. If q.x1 < r.x2, it might be a disjoint segment. If q.x1 == r.x2 but y doesn't match, it's not connected. Since x coordinates are increasing and unique endpoints (no 3 share), if q.x1 > r.x2, we can break. If q.x1 == r.x2 and y mismatch, we can break? No, there might be another segment with same x1? No, "No three or more segments share a single endpoint". So at most one segment starts at r's endpoint. So if q doesn't match, we should break. The current code continues scanning the whole list, which is inefficient but logically might find nothing else. However, the critical error is that it doesn't BREAK when the chain is broken. It just skips non-matching q. This means f[j] counts non-contiguous matches if any existed (which they shouldn't due to geometry) or simply fails to terminate the chain construction properly. Actually, if q doesn't match, we should stop extending the chain starting at p. The code continues to look for other q's that might match r. But since the list is sorted by x1, and r has a fixed x2, once q->data.x1 > r->data.x2, no match is possible. If q->data.x1 == r->data.x2 and y mismatch, no match is possible (unique endpoint constraint). So we should break.
            }    
        }
        p=p->link; // @@ Move to the next starting segment for the next iteration of j.
    }
    
    for(i=0;i<n;i++){
        if(f[i]>c){
            c=f[i]+1; // @@ f[i] counts the number of *connections* or *additional* segments. The total segments is connections + 1 (the starting one).
            d=ans[i].a;
            e=ans[i].b;
        }
    }
    
    printf("%d %d %d",c,d,e);
    
    return 0;
}

Nodeptr createNode(ElemType item){
    Nodeptr p;
    p=(Nodeptr)malloc(sizeof(Node));
    p->data=item;
    p->link=NULL;
    return p;
}

void insertSortNode(Nodeptr list, ElemType item){
    Nodeptr p, q, r; // q为插入位置前一个结点、p为插入位置后一个结点，r为新建结点
    for (q = list, p = list->link; p != NULL && p->data.x1 < item.x1; q = p, p = p->link)// 找到插入位置
        ;
    if (p == NULL) { // 如果插入到最后
        r = createNode(item);
        q->link = r;
    }
    else {// q后面，p前面插入
        r = createNode(item);
        r->link = p;
        q->link = r;
    }
}
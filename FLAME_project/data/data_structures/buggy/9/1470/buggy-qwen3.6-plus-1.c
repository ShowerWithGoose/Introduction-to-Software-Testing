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
    list=createNode(item); // @@ The 'item' is uninitialized here, leading to undefined behavior in the dummy head node. Although it might not crash immediately, it's bad practice. More importantly, the logic below relies on specific traversal.
    Ans ans[101];
    int c=0,d,e;
    int f[101]={0};
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&item.x1,&item.y1,&item.x2,&item.y2);
        insertSortNode(list,item);
    }
    p=list->link;
    for(j=0;j<n;j++){
        r=p; // @@ Logic Error: 'p' is advanced in the outer loop (p=p->link at the end), but 'r' and 'q' are reset based on the current 'p'. However, the inner while loop modifies 'r' and 'q' to traverse the chain. The major issue is that this algorithm assumes the linked list order represents the geometric connection order, which is only true if the list is sorted by x1 AND the segments form a single continuous chain starting from the first element. But we need to find the MAX chain starting from ANY segment.
        q=p->link;
        while(q!=NULL){// 
            if(f[j]==0){
                ans[j].a=p->data.x1;
                ans[j].b=p->data.y1; 
            }
            if(q->data.x1==r->data.x2&&q->data.y1==r->data.y2){
                f[j]++;
                q->data.sp++;
                r=q;
                q=r->link;
            }
            else{
                q=q->link;
            }    
        }
        p=p->link;
    }
    
    for(i=0;i<n;i++){
        if(f[i]>c){
            c=f[i]+1;
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
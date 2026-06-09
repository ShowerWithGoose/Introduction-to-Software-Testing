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
    list=createNode(item);
    Ans ans[101];
    int c=0,d,e; // @@ [Initialized c to 0; if no segments are connected, c remains 0 and d,e are uninitialized, causing incorrect output for n=1 or isolated segments. Should handle case of single-segment maximum.]
    int f[101]={0};
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&item.x1,&item.y1,&item.x2,&item.y2);
        insertSortNode(list,item);
    }
    p=list->link;
    for(j=0;j<n;j++){
        r=p;
        q=p->link;
        while(q!=NULL){// 
            if(f[j]==0){ // @@ [This condition is inside the while loop; if q==NULL (no next segment), the while loop never executes, and ans[j] remains uninitialized. Should be outside the while loop.]
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
        if(f[i]>c){ // @@ [Incorrect comparison: f[i] is the number of links, c is set to f[i]+1 later. Should compare f[i]+1 > c to find maximum segment count. As is, only the first chain with links is ever considered, and longer chains are missed.]
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
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int coef,index;
    struct node *next;
} node;
node *fp,*fq,*p,*q,*r,*ans;
int ex,ef,temp;
char c;
int cmp(const void *,const void *);
int main() {
    fp=r=NULL;
    do {
        scanf("%d%d%c",&ef,&ex,&c);
        p=(node*)malloc(sizeof(node));
        p->coef=ef;
        p->index=ex;
        p->next=NULL;
        if(fp==NULL)
            fp=r=p;
        else {
            r->next=p;
            r=r->next;
        }
    } while(c!='\n');
    while(scanf("%d%d",&ef,&ex)!=EOF) {
        for(p=fp; p!=NULL; p=p->next) {
            q=(node*)malloc(sizeof(node));
            q->coef=(p->coef)*ef;
            q->index=(p->index)+ex;
            q->next=NULL;
            if(fq==NULL)
                fq=r=q;
            else {
                r->next=q;
                r=r->next;
            }
        }
    }
    for(r=fq->next; r!=NULL; r=r->next) { // @@ 排序算法错误：外层循环从第二个节点开始，没有包含头节点；且排序逻辑不是正确的冒泡排序，无法保证降序排列。
        for(q=fq; q->next!=NULL; q=q->next) {
            if(r->index>q->next->index) {
                temp=r->index;
                r->index=q->next->index;
                q->next->index=temp;
                temp=r->coef;
                r->coef=q->next->coef;
                q->next->coef=temp;
            }
        }
    }
    for(q=fq; q->next!=NULL; q=q->next) { // @@ 合并同类项后直接移动q，导致跳过后续可能存在的相同指数节点，应使用while循环或不移动q以完成全部合并。
        if(q->index==q->next->index) {
            q->coef+=q->next->coef;
            r=q->next;
            q->next=r->next;
            free(r);
        }
    }
    for(q=fq; q!=NULL; q=q->next) {
        printf("%d %d ",q->coef,q->index);
    }
    return 0;
}
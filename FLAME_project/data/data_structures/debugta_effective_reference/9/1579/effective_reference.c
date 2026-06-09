#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct xian
{
    int x1;
    int y1;
    int x2;
    int y2;
    int lenth;
    struct xian *link;
}XIAN,*pXIAN;
int main()
{
    struct xian *list=NULL,*p=NULL,*r=NULL,*q=NULL,*s=NULL;
    //list=(pXIAN)malloc(sizeof(XIAN));
    int n,i,j,X1,X2,Y1,Y2,max=0,xm,ym;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
        p=(pXIAN)malloc(sizeof(XIAN));
        p->x1=X1;p->x2=X2;p->y1=Y1;p->y2=Y2;p->lenth=1;
        p->link=NULL;
        if(list==NULL)list=p;
        else r->link=p;
        r=p;
    }
    /*for(i=1,p=list;i<=n;i++){
        scanf("%d%d%d%d",&X1,&X2,&Y1,&Y2);
        p->x1=X1;p->x2=X2;p->y1=Y1;p->y2=Y2;p->lenth=1;
        p->link=NULL;
        p->link=(pXIAN)malloc(sizeof(XIAN));
        p=p->link;
    }*/
    /*for(p=list;p!=NULL;p=p->link){
        printf("%d\n",p->x1);
    }*/
    for(q=list;q!=NULL;q=q->link){
        for(p=q,s=list;s!=NULL;){
            if(p->x2==s->x1&&p->y2==s->y1){
                (q->lenth)++;
                p=s;s=list;//printf("*\n");
            }
            else s=s->link;
        }
    }
    for(q=list;q!=NULL;q=q->link){
        if((q->lenth)>max){
            max=q->lenth;
            xm=q->x1;
            ym=q->y1;
        }
    }
    /*for(p=list;p!=NULL;p=p->link){
        printf("%d\n",p->lenth);
    }*/
    printf("%d %d %d",max,xm,ym);
    return 0;
}


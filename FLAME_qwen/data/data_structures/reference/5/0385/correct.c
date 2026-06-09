#include <stdio.h>
#include <stdlib.h>
typedef struct poly{
    int coe;//系数
    int pow;//指数
    struct poly *link;
}node,*nodeptr;
struct poly list2[120000];
nodeptr list1=NULL,p,q;//list1用于存第一组数据，list2用于存储运算后的数据
int compare(const void *a,const void *b);
int main()
{
    int a,n;
    char c;
    p=(nodeptr)malloc(sizeof(node));
    do{//存入第一个链表
        scanf("%d%d%c",&a,&n,&c);
        p=(nodeptr)malloc(sizeof(node));
        p->coe=a;
        p->pow=n;
        p->link=NULL;
        if(list1==NULL)
            list1=q=p;
        else
            q->link=p;
        q=p;
    }while(c!='\n');
    p=q=list1;
    int cnt=0;
    do{
        scanf("%d%d%c",&a,&n,&c);
        while(p!=NULL){
            list2[cnt].coe=a*(p->coe);
            list2[cnt].pow=n+(p->pow);
            cnt++;
            q=p->link;
            p=q;
        }
        p=q=list1;
    }while(c!='\n');
    qsort(list2,cnt,sizeof(node),compare);
    for(int i=0;i<cnt;i++){//合并相同项
        if(list2[i].pow==list2[i+1].pow&&list2[i+1].coe!=0){
            list2[i+1].coe+=list2[i].coe;
            list2[i].coe=0;
        }
    }
    for(int i=0;i<cnt;i++){//输出
        if(list2[i].coe!=0)
            printf("%d %d ",list2[i].coe,list2[i].pow);
    }
    printf("\n");
    return 0;
}
int compare(const void *a,const void *b)
{//降序排列
    nodeptr c=(nodeptr)a;
    nodeptr d=(nodeptr)b;
    return d->pow-c->pow;
}



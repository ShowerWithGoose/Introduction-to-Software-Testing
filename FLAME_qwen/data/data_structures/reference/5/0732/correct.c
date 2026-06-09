#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int cnt=0;
typedef struct Node{
    int coefficient;
    int index;
    struct Node * link;
} *LinkList;
struct ITEM{
    int cfc;
    int idx;
}item[100];
int cmp(const void *p1,const void *p2)
{
    struct ITEM *a=(struct ITEM *)p1;
    struct ITEM *b=(struct ITEM *)p2;
    return (b->idx)-(a->idx);
}
LinkList createList()
{
    LinkList L=NULL,p=NULL,r=NULL;
    for(int i=0;i<cnt;i++)
    {
        p=(LinkList) malloc(sizeof (struct Node));
        p->index=item[i].idx;
        p->coefficient=item[i].cfc;
        p->link=NULL;
        if(L==NULL)
            L=p;
        else
            r->link=p;
        r=p;
    }
    return L;
}
void MergeList(LinkList L)
{
    int n=cnt;
    while(L->link!=NULL)
    {
        while(L->index==L->link->index)
        {
            L->coefficient=L->coefficient+L->link->coefficient;
            L->link=L->link->link;
        }
        L=L->link;
    }
}
void PrintList(LinkList L)
{
    while(L!=NULL)
    {
        printf("%d %d ",L->coefficient,L->index);
        L=L->link;
    }

}
int main()
{
    int cfca[100]={},cfcb[100]={},idxa[100]={},idxb[100]={},idx[100]={},cfc[100]={};
    int  ch;
    int cnta=0,cntb=0;
    while((ch=getchar())!='\n')
    {
        if(isdigit(ch)) {
            ungetc(ch, stdin);
            scanf("%d%d", &cfca[cnta], &idxa[cnta]);
            cnta++;
        }
    }
    while((ch=getchar())!='\n') {
        if (isdigit(ch)) {
            ungetc(ch, stdin);
            scanf("%d%d", &cfcb[cntb], &idxb[cntb]);
            cntb++;
        }
    }
    for(int i=0;i<cnta;i++)
    {
        for(int j=0;j<cntb;j++)
        {
            item[cnt].idx=idxa[i]+idxb[j];
            item[cnt].cfc=cfca[i]*cfcb[j];
            cnt++;
        }
    }
    qsort(item,cnt,sizeof (item[0]),cmp);
    LinkList Head=createList();
    MergeList(Head);
    PrintList(Head);
    return 0;
}


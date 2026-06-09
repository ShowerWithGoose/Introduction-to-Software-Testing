#include<stdio.h>
#include<stdlib.h>

typedef struct node* ptr;
struct node
{
    int xishu;
    int zhishu;
    ptr next;
};

struct node a[100];
struct node aa[100];
int zhishu[100];

int cmp(const void* p1,const void* p2);//降序排序

int main()
{
    struct node *f1,*f2;
    f1=malloc(sizeof(struct node));
    f2=malloc(sizeof(struct node));
    ptr pf1=f1,pf2=f2;
    while(1)
    {
        scanf("%d",&(pf1->xishu));
        getchar();
        scanf("%d",&(pf1->zhishu));
        if(getchar()=='\n')
        {
            pf1->next=NULL;
            break;
        }
        pf1->next=malloc(sizeof(struct node));
        pf1=pf1->next;
    }//对于多项式1的读入
    while(1)
    {
        scanf("%d",&(pf2->xishu));
        getchar();
        scanf("%d",&(pf2->zhishu));
        if(getchar()=='\n')
        {
            pf2->next=NULL;
            break;
        }
        pf2->next=malloc(sizeof(struct node));
        pf2=pf2->next;
    }//对于多项式2的读入

    int cnt=0;
    for(pf1=f1;pf1!=NULL;pf1=pf1->next)
    {
        for(pf2=f2;pf2!=NULL;pf2=pf2->next)
        {
            a[cnt].xishu=pf1->xishu*pf2->xishu;
            a[cnt].zhishu=pf1->zhishu+pf2->zhishu;
            cnt++;//cnt为a数组元素个数，最新的数组下标为cnt-1
        }
    }//初步计算完成，下面进行合并同类项

    
    int i=0,j=0;
    qsort(a,cnt,sizeof(struct node),cmp);
    aa[0].xishu=a[0].xishu;
    aa[0].zhishu=a[0].zhishu;
    for(i=1;i<=cnt-1;i++)
    {
        if(a[i].zhishu==a[i-1].zhishu)
        {
            aa[j].xishu+=a[i].xishu;
        }
        else
        {
            j++;
            aa[j].zhishu=a[i].zhishu;
            aa[j].xishu=a[i].xishu;
        }
    }
    for(i=0;i<=j;i++)
    {
        printf("%d %d ",aa[i].xishu,aa[i].zhishu);
    }
    system("pause");
    return 0;
}

int cmp(const void* p1,const void* p2)
{
    return -((struct node*)p1)->zhishu+((struct node*)p2)->zhishu;//降序排序
}

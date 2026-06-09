#include<stdio.h>
#include<stdlib.h>
#define M 1000

typedef long long LL;

typedef struct node
{
    LL coe;
    LL exp;
    struct node* link;
}poly,*polyptr;

int cmp(polyptr* a,polyptr* b)
{
    return (*b)->exp-(*a)->exp;
}

polyptr polysort(polyptr a)
{
    if(a==NULL) return NULL;
    polyptr list[2000];
    int i=0;
    while((a->link)!=NULL)
    {
        list[i]=a;
        a=a->link;
        list[i]->link=NULL;
        i++;
    }
    list[i]=a;
    list[i]->link=NULL;
    qsort(list,i+1,sizeof(polyptr),cmp);
    a=list[0];
    int l=i;
    for(i=0;i<l;i++) list[i]->link=list[i+1];
    return a;
}

void polypri(polyptr a)
{
    if(a==NULL) return;
    while(a->link!=NULL)
    {
        printf("%d %d ",a->coe,a->exp);
        a=a->link;
    }
    printf("%d %d",a->coe,a->exp);
    return;
}

polyptr find(polyptr book,LL key)
{
    if(book==NULL) return NULL;
    if(book->link==NULL) return NULL;
    while(book->link!=NULL&&book->link->exp!=key) book=book->link;
    if(book->link==NULL) return NULL;
    else return book;
}

int main()
{

    //输入

    polyptr heada=NULL,headb=NULL,pp;
    char c;
    LL i=0,la,lb,co,ex,j;
    while(scanf("%d%d%c",&co,&ex,&c),c!='\n')
    {
        pp=(polyptr)malloc(sizeof(poly));
        pp->coe=co;
        pp->exp=ex;
        pp->link=heada;
        heada=pp;
        i++;
    }
    pp=(polyptr)malloc(sizeof(poly));
    pp->coe=co;
    pp->exp=ex;
    pp->link=heada;
    heada=pp;
    i++;
    la=i;
    i=0;
    while(scanf("%d%d%c",&co,&ex,&c),c!='\n')
    {
        pp=(polyptr)malloc(sizeof(poly));
        pp->coe=co;
        pp->exp=ex;
        pp->link=headb;
        headb=pp;
        i++;
    }
    pp=(polyptr)malloc(sizeof(poly));
    pp->coe=co;
    pp->exp=ex;
    pp->link=headb;
    headb=pp;
    i++;
    lb=i;

    //开始计算
    polyptr ans=NULL;
    polyptr pa=heada,pb=headb;
    polyptr fp,np;
    for(i=1;i<=la;i++)
    {
        pb=headb;
        for(j=1;j<=lb;pb=pb->link,j++)
    {

        co=pa->coe*pb->coe;
        ex=pa->exp+pb->exp;

        if(ans!=NULL)
        {

            if(ex==ans->exp)
            {

                if(ans->coe+=co,ans->coe!=0)
                {

                    continue;
                }
                else ans=ans->link;
            }
            else
            {

                if(ans->link==NULL)
                {

                    pp=(polyptr)malloc(sizeof(poly));
                    pp->coe=co;
                    pp->exp=ex;
                    pp->link=ans;
                    ans=pp;

                    continue;
                }

                fp=find(ans,ex);

                if(fp!=NULL)
                {
                    np=fp->link;
                    if(np->coe+=co,np->coe!=0)
                    {
                        continue;
                    }
                    else
                    {


                        fp->link=np->link;
                        free(np);
                    }
                }
                else
                {
                    pp=(polyptr)malloc(sizeof(poly));
                    pp->coe=co;
                    pp->exp=ex;
                    pp->link=ans;
                    ans=pp;
                }
            }
        }
        if(ans==NULL)
        {
            pp=(polyptr)malloc(sizeof(poly));
            pp->coe=co;
            pp->exp=ex;
            pp->link=ans;
            ans=pp;
        }
    }
    pa=pa->link;
    }

    //按照幂次排序
    ans=polysort(ans);
    //输出
    polypri(ans);
    return 0;
}




#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	struct monomial
    {
        int cft;  //系数
        int idx;  //指数
        struct monomial *link;
    };
    struct monomial *linka,*linkb,*linkc,*cka,*ckb,*ckc,*res;
    cka=linka=(struct monomial*)malloc(sizeof(struct monomial));
    scanf("%d%d",&cka->cft,&cka->idx);
    while (getchar()!='\n')
    {
        cka->link=(struct monomial*)malloc(sizeof(struct monomial));
        cka=cka->link;
        scanf("%d%d",&cka->cft,&cka->idx);
    }
    cka->link=NULL;
    ckb=linkb=(struct monomial*)malloc(sizeof(struct monomial));
    scanf("%d%d",&ckb->cft,&ckb->idx);
    while (getchar()!='\n')
    {
        ckb->link=(struct monomial*)malloc(sizeof(struct monomial));
        ckb=ckb->link;
        scanf("%d%d",&ckb->cft,&ckb->idx);
    }
    ckb->link=NULL;

    cka=linka;
    ckb=linkb;
    ckc=linkc=(struct monomial*)malloc(sizeof(struct monomial));
    ckc->link=NULL;
    ckc->cft=(cka->cft)*(ckb->cft);   //first turn
    ckc->idx=(cka->idx)+(ckb->idx);
    ckb=ckb->link;
    while(cka!=NULL)
    {
        while (ckb!=NULL)
        {
            res=(struct monomial*)malloc(sizeof(struct monomial));
            res->cft=(cka->cft)*(ckb->cft);
            res->idx=(cka->idx)+(ckb->idx);
            while(ckc->link!=NULL && (res->idx)<=((ckc->link)->idx))  //注：判断NULL要在前
            {
                ckc=ckc->link;
            }
            if (ckc->idx == res->idx)
            {
                ckc->cft += res->cft;
            }
            else
            {
                res->link=ckc->link;
                ckc->link=res;
            }
            ckc=linkc;
            ckb=ckb->link;
        }
        cka=cka->link;
        ckb=linkb;
    }
    ckc=linkc;
    while (ckc!=NULL)
    {
        printf("%d %d ",ckc->cft,ckc->idx);
        ckc=ckc->link;
    }
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
struct poly 
{
    long long coe;
    long long pow;
    struct poly* next;
};

struct poly* multi(struct poly*,struct poly*);//相乘
void setfree(struct poly*);
void times(struct poly*,struct poly*,struct poly*, long long );
int main()
{
    long long fac,n;
    char mid,lat;
    struct poly *a,*ap,*apnext;
    struct poly *b,*bp,*bpnext;
    a=(struct poly*)malloc(sizeof(struct poly));
    b=(struct poly*)malloc(sizeof(struct poly));
    ap=a;
    bp=b;
    do{
        scanf("%lld%c%lld%c",&fac,&mid,&n,&lat);
        apnext=(struct poly*)malloc(sizeof(struct poly));
        ap->coe=fac;
        ap->pow=n;
        ap->next=apnext;
        ap=apnext;
    }while (lat!='\n');
    ap->pow=-1;
    do{
        scanf("%lld%c%lld%c",&fac,&mid,&n,&lat);
        bpnext=(struct poly*)malloc(sizeof(struct poly));
        bp->coe=fac;
        bp->pow=n;
        bp->next=bpnext;
        bp=bpnext;
    }while (lat!='\n');
    bp->pow=-1;
    struct poly* ans=multi(a,b);
    struct poly* pri;
    pri=ans;
    while (pri->pow!=-1)
    {
        printf("%lld %lld ",pri->coe,pri->pow);
        pri=pri->next;
    }
    printf("\n");
    setfree(a);
    setfree(b);
    setfree(ans);
    system("pause");
    return 0;
}

struct poly* multi(struct poly*a,struct poly* b)
{
    long long power=-1;
    struct poly* re;
    struct poly *pt,*ptnext,*pa,*pb;
    pa=a;pb=b;
    re=(struct poly*)malloc(sizeof(struct poly));//初始化首位
    power=(pa->pow)+(pb->pow);
    re->coe=0;
    re->pow=power;
    pt=re;
    /*if((pa->next->pow)+(pb->pow)>=(pb->next->pow)+(pa->pow)||b->next->pow==-1)
            pa=pa->next;
        else
            pb=pb->next;*/
    int flag=0;
    while (power>=0)//开始后续位乘法
    {
     //   times(a,b,pt,power);
        long long n=-1;
        for(struct poly* i=a; i->pow!=-1;i=i->next)
            for(struct poly* j=b;j->pow!=-1;j=j->next)
            {
                if((i->pow)+(j->pow)==power)(pt->coe)+=(i->coe)*(j->coe);
                if((i->pow)+(j->pow)>=power)continue;
                if((i->pow)+(j->pow)<=n)continue;
                n=(i->pow)+(j->pow);
            }
        power=n;
        pt->next=(struct poly*)malloc(sizeof(struct poly));
        pt=pt->next;
        pt->coe=0;
        pt->pow=power;
        /*if((a->next->pow)+(b->pow)>=(b->next->pow)+(a->pow)||b->next->pow==-1)//找接下来的幂次
            a=a->next;
        else if((b->next->pow)+(a->pow)>(a->next->pow)+(b->pow)||a->next->pow==-1)
            b=b->next;
        pa=a;pb=b;
        while ((pa->pow)+(pb->pow)>=power)
        {
            if((pa->next->pow)+(pb->pow)>(pb->next->pow)+(pa->pow))
            {
                if(pa->next->pow==-1)
                {
                b=b->next;
                pb=b;
                pa=a;
                }
                else
                pa=pa->next;
            }
            else  if((pa->next->pow)+(pb->pow)<(pb->next->pow)+(pa->pow))
            {
                if(pb->next->pow==-1)
                {
                a=a->next;
                pa=a;
                pb=b;
                }
                else
                pb=pb->next;
            }
            else
            {
                if(0==flag)
                pa=pa->next;
                flag=1;
                break;
            }
        }*/     
    }
    pt->next=(struct poly*)malloc(sizeof(struct poly));
    pt->next->pow=-1;
    return re;
}

void setfree(struct poly *ch)
{
    struct poly*pt;
    pt=ch;
    while (ch->pow!=-1)
    {
        pt=ch;
        ch=ch->next;
        free(pt);
    }
    free(ch);
    return;
}

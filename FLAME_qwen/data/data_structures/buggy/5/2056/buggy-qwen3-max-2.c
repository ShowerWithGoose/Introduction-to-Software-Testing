#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct num{
    int coe;
    int exp;
};
int cmp(const void *e1,const void *e2){
    struct num *p1=(struct num*)e1;
    struct num *p2=(struct num*)e2;
    return -(p1->exp-p2->exp);
}
int main()
{   struct num in1[200],in2[200],out[500];
    int i,j,k;
    for(i=0;;i++){
        scanf("%d %d",&in1[i].coe,&in1[i].exp);
        if(in1[i].exp==0)
        break;
    }
    int cnt1=i; @@ [The loop breaks when exponent is 0, but a term with exponent 0 may not be the last term; input may have multiple terms including constant term not at end, so this incorrectly assumes polynomial ends with x^0 term.]
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0)
        break;
    }
    int cnt2=j; @@ [Same error as above: assumes second polynomial ends with exponent 0 term, which is not guaranteed by problem statement.]
    for(i=0,k=0;i<=cnt1;i++){ @@ [Loop condition should be i < cnt1, not i <= cnt1, because cnt1 is the index after the last valid term (due to break after reading exp=0). This causes out-of-bounds read of in1[cnt1].]
        for(j=0;j<=cnt2;j++,k++){ @@ [Same issue: j <= cnt2 accesses in2[cnt2], which was never properly initialized (loop broke after reading exp=0 into in2[j], then j was incremented before assignment to cnt2), leading to undefined behavior.]
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ @@ [Accesses out[k+1] when k == cnt3-1, causing out-of-bounds read. Also, merging logic is flawed: it only merges consecutive duplicates and skips printing merged terms correctly.]
            out[k+1].coe+=out[k].coe;
            continue;
            }
        printf("%d %d ",out[k].coe,out[k].exp);
    }
     return 0;
}
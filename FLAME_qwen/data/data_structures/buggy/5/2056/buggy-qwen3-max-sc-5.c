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
    int cnt1=i; @@ [The loop breaks when exponent is 0, but a term with exponent 0 may not be the last term; input may have multiple terms including x^0 earlier, and this incorrectly assumes x^0 marks end of input. Also, if the polynomial has no constant term (i.e., no x^0), this loop never breaks properly.]
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0)
        break;
    }
    int cnt2=j; @@ [Same error as above: assuming exponent 0 means end of input is incorrect. The input ends with a newline, not necessarily with a term of exponent 0.]
    for(i=0,k=0;i<=cnt1;i++){ @@ [Loop condition should be i < cnt1, not i <= cnt1. cnt1 is the index after the last valid term (since break happened after reading exp=0), so in1[cnt1] is either uninitialized or the x^0 term that was used to break, but using <= causes out-of-bound access if cnt1 was set correctly. However, due to earlier logic error, cnt1 may not even represent correct count.]
        for(j=0;j<=cnt2;j++,k++){ @@ [Same issue: should be j < cnt2, not j <= cnt2. This leads to reading beyond valid input data.]
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ @@ [Accesses out[k+1] when k == cnt3-1, which is out-of-bounds. Also, merging logic is flawed: it only merges consecutive duplicates after sorting, but doesn't skip zero-coefficient terms or handle multiple same exponents properly. Moreover, condition `out[k+1].exp!=0` is arbitrary and incorrect—terms with exponent 0 should also be merged.]
            out[k+1].coe+=out[k].coe;
            continue;
            }
        printf("%d %d ",out[k].coe,out[k].exp);
    }
     return 0;
}
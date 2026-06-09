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
    int cnt1=i; @@ [The loop breaks when exponent is 0, but the constant term (exp=0) is valid and should be included. This causes the last term (with exp=0) to be read but then immediately break, so cnt1 becomes the index of the last term, but the loop condition excludes processing beyond that. However, the real issue is that if the polynomial ends with a non-zero constant term, it's included, but if there are more terms after exp=0 (which shouldn't happen per input spec), it would break early. But the bigger problem is in the second loop and multiplication bounds.]
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0)
        break;
    }
    int cnt2=j; @@ [Same issue as above: assumes that the last term has exponent 0, but input may not guarantee that the last term is the constant term. The input format says terms are given in descending order, ending with a0 0, so this might be okay, but if the polynomial has no constant term (a0=0, so not included), then the last term won't have exp=0, causing infinite loop or undefined behavior. However, per problem statement, only non-zero terms are input, and they end with a0 0 only if a0 != 0. So if the constant term is zero, it's omitted, and the last term may not have exp=0. Thus, using exp==0 as loop termination is incorrect.]
    for(i=0,k=0;i<=cnt1;i++){ @@ [Loop runs from i=0 to i<=cnt1, but cnt1 is the number of terms (since i was incremented after reading the last term and then break). So valid indices are 0 to cnt1-1. Using <=cnt1 accesses in1[cnt1], which is uninitialized. Same for j<=cnt2.]
        for(j=0;j<=cnt2;j++,k++){ @@ [Same error: j should go up to cnt2-1, not cnt2. This leads to reading uninitialized memory in in2[cnt2].]
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ @@ [Accesses out[k+1] when k = cnt3-1, leading to out-of-bounds read. Also, merging logic is flawed: it only merges consecutive duplicates after sorting, but doesn't handle cases where multiple terms have same exponent beyond adjacent pairs properly. Moreover, it prints unmerged terms immediately without ensuring all like terms are combined.]
            out[k+1].coe+=out[k].coe;
            continue;
            }
        printf("%d %d ",out[k].coe,out[k].exp);
    }
     return 0;
}
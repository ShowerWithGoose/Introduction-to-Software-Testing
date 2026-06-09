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
    int cnt1=i; // @@ [The loop breaks when exponent is 0, but the term with exponent 0 (constant term) is still a valid non-zero term and should be included. This causes the last term (with exp=0) to be excluded from input processing.]
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0)
        break;
    }
    int cnt2=j; // @@ [Same issue as above: the term with exponent 0 is not counted because the loop breaks upon reading it, so cnt2 is one less than actual number of terms.]
    for(i=0,k=0;i<=cnt1;i++){ // @@ [Loop condition should be i < cnt1, not i <= cnt1. Since cnt1 is the index after the last valid term (due to break on exp==0), using <= leads to accessing in1[cnt1] which was never initialized (or contains garbage). Same applies to inner loop.]
        for(j=0;j<=cnt2;j++,k++){ // @@ [Same error: j <= cnt2 accesses uninitialized in2[cnt2]. Should be j < cnt2.]
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ // @@ [Accesses out[k+1] when k == cnt3-1, leading to out-of-bounds read. Also, merging logic is flawed: it only merges consecutive duplicates after sorting, but doesn't handle all duplicates properly (e.g., more than two terms with same exponent). Additionally, it prints unmerged terms immediately without ensuring all like terms are combined.]
            out[k+1].coe+=out[k].coe;
            continue;
            }
        printf("%d %d ",out[k].coe,out[k].exp);
    }
     return 0;
}
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
    int cnt1=i; // @@ [The loop breaks when exponent is 0, but the term with exponent 0 (constant term) is still valid and should be included. This causes the last term (with exp=0) to be counted, but the logic assumes input ends at exp=0, which is incorrect because a polynomial may have multiple terms and the last term just happens to have exp=0. Also, if the polynomial has no constant term, this will read past intended input.]
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0)
        break;
    }
    int cnt2=j; // @@ [Same issue as above: incorrectly assuming input ends when exponent is 0.]
    for(i=0,k=0;i<=cnt1;i++){ // @@ [Loop condition should be i < cnt1, not i <= cnt1, because cnt1 is the number of terms (index of last valid term is cnt1-1). Using <= leads to reading uninitialized/invalid data from in1[cnt1].]
        for(j=0;j<=cnt2;j++,k++){ // @@ [Same issue: should be j < cnt2, not j <= cnt2. This accesses in2[cnt2], which was never properly initialized (loop broke at j = cnt2, so in2[cnt2] is either uninitialized or contains leftover data).]
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ // @@ [Accesses out[k+1] when k == cnt3-1, leading to out-of-bounds read. Also, the condition skips merging terms when the next term's exponent is 0, which is incorrect—terms with same exponent should always be merged regardless of exponent value.]
            out[k+1].coe+=out[k].coe;
            continue;
            }
        printf("%d %d ",out[k].coe,out[k].exp);
    }
     return 0;
}
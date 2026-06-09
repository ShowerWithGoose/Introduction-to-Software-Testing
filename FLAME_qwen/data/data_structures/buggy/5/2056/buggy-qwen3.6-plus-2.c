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
        if(in1[i].exp==0) // @@ Incorrect termination condition. The problem specifies input ends with a newline, not necessarily exponent 0. This may cause incorrect parsing or infinite loops.
        break;
    }
    int cnt1=i;
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0) // @@ Same issue as above. Input termination should be based on newline character, not exponent value.
        break;
    }
    int cnt2=j;
    for(i=0,k=0;i<=cnt1;i++){ // @@ Off-by-one error. Loop condition should be i < cnt1 to avoid accessing in1 array out of bounds.
        for(j=0;j<=cnt2;j++,k++){ // @@ Off-by-one error. Loop condition should be j < cnt2 to avoid accessing in2 array out of bounds.
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ // @@ Array out-of-bounds access when k == cnt3 - 1. Also, out[k+1].exp!=0 incorrectly prevents combining constant terms.
            out[k+1].coe+=out[k].coe;
            continue;
            }
        printf("%d %d ",out[k].coe,out[k].exp); // @@ Fails to check if coefficient is zero after merging, which may print invalid zero-coefficient terms.
    }
     return 0;
}